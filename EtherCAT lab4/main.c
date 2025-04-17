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

//initialize timertask
//static struct timer_task TIMER_task1;

//initialize sensors
struct MLX90393 sensor1;
struct MLX90393 sensor2;
struct MLX90393 sensor3;
struct MLX90393 sensor4;
struct MLX90393 sensor5;
struct MLX90393 sensor6;
struct MLX90393 sensor7;
struct MLX90393 sensor8;
struct MLX90393 sensor9;

struct sensorRow_Values sensorRow_Values_Left;
struct sensorRow_Values sensorRow_Values_Middle;
struct sensorRow_Values sensorRow_Values_Right;

// 
struct neuron_pair neuron_pair_1_top; 
struct neuron_pair neuron_pair_1_middle; 
struct neuron_pair neuron_pair_1_bottom; 
struct neuron_pair neuron_pair_2_top;
struct neuron_pair neuron_pair_2_middle;
struct neuron_pair neuron_pair_2_bottom;
struct neuron_pair neuron_pair_3_top;
struct neuron_pair neuron_pair_3_middle;
struct neuron_pair neuron_pair_3_bottom;

struct neuronRow_Values neuronRow_Values_Left;
struct neuronRow_Values neuronRow_Values_Middle;
struct neuronRow_Values neuronRow_Values_Right;

//readout variables
bool new_data;
bool triggered;
bool data_readout;
uint16_t wait_time;
uint8_t selected_row; //1,2,3
uint8_t selected_output_mode; //1 Force , 2 Neural Spikes

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

/*
static void TIMER_task1_cb(const struct timer_task *const timer_task)
{
	new_data = true;
	timer_stop(&TIMER_1);
};

void TIMER_init(uint16_t timer_interval)
{
	TIMER_task1.interval = timer_interval;
	TIMER_task1.cb       = TIMER_task1_cb;
	TIMER_task1.mode     = TIMER_TASK_REPEAT;

	timer_add_task(&TIMER_1, &TIMER_task1);
	//timer_start(&TIMER_0);
};
*/

void SensorRowUpdate(uint8_t row_select, uint8_t output_mode_select)
{
	switch(row_select){
		case 1: ;
			
			update_struct_values(&sensorRow_Values_Left, &sensor7, &sensor4, &sensor1);
			mag_to_force(&sensorRow_Values_Left);
			//neuron_calc(&sensorRow_Values_1,&neuron1_normal,&neuron1_shear,&neuron2_normal,&neuron2_shear, &neuron3_normal,&neuron3_shear); for future implementation just a placeholder 
			//update_struct_values_neural(struct neuronRow_Values *neuron_row, struct neuron_pair *neuron_pair_top, struct neuron_pair *neuron_pair_middle, struct neuron_pair *neuron_pair_bottom); Placeholder for future implementation 
			
			BLDC_OUT->hall_top_x = sensorRow_Values_Left.b_x_top; //data7,8,9
			BLDC_OUT->hall_top_y = sensorRow_Values_Left.b_y_top;
			BLDC_OUT->hall_top_z = sensorRow_Values_Left.b_z_top;
				
			BLDC_OUT->hall_middle_x = sensorRow_Values_Left.b_x_middle; //data4,5,6
			BLDC_OUT->hall_middle_y = sensorRow_Values_Left.b_y_middle;
			BLDC_OUT->hall_middle_z = sensorRow_Values_Left.b_z_middle;

				
			BLDC_OUT->hall_bottom_x = sensorRow_Values_Left.b_x_bottom; //data1,2,3
			BLDC_OUT->hall_bottom_y = sensorRow_Values_Left.b_y_bottom;
			BLDC_OUT->hall_bottom_z = sensorRow_Values_Left.b_z_bottom;
				
			/*
			BLDC_OUT->hall_bottom_x = sensor1.data.x; //data1,2,3
			BLDC_OUT->hall_bottom_y = sensor1.data.y;
			BLDC_OUT->hall_bottom_z = sensor1.data.z;
	
			BLDC_OUT->hall_middle_x = sensor4.data.x; //data4,5,6
			BLDC_OUT->hall_middle_y = sensor4.data.y;
			BLDC_OUT->hall_middle_z = sensor4.data.z;
			
			BLDC_OUT->hall_top_x = sensor7.data.x; //data7,8,9
			BLDC_OUT->hall_top_y = sensor7.data.y;
			BLDC_OUT->hall_top_z = sensor7.data.z;
			*/
			
			switch(output_mode_select){
				case 1: ;
					BLDC_OUT->neuron_top_normal = sensorRow_Values_Left.force_z_top;
					BLDC_OUT->neuron_top_shear = sensorRow_Values_Left.force_r_top;
					
					BLDC_OUT->neuron_middle_normal = sensorRow_Values_Left.force_z_middle;
					BLDC_OUT->neuron_middle_shear = sensorRow_Values_Left.force_r_middle;
					
					BLDC_OUT->neuron_bottom_normal = sensorRow_Values_Left.force_z_bottom;
					BLDC_OUT->neuron_bottom_shear = sensorRow_Values_Left.force_r_bottom;
				break;
				
				case 2: ;
				BLDC_OUT->neuron_top_normal = neuronRow_Values_Left.neuron_top_normal;
				BLDC_OUT->neuron_top_shear = neuronRow_Values_Left.neuron_top_shear;
				
				BLDC_OUT->neuron_middle_normal = neuronRow_Values_Left.neuron_middle_normal;
				BLDC_OUT->neuron_middle_shear = neuronRow_Values_Left.neuron_middle_shear;
				
				BLDC_OUT->neuron_bottom_normal = neuronRow_Values_Left.neuron_bottom_normal;
				BLDC_OUT->neuron_bottom_shear = neuronRow_Values_Left.neuron_bottom_shear;
				break;
			}
			
			//mag_to_force(&sensorRow_Values_1, &sensor1, &sensor4, &sensor7);
			//neuron_calc(&sensorRow_Values_1,&neuron1_normal,&neuron1_shear,&neuron2_normal,&neuron2_shear, &neuron3_normal,&neuron3_shear);
			
			BLDC_OUT->hall_middle_temp = 1;
			break;
		
		case 2: ;
			update_struct_values(&sensorRow_Values_Middle, &sensor8, &sensor5, &sensor2);
			mag_to_force(&sensorRow_Values_Middle);
			//neuron_calc(&sensorRow_Values_1,&neuron1_normal,&neuron1_shear,&neuron2_normal,&neuron2_shear, &neuron3_normal,&neuron3_shear); for future implementation just a placeholder
			//update_struct_values_neural(struct neuronRow_Values *neuron_row, struct neuron_pair *neuron_pair_top, struct neuron_pair *neuron_pair_middle, struct neuron_pair *neuron_pair_bottom); Placeholder for future implementation
			
			BLDC_OUT->hall_top_x = sensorRow_Values_Middle.b_x_top; //data7,8,9
			BLDC_OUT->hall_top_y = sensorRow_Values_Middle.b_y_top;
			BLDC_OUT->hall_top_z = sensorRow_Values_Middle.b_z_top;
			
			BLDC_OUT->hall_middle_x = sensorRow_Values_Middle.b_x_middle; //data4,5,6
			BLDC_OUT->hall_middle_y = sensorRow_Values_Middle.b_y_middle;
			BLDC_OUT->hall_middle_z = sensorRow_Values_Middle.b_z_middle;

			
			BLDC_OUT->hall_bottom_x = sensorRow_Values_Middle.b_x_bottom; //data1,2,3
			BLDC_OUT->hall_bottom_y = sensorRow_Values_Middle.b_y_bottom;
			BLDC_OUT->hall_bottom_z = sensorRow_Values_Middle.b_z_bottom;
			
			switch(output_mode_select){
				case 1: ;
				BLDC_OUT->neuron_top_normal = sensorRow_Values_Middle.force_z_top;
				BLDC_OUT->neuron_top_shear = sensorRow_Values_Middle.force_r_top;
				
				BLDC_OUT->neuron_middle_normal = sensorRow_Values_Middle.force_z_middle;
				BLDC_OUT->neuron_middle_shear = sensorRow_Values_Middle.force_r_middle;
				
				BLDC_OUT->neuron_bottom_normal = sensorRow_Values_Middle.force_z_bottom;
				BLDC_OUT->neuron_bottom_shear = sensorRow_Values_Middle.force_r_bottom;
				break;
				
				case 2: ;
				BLDC_OUT->neuron_top_normal = neuronRow_Values_Middle.neuron_top_normal;
				BLDC_OUT->neuron_top_shear = neuronRow_Values_Middle.neuron_top_shear;
			
				BLDC_OUT->neuron_middle_normal = neuronRow_Values_Middle.neuron_middle_normal;
				BLDC_OUT->neuron_middle_shear = neuronRow_Values_Middle.neuron_middle_shear;
			
				BLDC_OUT->neuron_bottom_normal = neuronRow_Values_Middle.neuron_bottom_normal;
				BLDC_OUT->neuron_bottom_shear = neuronRow_Values_Middle.neuron_bottom_shear;
				break;
			}
		
		
		/*
			BLDC_OUT->hall_bottom_x = sensor2.data.x; //data1,2,3
			BLDC_OUT->hall_bottom_y = sensor2.data.y;
			BLDC_OUT->hall_bottom_z = sensor2.data.z;
			
			BLDC_OUT->hall_middle_x = sensor5.data.x; //data4,5,6
			BLDC_OUT->hall_middle_y = sensor5.data.y;
			BLDC_OUT->hall_middle_z = sensor5.data.z;
			
			BLDC_OUT->hall_top_x = sensor8.data.x; //data7,8,9
			BLDC_OUT->hall_top_y = sensor8.data.y;
			BLDC_OUT->hall_top_z = sensor8.data.z;
		*/
			//mag_to_force(&sensorRow_Values_1, &sensor2, &sensor5, &sensor8);
			//neuron_calc(&sensorRow_Values_1,&neuron1_normal,&neuron1_shear,&neuron2_normal,&neuron2_shear, &neuron3_normal,&neuron3_shear);
			
			BLDC_OUT->hall_middle_temp = 2;
			break;
			
		case 3: ;
			update_struct_values(&sensorRow_Values_Right, &sensor9, &sensor6, &sensor3);
			mag_to_force(&sensorRow_Values_Right);
			//neuron_calc(&sensorRow_Values_1,&neuron1_normal,&neuron1_shear,&neuron2_normal,&neuron2_shear, &neuron3_normal,&neuron3_shear); for future implementation just a placeholder
			//update_struct_values_neural(struct neuronRow_Values *neuron_row, struct neuron_pair *neuron_pair_top, struct neuron_pair *neuron_pair_middle, struct neuron_pair *neuron_pair_bottom); Placeholder for future implementation
			
			
			BLDC_OUT->hall_top_x = sensorRow_Values_Right.b_x_top; //data7,8,9
			BLDC_OUT->hall_top_y = sensorRow_Values_Right.b_y_top;
			BLDC_OUT->hall_top_z = sensorRow_Values_Right.b_z_top;
			
			BLDC_OUT->hall_middle_x = sensorRow_Values_Right.b_x_middle; //data4,5,6
			BLDC_OUT->hall_middle_y = sensorRow_Values_Right.b_y_middle;
			BLDC_OUT->hall_middle_z = sensorRow_Values_Right.b_z_middle;

			
			BLDC_OUT->hall_bottom_x = sensorRow_Values_Right.b_x_bottom; //data1,2,3
			BLDC_OUT->hall_bottom_y = sensorRow_Values_Right.b_y_bottom;
			BLDC_OUT->hall_bottom_z = sensorRow_Values_Right.b_z_bottom;
			
			switch(output_mode_select){
				case 1: ;
				BLDC_OUT->neuron_top_normal = sensorRow_Values_Right.force_z_top;
				BLDC_OUT->neuron_top_shear = sensorRow_Values_Right.force_r_top;
				
				BLDC_OUT->neuron_middle_normal = sensorRow_Values_Right.force_z_middle;
				BLDC_OUT->neuron_middle_shear = sensorRow_Values_Right.force_r_middle;
				
				BLDC_OUT->neuron_bottom_normal = sensorRow_Values_Right.force_z_bottom;
				BLDC_OUT->neuron_bottom_shear = sensorRow_Values_Right.force_r_bottom;
				break;
				
				case 2: ;
				BLDC_OUT->neuron_top_normal = neuronRow_Values_Right.neuron_top_normal;
				BLDC_OUT->neuron_top_shear = neuronRow_Values_Right.neuron_top_shear;
				
				BLDC_OUT->neuron_middle_normal = neuronRow_Values_Right.neuron_middle_normal;
				BLDC_OUT->neuron_middle_shear = neuronRow_Values_Right.neuron_middle_shear;
				
				BLDC_OUT->neuron_bottom_normal = neuronRow_Values_Right.neuron_bottom_normal;
				BLDC_OUT->neuron_bottom_shear = neuronRow_Values_Right.neuron_bottom_shear;
				break;
			}
			
			/*
			BLDC_OUT->hall_bottom_x = sensor3.data.x; //data1,2,3
			BLDC_OUT->hall_bottom_y = sensor3.data.y;
			BLDC_OUT->hall_bottom_z = sensor3.data.z;
			
			BLDC_OUT->hall_middle_x = sensor6.data.x; //data4,5,6
			BLDC_OUT->hall_middle_y = sensor6.data.y;
			BLDC_OUT->hall_middle_z = sensor6.data.z;
			
			BLDC_OUT->hall_top_x = sensor9.data.x; //data7,8,9
			BLDC_OUT->hall_top_y = sensor9.data.y;
			BLDC_OUT->hall_top_z = sensor9.data.z;
			*/
			//mag_to_force(&sensorRow_Values_1, &sensor3, &sensor6, &sensor9);
			//neuron_calc(&sensorRow_Values_1,&neuron1_normal,&neuron1_shear,&neuron2_normal,&neuron2_shear, &neuron3_normal,&neuron3_shear);
			
			BLDC_OUT->hall_middle_temp = 3;
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
	
	// for testing purposes
	gpio_set_pin_level(TRG,false);
	gpio_set_pin_level(TRG,true);
	
	// Initialize Sensor Array
	SensorArray_Init(&sensor1,&sensor2,&sensor3,&sensor4,&sensor5,&sensor6,&sensor7,&sensor8,&sensor9,bmx_io);
	//neuron_init(&neuron1_normal,&neuron1_shear,&neuron2_normal,&neuron2_shear, &neuron3_normal,&neuron3_shear); Needs to be Implemented in future Version 

	gpio_set_pin_level(TRG,false);
	
	//Initialize ReadoutVariables
	new_data = false;
	triggered = false;
	data_readout = false;
	wait_time = convDelayMicro(&sensor9);
	//TIMER_init(wait_time);
	NVIC_EnableIRQ(TC3_IRQn);
	selected_row = 2; //1 = left, 2 = middle, 3 = right
	selected_output_mode = 1; //1 = Force, 2 = Neural Spikes
	/* Replace with your application code */
	while (1) {
		
		if (triggered == false)	{
			BLDC_OUT->hall_middle_temp = 0;
			triggerSensor(50);
			//triggerReadout_Prepare_Timer(50);
	//		timer_start(&TIMER_1);
			triggered = true;
			data_readout = false;
		}
		if(new_data == true && data_readout == false){	
			triggerReadoutArray(&sensor1,&sensor2,&sensor3,&sensor4,&sensor5,&sensor6,&sensor7,&sensor8,&sensor9,bmx_io);
			SensorRowUpdate(selected_row, selected_output_mode); //must be modified later to allow readout of whole array - for loop where every row is selected once
			new_data = false; 
			data_readout = true;
			//triggered = false;
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
