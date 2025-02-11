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
static struct timer_task TIMER_task1;

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


// 
struct fneuron_t neuron1_normal; 
struct fneuron_t neuron1_shear; 
struct fneuron_t neuron2_normal; 
struct fneuron_t neuron2_shear; 
struct fneuron_t neuron3_normal;
struct fneuron_t neuron3_shear;

struct sensorRow_Values sensorRow_Values_1; 



//readout variables
bool new_data;
bool triggered;
uint16_t wait_time;
uint8_t selected_row;

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


volatile BLDC_ECAT_OUT* const BLDC_OUT =&ram_buffer[ram_wr_start];
volatile BLDC_ECAT_IN* const BLDC_IN =&ram_buffer[ram_rd_start];

static void TIMER_task1_cb(const struct timer_task *const timer_task)
{
	triggerReadoutArray(&sensor1,&sensor2,&sensor3,&sensor4,&sensor5,&sensor6,&sensor7,&sensor8,&sensor9,bmx_io);
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

void SensorRowUpdate(uint8_t row_select)
{
	switch(row_select){
		case 1: ;
			BLDC_OUT->hall_bottom_x = sensor1.data.x; //data1,2,3
			BLDC_OUT->hall_bottom_y = sensor1.data.y;
			BLDC_OUT->hall_bottom_z = sensor1.data.z;
	
			BLDC_OUT->hall_middle_x = sensor4.data.x; //data4,5,6
			BLDC_OUT->hall_middle_y = sensor4.data.y;
			BLDC_OUT->hall_middle_z = sensor4.data.z;
			
			BLDC_OUT->hall_top_x = sensor7.data.x; //data7,8,9
			BLDC_OUT->hall_top_y = sensor7.data.y;
			BLDC_OUT->hall_top_z = sensor7.data.z;
			
			//mag_to_force(&sensorRow_Values_1, &sensor1, &sensor4, &sensor7);
			//neuron_calc(&sensorRow_Values_1,&neuron1_normal,&neuron1_shear,&neuron2_normal,&neuron2_shear, &neuron3_normal,&neuron3_shear);
			
			BLDC_OUT->hall_middle_temp = 1;
			break;
		
		case 2: ;
			BLDC_OUT->hall_bottom_x = sensor2.data.x; //data1,2,3
			BLDC_OUT->hall_bottom_y = sensor2.data.y;
			BLDC_OUT->hall_bottom_z = sensor2.data.z;
			
			BLDC_OUT->hall_middle_x = sensor5.data.x; //data4,5,6
			BLDC_OUT->hall_middle_y = sensor5.data.y;
			BLDC_OUT->hall_middle_z = sensor5.data.z;
			
			BLDC_OUT->hall_top_x = sensor8.data.x; //data7,8,9
			BLDC_OUT->hall_top_y = sensor8.data.y;
			BLDC_OUT->hall_top_z = sensor8.data.z;
		
			//mag_to_force(&sensorRow_Values_1, &sensor2, &sensor5, &sensor8);
			//neuron_calc(&sensorRow_Values_1,&neuron1_normal,&neuron1_shear,&neuron2_normal,&neuron2_shear, &neuron3_normal,&neuron3_shear);
			
			BLDC_OUT->hall_middle_temp = 2;
			break;
			
		case 3: ;
			BLDC_OUT->hall_bottom_x = sensor3.data.x; //data1,2,3
			BLDC_OUT->hall_bottom_y = sensor3.data.y;
			BLDC_OUT->hall_bottom_z = sensor3.data.z;
			
			BLDC_OUT->hall_middle_x = sensor6.data.x; //data4,5,6
			BLDC_OUT->hall_middle_y = sensor6.data.y;
			BLDC_OUT->hall_middle_z = sensor6.data.z;
			
			BLDC_OUT->hall_top_x = sensor9.data.x; //data7,8,9
			BLDC_OUT->hall_top_y = sensor9.data.y;
			BLDC_OUT->hall_top_z = sensor9.data.z;
			
			//mag_to_force(&sensorRow_Values_1, &sensor3, &sensor6, &sensor9);
			//neuron_calc(&sensorRow_Values_1,&neuron1_normal,&neuron1_shear,&neuron2_normal,&neuron2_shear, &neuron3_normal,&neuron3_shear);
			
			BLDC_OUT->hall_middle_temp = 3;
			break;
		}
}


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
	//neuron_init(&neuron1_normal,&neuron1_shear,&neuron2_normal,&neuron2_shear, &neuron3_normal,&neuron3_shear);

	gpio_set_pin_level(TRG,false);
	
	//Initialize ReadoutVariables
	new_data = false;
	triggered = false;
	wait_time = convDelayMicro(&sensor9);
	TIMER_init(wait_time);
	selected_row = 1; //1 = left, 2 = middle, 3 = right
	
	/* Replace with your application code */
	while (1) {
		
		if (triggered == false)	{
			BLDC_OUT->hall_middle_temp = 0;
			triggerReadout_Prepare_Timer(50);
			timer_start(&TIMER_1);
			triggered = true;
		}
		if(new_data == true){	
			SensorRowUpdate(selected_row);
			new_data = false; 
			triggered = false;
		}
	}
}
