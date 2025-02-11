/*
 * SensorArray.c
 *
 * Created: 11.12.2024 18:02:12
 *  Author: dulic
 */ 
#include <Melexis/SensorArray.h>
#include "math.h"


void triggerInitialize(struct MLX90393 *hall_sensor, struct io_descriptor *io)
{
		//setTrigIntSel(hall_sensor,1,io);
		setExtTrig(hall_sensor,1,io);
		//startMeasurement(hall_sensor, X_FLAG | Y_FLAG | Z_FLAG | T_FLAG, io);
		startMeasurement(hall_sensor, X_FLAG | Y_FLAG | Z_FLAG, io);
}


void triggerSensor(uint16_t pulseTime)
{
	gpio_set_pin_level(TRG,true);
	delay_us(pulseTime);
	gpio_set_pin_level(TRG,false);
};

void triggerReadout_Prepare(struct MLX90393 *hall_sensor, uint16_t pulseTime) 
{
	triggerSensor(pulseTime);
	uint16_t delayTime = convDelayMillis(hall_sensor);
	delay_ms(delayTime); //can be optimized as clock is not that precise
};

void triggerReadout_Prepare_Timer(uint16_t pulseTime)
{
	triggerSensor(pulseTime);
};

uint8_t triggerReadout(struct MLX90393 *hall_sensor, struct io_descriptor *io)
{
	//uint8_t status = readMeasurement(hall_sensor, X_FLAG | Y_FLAG | Z_FLAG | T_FLAG, io);
	uint8_t status = readMeasurement(hall_sensor, X_FLAG | Y_FLAG | Z_FLAG , io);
	convertRaw(hall_sensor);
	return checkStatus(status);
};


uint8_t triggerReadoutArray(struct MLX90393 *hall_sensor_1, struct MLX90393 *hall_sensor_2, struct MLX90393 *hall_sensor_3, 
						    struct MLX90393 *hall_sensor_4, struct MLX90393 *hall_sensor_5, struct MLX90393 *hall_sensor_6, 
					        struct MLX90393 *hall_sensor_7, struct MLX90393 *hall_sensor_8, struct MLX90393 *hall_sensor_9,
					        struct io_descriptor *io)
{
	uint8_t status1 = triggerReadout(hall_sensor_1,io);
	uint8_t status2 = triggerReadout(hall_sensor_2,io);
	uint8_t status3 = triggerReadout(hall_sensor_3,io);
	uint8_t status4 = triggerReadout(hall_sensor_4,io);
	uint8_t status5 = triggerReadout(hall_sensor_5,io);
	uint8_t status6 = triggerReadout(hall_sensor_6,io);
	uint8_t status7 = triggerReadout(hall_sensor_7,io);
	uint8_t status8 = triggerReadout(hall_sensor_8,io);
	uint8_t status9 = triggerReadout(hall_sensor_9,io);
	
	return checkStatus(status1) | checkStatus(status2) | checkStatus(status3) | checkStatus(status4) | checkStatus(status5) | checkStatus(status6) | checkStatus(status7) | checkStatus(status8) | checkStatus(status9);
};

void SensorArray_Init(struct MLX90393 *hall_sensor_1, struct MLX90393 *hall_sensor_2, struct MLX90393 *hall_sensor_3,
struct MLX90393 *hall_sensor_4, struct MLX90393 *hall_sensor_5, struct MLX90393 *hall_sensor_6,
struct MLX90393 *hall_sensor_7, struct MLX90393 *hall_sensor_8, struct MLX90393 *hall_sensor_9,
struct io_descriptor *io)
{
	//bottom row left
	initialize(hall_sensor_1);
	begin(hall_sensor_1,1,0,0,false, io);
	triggerInitialize(hall_sensor_1, io);
	
	//bottom row middle
	initialize(hall_sensor_2);
	begin(hall_sensor_2,1,0,1,false, io);
	triggerInitialize(hall_sensor_2, io);
	
	//bottom row right
	initialize(hall_sensor_3);
	begin(hall_sensor_3,1,1,0,false, io);
	triggerInitialize(hall_sensor_3, io);
	
	//middle row left
	initialize(hall_sensor_4);
	begin(hall_sensor_4,2,0,0,false, io);
	triggerInitialize(hall_sensor_4, io);
	
	//middle row middle
	initialize(hall_sensor_5);
	begin(hall_sensor_5,2,0,1,false, io);
	triggerInitialize(hall_sensor_5, io);
	
	//middle row right
	initialize(hall_sensor_6);
	begin(hall_sensor_6,2,1,0,false, io);
	triggerInitialize(hall_sensor_6, io);
	
	//top row left
	initialize(hall_sensor_7);
	begin(hall_sensor_7,3,0,0,false, io);
	triggerInitialize(hall_sensor_7, io);
	
	//top row middle
	initialize(hall_sensor_8);
	begin(hall_sensor_8,3,0,1,false, io);
	triggerInitialize(hall_sensor_8, io);
	
	//top row right
	initialize(hall_sensor_9);
	begin(hall_sensor_9,3,1,0,false, io);
	triggerInitialize(hall_sensor_9, io);
}

void mag_to_force(struct sensorRow_Values *sensor_row, struct MLX90393 *hall_sensor_top, struct MLX90393 *hall_sensor_middle, struct MLX90393 *hall_sensor_bottom){
	
	//Convert to B_r
	sensor_row->b_r_top = (hall_sensor_top->data.x*hall_sensor_top->data.x) + (hall_sensor_top->data.y*hall_sensor_top->data.y);
	sensor_row->b_r_top = sqrt(sensor_row->b_r_top);
	
	
	sensor_row->b_r_middle = (hall_sensor_middle->data.x*hall_sensor_middle->data.x) + (hall_sensor_middle->data.y*hall_sensor_middle->data.y);
	sensor_row->b_r_middle = sqrt(sensor_row->b_r_middle);
	
	sensor_row->b_r_bottom = (hall_sensor_bottom->data.x*hall_sensor_bottom->data.x) + (hall_sensor_bottom->data.y*hall_sensor_bottom->data.y);
	sensor_row->b_r_bottom = sqrt(sensor_row->b_r_bottom);
	
	sensor_row->force_z_top = 51.152 + (0.0068*sensor_row->b_r_top) + (0.0130*hall_sensor_top->data.z);
	sensor_row->force_r_top = 8.9701 + (0.0106*sensor_row->b_r_top) + (0.0026*hall_sensor_top->data.z);

	sensor_row->force_z_middle =-22.8835 + (0.0014*sensor_row->b_r_top) + (0.0017*hall_sensor_middle->data.z);
	sensor_row->force_r_middle =-10.1016 + (0.0031*sensor_row->b_r_top) + (-0.0014*hall_sensor_middle->data.z);
	
	sensor_row->force_z_bottom = 35.2728 + (-0.0130*sensor_row->b_r_top) + (0.0084*hall_sensor_bottom->data.z);
	sensor_row->force_r_bottom = 9.9403 + (-0.0075*sensor_row->b_r_top) + (0.0013*hall_sensor_bottom->data.z);
	
	
}