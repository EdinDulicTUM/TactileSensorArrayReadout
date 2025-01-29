#include <atmel_start.h>
#include <Melexis/MLX90393_microchip.h>
#include <stdio.h>
#include <string.h>
#include <driver_init.h>
#include <math.h>
#include <Melexis/SensorArray.h>

//struct for I2C IO
struct io_descriptor *bmx_io;
//io descriptor for debug UART
struct io_descriptor *debug_io;

static struct timer_task TIMER_task1; 

bool new_data; 
bool triggered;
uint16_t wait_time;

struct MLX90393 sensor1;
struct MLX90393 sensor2;
struct MLX90393 sensor3;
struct MLX90393 sensor4;
struct MLX90393 sensor5;
struct MLX90393 sensor6;
struct MLX90393 sensor7;
struct MLX90393 sensor8;
struct MLX90393 sensor9;


void counter_delay(uint16_t counter){
	int counter_inter = 0;
	for (int i = 0; i< counter; i++)
	{
		counter_inter++;
	}
}


static void TIMER_task1_cb(const struct timer_task *const timer_task)
{
	triggerReadoutArray(&sensor1,&sensor2,&sensor3,&sensor4,&sensor5,&sensor6,&sensor7,&sensor8,&sensor9,bmx_io);
	new_data = true;
	timer_stop(&TIMER_0);
};

void TIMER_init(uint16_t timer_interval)
{
	TIMER_task1.interval = timer_interval;
	TIMER_task1.cb       = TIMER_task1_cb;
	TIMER_task1.mode     = TIMER_TASK_REPEAT;

	timer_add_task(&TIMER_0, &TIMER_task1);
	//timer_start(&TIMER_0);
};


int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	
	//Initialize I2C communication
	i2c_m_sync_get_io_descriptor(&I2C_0, &bmx_io);
	i2c_m_sync_enable(&I2C_0);
	
	//enable UART drivers on the virtual com port
	usart_sync_get_io_descriptor(&USART_0, &debug_io);
	usart_sync_enable(&USART_0);

		
    gpio_set_pin_level(TRG,false);
	gpio_set_pin_level(TRG,true);
	
    //bottom row left
	initialize(&sensor1);
	begin(&sensor1,1,0,0,false, bmx_io);
	triggerInitialize(&sensor1,bmx_io);
	//delay_ms(1);
	
	//bottom row middle
	initialize(&sensor2);
	begin(&sensor2,1,0,1,false, bmx_io);
	triggerInitialize(&sensor2,bmx_io);
	//delay_ms(1);
	//counter_delay(30000);
	
	//bottom row right
	initialize(&sensor3);
	begin(&sensor3,1,1,0,false, bmx_io);
	triggerInitialize(&sensor3,bmx_io);
	//delay_ms(10);
	
	//middle row left
	initialize(&sensor4);
	begin(&sensor4,2,0,0,false, bmx_io);
	triggerInitialize(&sensor4,bmx_io);
	//delay_ms(10);
	    
	//middle row middle
	initialize(&sensor5);
	begin(&sensor5,2,0,1,false, bmx_io);
	triggerInitialize(&sensor5,bmx_io);
	//delay_ms(10);
	    
	 //middle row right
	 initialize(&sensor6);
	 begin(&sensor6,2,1,0,false, bmx_io);
	 triggerInitialize(&sensor6,bmx_io);
	 //delay_ms(10);
	 
	 //top row left
	 initialize(&sensor7);
	 begin(&sensor7,3,0,0,false, bmx_io);
	 triggerInitialize(&sensor7,bmx_io);
	 //delay_ms(10);
	     
	 //top row middle
	 initialize(&sensor8);
	 begin(&sensor8,3,0,1,false, bmx_io);
	 triggerInitialize(&sensor8,bmx_io);
	 //delay_ms(10);
	     
	 //top row right
	 initialize(&sensor9);
	 begin(&sensor9,3,1,0,false, bmx_io);
	 triggerInitialize(&sensor9,bmx_io);
	 //delay_ms(10);
	 
	 gpio_set_pin_level(TRG,false);
	 
	 new_data = false;
	 triggered = false;
	wait_time = convDelayMillis(&sensor9);
	TIMER_init(wait_time);



	/* Replace with your application code */
	while (1) {
		
		
		
		/*
		readData(&sensor1, bmx_io);
		readData(&sensor2, bmx_io);
		readData(&sensor3, bmx_io);
		readData(&sensor4, bmx_io);
		readData(&sensor5, bmx_io);
		readData(&sensor6, bmx_io);
		readData(&sensor7, bmx_io);
		readData(&sensor8, bmx_io);
		readData(&sensor9, bmx_io);
		*/
		
		
		//triggerReadout_Prepare(&sensor1,50);
		
	if (triggered == false)	{
		triggerReadout_Prepare_Timer(50);
		timer_start(&TIMER_0);
		triggered = true;
	}
		
		/*
		triggerReadout(&sensor1,bmx_io);
		triggerReadout(&sensor2,bmx_io);
		triggerReadout(&sensor3,bmx_io);
		triggerReadout(&sensor4,bmx_io);
		triggerReadout(&sensor5,bmx_io);
		triggerReadout(&sensor6,bmx_io);
		triggerReadout(&sensor7,bmx_io);
		triggerReadout(&sensor8,bmx_io);
		triggerReadout(&sensor9,bmx_io);
		*/
	
	if(new_data == true){	
		char str1[120] = {};
		sprintf(str1, "Sensor 1: X=%.2f; Y=%.2f;  Z=%.2f; Temp = %.2f\n", sensor1.data.x, sensor1.data.y, sensor1.data.z, sensor1.data.t);
		io_write(debug_io, (uint8_t *)str1, strlen(str1));
		
		char str2[120] = {};
		sprintf(str2, "Sensor 2: X=%.2f; Y=%.2f;  Z=%.2f; Temp = %.2f\n", sensor2.data.x, sensor2.data.y, sensor2.data.z, sensor2.data.t);
		io_write(debug_io, (uint8_t *)str2, strlen(str2));
	
		char str3[120] = {};
		sprintf(str3, "Sensor 3: X=%.2f; Y=%.2f;  Z=%.2f; Temp = %.2f\n", sensor3.data.x, sensor3.data.y, sensor3.data.z, sensor3.data.t);
		io_write(debug_io, (uint8_t *)str3, strlen(str3));
		
		char str4[120] = {};
		sprintf(str4, "Sensor 4: X=%.2f; Y=%.2f;  Z=%.2f; Temp = %.2f\n", sensor4.data.x, sensor4.data.y, sensor4.data.z, sensor4.data.t);
		io_write(debug_io, (uint8_t *)str4, strlen(str4));
		
		char str5[120] = {};
		sprintf(str5, "Sensor 5: X=%.2f; Y=%.2f;  Z=%.2f; Temp = %.2f\n", sensor5.data.x, sensor5.data.y, sensor5.data.z, sensor5.data.t);
		io_write(debug_io, (uint8_t *)str5, strlen(str5));
		
		char str6[120] = {};
		sprintf(str6, "Sensor 6: X=%.2f; Y=%.2f;  Z=%.2f; Temp = %.2f\n", sensor6.data.x, sensor6.data.y, sensor6.data.z, sensor6.data.t);
		io_write(debug_io, (uint8_t *)str6, strlen(str6));
		
		char str7[120] = {};
		sprintf(str7, "Sensor 7: X=%.2f; Y=%.2f;  Z=%.2f; Temp = %.2f\n", sensor7.data.x, sensor7.data.y, sensor7.data.z, sensor7.data.t);
		io_write(debug_io, (uint8_t *)str7, strlen(str7));
		
		char str8[120] = {};
		sprintf(str8, "Sensor 8: X=%.2f; Y=%.2f;  Z=%.2f; Temp = %.2f\n", sensor8.data.x, sensor8.data.y, sensor8.data.z, sensor8.data.t);
		io_write(debug_io, (uint8_t *)str8, strlen(str8));
				
		char str9[120] = {};
		sprintf(str9, "Sensor 9: X=%.2f; Y=%.2f;  Z=%.2f; Temp = %.2f\n", sensor9.data.x, sensor9.data.y, sensor9.data.z, sensor9.data.t);
		io_write(debug_io, (uint8_t *)str9, strlen(str9));

		char str10[100] = {};
		sprintf(str10, "-------------------------------------------------------------\n");
		io_write(debug_io, (uint8_t *)str10, strlen(str10));
		//delay_ms(1000);
		new_data = false; 
		triggered = false;
		}
	
	}
}
