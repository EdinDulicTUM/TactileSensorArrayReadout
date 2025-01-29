/*
 * SensorArray.c
 *
 * Created: 11.12.2024 18:02:12
 *  Author: dulic
 */ 
#include <Melexis/SensorArray.h>



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

