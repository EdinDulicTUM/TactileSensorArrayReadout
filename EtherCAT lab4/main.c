#include <atmel_start.h>
#include <EtherCAT/ethercat_e54.h>
#include <Melexis/MLX90393_microchip.h>
#include <stdio.h>
#include <string.h>
#include <driver_init.h>
#include <math.h>
#include <Melexis/SensorArray.h>
#include <Tactile_Sensor/neural_spikes.h>

//struct for I2C IO
struct io_descriptor *bmx_io;
struct io_descriptor *bmx_io_2;

//Initialize Sensor Array - Basic Configuration and Data Structure - rewrite to one struct for readability later !!!!! - done
struct  sensor_array
{
	//Basic Preparation of Hall Sensors in Array
	struct MLX90393 sensor1;
	struct MLX90393 sensor2;
	struct MLX90393 sensor3;
	struct MLX90393 sensor4;
	struct MLX90393 sensor5;
	struct MLX90393 sensor6;
	struct MLX90393 sensor7;
	struct MLX90393 sensor8;
	struct MLX90393 sensor9;
	
	//Initialize Data Storage for Sensor Values of Sensor Array
	struct sensorRow_Values sensorRow_Values_Left;
	struct sensorRow_Values sensorRow_Values_Middle;
	struct sensorRow_Values sensorRow_Values_Right;
	
	//Create Neuron Pairs based on the Izhekevic Model for every hall sensor
	struct neuron_pair neuron_pair_1_top; 
	struct neuron_pair neuron_pair_1_middle; 
	struct neuron_pair neuron_pair_1_bottom; 
	struct neuron_pair neuron_pair_2_top;
	struct neuron_pair neuron_pair_2_middle;
	struct neuron_pair neuron_pair_2_bottom;
	struct neuron_pair neuron_pair_3_top;
	struct neuron_pair neuron_pair_3_middle;
	struct neuron_pair neuron_pair_3_bottom;
 
	//Initialize Data Storage for calculated Neuron Values of Sensor Array
	struct neuronRow_Values neuronRow_Values_Left;
	struct neuronRow_Values neuronRow_Values_Middle;
	struct neuronRow_Values neuronRow_Values_Right;
	
	uint8_t array_number; 
};
struct sensor_array sensor_array_1;
struct sensor_array sensor_array_2;

//readout variables
bool new_data;
bool triggered;
bool data_readout;
uint16_t wait_time;
uint8_t selected_row; 
uint8_t selected_output_mode;
uint8_t selected_array; // needs to be implemented
uint8_t number_of_arrays;

//Ethercat Configuration

typedef struct  {
	float hall_top_x;
	float hall_top_y;
	float hall_top_z;
	float neuron_top_normal;
	float neuron_top_shear;
	
	float hall_middle_x;
	float hall_middle_y;
	float hall_middle_z;
	float hall_middle_temp;
	float neuron_middle_normal;
	float neuron_middle_shear;
	
	float hall_bottom_x;
	float hall_bottom_y;
	float hall_bottom_z;
	float neuron_bottom_normal;
	float neuron_bottom_shear;
} BLDC_ECAT_OUT;


typedef struct  {
	/*
	uint16_t control_mode;
	uint16_t	 control_set;
	int32_t desired_position		;
	uint32_t Motor_position_offset	;
	float desired_speed			;
	float Joint_max_speed		;
	float desired_torque		;
	float tau_max				;
	float tau_kp				;
	float tau_kd				;
	uint16_t tau_N				;
	uint16_t tau_Gain			;
	float tau_offset			;
	uint32_t tau_filter			;
	float I_desired				;
	float I_max					;
	float i_kp					;
	float i_ki					;
	*/
} BLDC_ECAT_IN;


volatile BLDC_ECAT_OUT*  BLDC_OUT =&ram_buffer[ram_wr_start];
volatile BLDC_ECAT_IN*  BLDC_IN =&ram_buffer[ram_rd_start];


void SensorRowUpdate(struct sensor_array *sensor_array_use, uint8_t row_select, uint8_t output_mode_select) // rewrite to accept struct of any sensor array + update any row in array!!!!!
{
	switch(row_select){
		case 1: ;
			
			update_struct_values(&(sensor_array_use->sensorRow_Values_Left), &(sensor_array_use->sensor7), &(sensor_array_use->sensor4), &(sensor_array_use->sensor1));
			mag_to_force(row_select, &(sensor_array_use->sensorRow_Values_Left));
			neuron_calc_row(&(sensor_array_use->sensorRow_Values_Left), &(sensor_array_use->neuron_pair_1_top), &(sensor_array_use->neuron_pair_1_middle), &(sensor_array_use->neuron_pair_1_bottom));
			update_struct_values_neural(&(sensor_array_use->neuronRow_Values_Left), &(sensor_array_use->neuron_pair_1_top), &(sensor_array_use->neuron_pair_1_middle), &(sensor_array_use->neuron_pair_1_bottom));
			
			BLDC_OUT->hall_top_x = sensor_array_use->sensorRow_Values_Left.b_x_top; //data7,8,9
			BLDC_OUT->hall_top_y = sensor_array_use->sensorRow_Values_Left.b_y_top;
			BLDC_OUT->hall_top_z = sensor_array_use->sensorRow_Values_Left.b_z_top;
				
			BLDC_OUT->hall_middle_x = sensor_array_use->sensorRow_Values_Left.b_x_middle; //data4,5,6
			BLDC_OUT->hall_middle_y = sensor_array_use->sensorRow_Values_Left.b_y_middle;
			BLDC_OUT->hall_middle_z = sensor_array_use->sensorRow_Values_Left.b_z_middle;

				
			BLDC_OUT->hall_bottom_x = sensor_array_use->sensorRow_Values_Left.b_x_bottom; //data1,2,3
			BLDC_OUT->hall_bottom_y = sensor_array_use->sensorRow_Values_Left.b_y_bottom;
			BLDC_OUT->hall_bottom_z = sensor_array_use->sensorRow_Values_Left.b_z_bottom;
	
			
			switch(output_mode_select){
				case 1: ;
					BLDC_OUT->neuron_top_normal = sensor_array_use->sensorRow_Values_Left.force_z_top;
					BLDC_OUT->neuron_top_shear = sensor_array_use->sensorRow_Values_Left.force_r_top;
					
					BLDC_OUT->neuron_middle_normal = sensor_array_use->sensorRow_Values_Left.force_z_middle;
					BLDC_OUT->neuron_middle_shear = sensor_array_use->sensorRow_Values_Left.force_r_middle;
					
					BLDC_OUT->neuron_bottom_normal = sensor_array_use->sensorRow_Values_Left.force_z_bottom;
					BLDC_OUT->neuron_bottom_shear = sensor_array_use->sensorRow_Values_Left.force_r_bottom;
				break;
				
				case 2: ;
				BLDC_OUT->neuron_top_normal = sensor_array_use->neuronRow_Values_Left.neuron_top_normal;
				BLDC_OUT->neuron_top_shear = sensor_array_use->neuronRow_Values_Left.neuron_top_shear;
				
				BLDC_OUT->neuron_middle_normal = sensor_array_use->neuronRow_Values_Left.neuron_middle_normal;
				BLDC_OUT->neuron_middle_shear = sensor_array_use->neuronRow_Values_Left.neuron_middle_shear;
				
				BLDC_OUT->neuron_bottom_normal = sensor_array_use->neuronRow_Values_Left.neuron_bottom_normal;
				BLDC_OUT->neuron_bottom_shear = sensor_array_use->neuronRow_Values_Left.neuron_bottom_shear;
				break;
			}
			
			BLDC_OUT->hall_middle_temp = row_select + ((sensor_array_use->array_number-1)*3); 
			break;
		
		case 2: ;
			update_struct_values(&(sensor_array_use->sensorRow_Values_Middle), &(sensor_array_use->sensor8), &(sensor_array_use->sensor5), &(sensor_array_use->sensor2));
			mag_to_force(row_select, &(sensor_array_use->sensorRow_Values_Middle));
			neuron_calc_row(&(sensor_array_use->sensorRow_Values_Middle), &(sensor_array_use->neuron_pair_2_top), &(sensor_array_use->neuron_pair_2_middle), &(sensor_array_use->neuron_pair_2_bottom));
			update_struct_values_neural(&(sensor_array_use->neuronRow_Values_Middle), &(sensor_array_use->neuron_pair_2_top), &(sensor_array_use->neuron_pair_2_middle), &(sensor_array_use->neuron_pair_2_bottom));
			
			BLDC_OUT->hall_top_x = sensor_array_use->sensorRow_Values_Middle.b_x_top; //data7,8,9
			BLDC_OUT->hall_top_y = sensor_array_use->sensorRow_Values_Middle.b_y_top;
			BLDC_OUT->hall_top_z = sensor_array_use->sensorRow_Values_Middle.b_z_top;
			
			BLDC_OUT->hall_middle_x = sensor_array_use->sensorRow_Values_Middle.b_x_middle; //data4,5,6
			BLDC_OUT->hall_middle_y = sensor_array_use->sensorRow_Values_Middle.b_y_middle;
			BLDC_OUT->hall_middle_z = sensor_array_use->sensorRow_Values_Middle.b_z_middle;

			
			BLDC_OUT->hall_bottom_x = sensor_array_use->sensorRow_Values_Middle.b_x_bottom; //data1,2,3
			BLDC_OUT->hall_bottom_y = sensor_array_use->sensorRow_Values_Middle.b_y_bottom;
			BLDC_OUT->hall_bottom_z = sensor_array_use->sensorRow_Values_Middle.b_z_bottom;
			
			switch(output_mode_select){
				case 1: ;
				BLDC_OUT->neuron_top_normal = sensor_array_use->sensorRow_Values_Middle.force_z_top;
				BLDC_OUT->neuron_top_shear = sensor_array_use->sensorRow_Values_Middle.force_r_top;
				
				BLDC_OUT->neuron_middle_normal = sensor_array_use->sensorRow_Values_Middle.force_z_middle;
				BLDC_OUT->neuron_middle_shear = sensor_array_use->sensorRow_Values_Middle.force_r_middle;
				
				BLDC_OUT->neuron_bottom_normal = sensor_array_use->sensorRow_Values_Middle.force_z_bottom;
				BLDC_OUT->neuron_bottom_shear = sensor_array_use->sensorRow_Values_Middle.force_r_bottom;
				break;
				
				case 2: ;
				BLDC_OUT->neuron_top_normal = sensor_array_use->neuronRow_Values_Middle.neuron_top_normal;
				BLDC_OUT->neuron_top_shear = sensor_array_use->neuronRow_Values_Middle.neuron_top_shear;
			
				BLDC_OUT->neuron_middle_normal = sensor_array_use->neuronRow_Values_Middle.neuron_middle_normal;
				BLDC_OUT->neuron_middle_shear = sensor_array_use->neuronRow_Values_Middle.neuron_middle_shear;
			
				BLDC_OUT->neuron_bottom_normal = sensor_array_use->neuronRow_Values_Middle.neuron_bottom_normal;
				BLDC_OUT->neuron_bottom_shear = sensor_array_use->neuronRow_Values_Middle.neuron_bottom_shear;
				break;
			}
		
			BLDC_OUT->hall_middle_temp = row_select + ((sensor_array_use->array_number-1)*3);
			break;
			
		case 3: ;
			update_struct_values(&(sensor_array_use->sensorRow_Values_Right), &(sensor_array_use->sensor9), &(sensor_array_use->sensor6), &(sensor_array_use->sensor3));
			mag_to_force(row_select, &(sensor_array_use->sensorRow_Values_Right));
			neuron_calc_row(&(sensor_array_use->sensorRow_Values_Right), &(sensor_array_use->neuron_pair_3_top), &(sensor_array_use->neuron_pair_3_middle), &(sensor_array_use->neuron_pair_3_bottom));
			update_struct_values_neural(&(sensor_array_use->neuronRow_Values_Right), &(sensor_array_use->neuron_pair_3_top), &(sensor_array_use->neuron_pair_3_middle), &(sensor_array_use->neuron_pair_3_bottom));
			
			BLDC_OUT->hall_top_x = sensor_array_use->sensorRow_Values_Right.b_x_top; //data7,8,9
			BLDC_OUT->hall_top_y = sensor_array_use->sensorRow_Values_Right.b_y_top;
			BLDC_OUT->hall_top_z = sensor_array_use->sensorRow_Values_Right.b_z_top;
			
			BLDC_OUT->hall_middle_x = sensor_array_use->sensorRow_Values_Right.b_x_middle; //data4,5,6
			BLDC_OUT->hall_middle_y = sensor_array_use->sensorRow_Values_Right.b_y_middle;
			BLDC_OUT->hall_middle_z = sensor_array_use->sensorRow_Values_Right.b_z_middle;

			
			BLDC_OUT->hall_bottom_x = sensor_array_use->sensorRow_Values_Right.b_x_bottom; //data1,2,3
			BLDC_OUT->hall_bottom_y = sensor_array_use->sensorRow_Values_Right.b_y_bottom;
			BLDC_OUT->hall_bottom_z = sensor_array_use->sensorRow_Values_Right.b_z_bottom;
			
			switch(output_mode_select){
				case 1: ;
				BLDC_OUT->neuron_top_normal = sensor_array_use->sensorRow_Values_Right.force_z_top;
				BLDC_OUT->neuron_top_shear = sensor_array_use->sensorRow_Values_Right.force_r_top;
				
				BLDC_OUT->neuron_middle_normal = sensor_array_use->sensorRow_Values_Right.force_z_middle;
				BLDC_OUT->neuron_middle_shear = sensor_array_use->sensorRow_Values_Right.force_r_middle;
				
				BLDC_OUT->neuron_bottom_normal = sensor_array_use->sensorRow_Values_Right.force_z_bottom;
				BLDC_OUT->neuron_bottom_shear = sensor_array_use->sensorRow_Values_Right.force_r_bottom;
				break;
				
				case 2: ;
				BLDC_OUT->neuron_top_normal = sensor_array_use->neuronRow_Values_Right.neuron_top_normal;
				BLDC_OUT->neuron_top_shear = sensor_array_use->neuronRow_Values_Right.neuron_top_shear;
				
				BLDC_OUT->neuron_middle_normal = sensor_array_use->neuronRow_Values_Right.neuron_middle_normal;
				BLDC_OUT->neuron_middle_shear = sensor_array_use->neuronRow_Values_Right.neuron_middle_shear;
				
				BLDC_OUT->neuron_bottom_normal = sensor_array_use->neuronRow_Values_Right.neuron_bottom_normal;
				BLDC_OUT->neuron_bottom_shear = sensor_array_use->neuronRow_Values_Right.neuron_bottom_shear;
				break;
			}

			BLDC_OUT->hall_middle_temp = row_select + ((sensor_array_use->array_number-1)*3); 
			break;
		}
};


int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	configure_ethercat_dma_descriptors();
	
	//Initialize I2C communication
	i2c_m_sync_get_io_descriptor(&I2C_0, &bmx_io);
	i2c_m_sync_enable(&I2C_0);
	
	i2c_m_sync_get_io_descriptor(&I2C_1, &bmx_io_2);
	i2c_m_sync_enable(&I2C_1);
	
	//Reset TRG Pin
	gpio_set_pin_level(TRG,false);

	//Initialize Readout Variables
	new_data = false;
	triggered = false;
	data_readout = false;
	wait_time = convDelayMicro(&(sensor_array_1.sensor9));
	selected_row = 1; //1 = left, 2 = middle, 3 = right
	selected_array = 1; // needs to be implemented
	
	// User Input
	selected_output_mode = 1; //1 = Force, 2 = Neural Spikes
	number_of_arrays = 1; // how many arrays you want to read out at the same time - implementation necessairy!
	
	
	// Initialize Sensor Array
	sensor_array_1.array_number = 1;
	SensorArray_Init(&(sensor_array_1.sensor1),&(sensor_array_1.sensor2),&(sensor_array_1.sensor3),
					 &(sensor_array_1.sensor4),&(sensor_array_1.sensor5),&(sensor_array_1.sensor6),
					 &(sensor_array_1.sensor7),&(sensor_array_1.sensor8),&(sensor_array_1.sensor9),bmx_io);
	neuron_init_array(&(sensor_array_1.neuron_pair_1_top), &(sensor_array_1.neuron_pair_1_middle), &(sensor_array_1.neuron_pair_1_bottom),
					  &(sensor_array_1.neuron_pair_2_top), &(sensor_array_1.neuron_pair_2_middle), &(sensor_array_1.neuron_pair_2_bottom), 
					  &(sensor_array_1.neuron_pair_3_top), &(sensor_array_1.neuron_pair_3_middle), &(sensor_array_1.neuron_pair_3_bottom));
	
	if (number_of_arrays == 2)
	{
		sensor_array_2.array_number = 2;
		SensorArray_Init(&(sensor_array_2.sensor1),&(sensor_array_2.sensor2),&(sensor_array_2.sensor3),
						 &(sensor_array_2.sensor4),&(sensor_array_2.sensor5),&(sensor_array_2.sensor6),
						 &(sensor_array_2.sensor7),&(sensor_array_2.sensor8),&(sensor_array_2.sensor9),bmx_io);
		neuron_init_array(&(sensor_array_2.neuron_pair_1_top), &(sensor_array_2.neuron_pair_1_middle), &(sensor_array_2.neuron_pair_1_bottom),
						  &(sensor_array_2.neuron_pair_2_top), &(sensor_array_2.neuron_pair_2_middle), &(sensor_array_2.neuron_pair_2_bottom),
						  &(sensor_array_2.neuron_pair_3_top), &(sensor_array_2.neuron_pair_3_middle), &(sensor_array_2.neuron_pair_3_bottom));
	}

	// Activate Interrupt
	NVIC_EnableIRQ(TC3_IRQn);
	
	/* Replace with your application code */
	 
	while (1) 
	{
		
		if (triggered == false)	
		{
			triggerSensor(50);
			triggered = true;
			data_readout = false;
		}
		
		if(new_data == true && data_readout == false)
		{	
			//Needs to be rewritten to change between sensor arrays !!!!!!
			if (selected_array == 1)
			{
				triggerReadoutArray(&(sensor_array_1.sensor1),&(sensor_array_1.sensor2),&(sensor_array_1.sensor3),
									&(sensor_array_1.sensor4),&(sensor_array_1.sensor5),&(sensor_array_1.sensor6),
									&(sensor_array_1.sensor7),&(sensor_array_1.sensor8),&(sensor_array_1.sensor9),bmx_io);
			}
			if (selected_array == 2)
			{
				triggerReadoutArray(&(sensor_array_2.sensor1),&(sensor_array_2.sensor2),&(sensor_array_2.sensor3),
									&(sensor_array_2.sensor4),&(sensor_array_2.sensor5),&(sensor_array_2.sensor6),
									&(sensor_array_2.sensor7),&(sensor_array_2.sensor8),&(sensor_array_2.sensor9),bmx_io_2);
			}
		
			new_data = false; 
			data_readout = true;
		}
		
		if(data_readout == true && row_change_possible == true )
		{
			if (selected_array == 1)
			{
				SensorRowUpdate(&sensor_array_1, selected_row, selected_output_mode);
			}
			if (selected_array == 2)
			{
				SensorRowUpdate(&sensor_array_2, selected_row, selected_output_mode);
			}
			selected_row++;	
			row_change_possible == false;
			if (selected_row == 4)
			{
				selected_row = 1 ;
				selected_array++;
				if (selected_array > number_of_arrays)
				 {
					 selected_array = 1;
				 }
			}
		}		
	}
}

void TC3_Handler(void){
	
	if (TC3->COUNT16.INTFLAG.bit.OVF){
		TC3->COUNT16.INTFLAG.bit.OVF =1;
		triggered = false;
	}
	else if (TC3->COUNT16.INTFLAG.bit.MC1){
		TC3->COUNT16.INTFLAG.bit.MC1 =1;
		new_data = true;
	}
};
