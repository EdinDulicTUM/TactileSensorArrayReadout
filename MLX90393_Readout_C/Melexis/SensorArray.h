/*
 * SensorArray.h
 *
 * Created: 11.12.2024 18:03:27
 *  Author: dulic
 */ 


#ifndef SENSORARRAY_H_
#define SENSORARRAY_H_
#include <Melexis/MLX90393_microchip.h>


void triggerSensor(uint16_t pulseTime);
void triggerReadout_Prepare(struct MLX90393 *hall_sensor, uint16_t pulseTime);
void triggerReadout_Prepare_Timer(uint16_t pulseTime);
void triggerInitialize(struct MLX90393 *hall_sensor, struct io_descriptor *io); 
uint8_t triggerReadout(struct MLX90393 *hall_sensor, struct io_descriptor *io);
uint8_t triggerReadoutArray(struct MLX90393 *hall_sensor_1, struct MLX90393 *hall_sensor_2, struct MLX90393 *hall_sensor_3,
							struct MLX90393 *hall_sensor_4, struct MLX90393 *hall_sensor_5, struct MLX90393 *hall_sensor_6,
							struct MLX90393 *hall_sensor_7, struct MLX90393 *hall_sensor_8, struct MLX90393 *hall_sensor_9,
							struct io_descriptor *io);


#endif /* SENSORARRAY_H_ */