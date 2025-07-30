/*
 * SensorArray.h
 *
 * Created: 11.12.2024 18:03:27
 *  Author: dulic
 */ 


#ifndef SENSORARRAY_H_
#define SENSORARRAY_H_
#include <Melexis/MLX90393_microchip.h>

typedef struct sensorRow_Values{
	
	float b_x_top, b_x_middle, b_x_bottom;
	float b_y_top, b_y_middle, b_y_bottom;
	float b_z_top, b_z_middle, b_z_bottom;
	float b_r_top, b_r_middle, b_r_bottom;
	float force_x_top, force_x_middle, force_x_bottom;
	float force_y_top, force_y_middle, force_y_bottom;
	float force_z_top, force_z_middle, force_z_bottom;
	float force_r_top, force_r_middle, force_r_bottom;
}sensorRow_Values;


void triggerSensor(uint16_t pulseTime);
void triggerReadout_Prepare(struct MLX90393 *hall_sensor, uint16_t pulseTime);
void triggerReadout_Prepare_Timer(uint16_t pulseTime);
void triggerInitialize(struct MLX90393 *hall_sensor, struct i2c_m_sync_desc *const i2c, struct io_descriptor *io); 
uint8_t triggerReadout(struct MLX90393 *hall_sensor, struct i2c_m_sync_desc *const i2c, struct io_descriptor *io);
uint8_t triggerReadoutArray(struct MLX90393 *hall_sensor_1, struct MLX90393 *hall_sensor_2, struct MLX90393 *hall_sensor_3,
							struct MLX90393 *hall_sensor_4, struct MLX90393 *hall_sensor_5, struct MLX90393 *hall_sensor_6,
							struct MLX90393 *hall_sensor_7, struct MLX90393 *hall_sensor_8, struct MLX90393 *hall_sensor_9,
							struct i2c_m_sync_desc *const i2c, struct io_descriptor *io);
void SensorArray_Init(struct MLX90393 *hall_sensor_1, struct MLX90393 *hall_sensor_2, struct MLX90393 *hall_sensor_3,
							struct MLX90393 *hall_sensor_4, struct MLX90393 *hall_sensor_5, struct MLX90393 *hall_sensor_6,
							struct MLX90393 *hall_sensor_7, struct MLX90393 *hall_sensor_8, struct MLX90393 *hall_sensor_9,
							struct i2c_m_sync_desc *const i2c, struct io_descriptor *io);
void update_struct_values(struct sensorRow_Values *sensor_row, struct MLX90393 *hall_sensor_top, struct MLX90393 *hall_sensor_middle, struct MLX90393 *hall_sensor_bottom);
void mag_to_force(uint8_t row_select, struct sensorRow_Values *sensor_row);

#endif /* SENSORARRAY_H_ */