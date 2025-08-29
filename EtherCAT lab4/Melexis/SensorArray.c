/*
 * SensorArray.c
 *
 * Created: 11.12.2024 18:02:12
 *  Author: dulic
 */ 
#include <Melexis/SensorArray.h>
#include <math.h>
#include <Melexis/Calibration_Parameters.h>


void triggerInitialize(struct MLX90393 *hall_sensor, struct i2c_m_sync_desc *const i2c, struct io_descriptor *io)
{
		//setTrigIntSel(hall_sensor,1,io);
		setExtTrig(hall_sensor,1,i2c,io);
		//startMeasurement(hall_sensor, X_FLAG | Y_FLAG | Z_FLAG | T_FLAG, io);
		startMeasurement(hall_sensor, X_FLAG | Y_FLAG | Z_FLAG, i2c, io);
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

uint8_t triggerReadout(struct MLX90393 *hall_sensor, struct i2c_m_sync_desc *const i2c, struct io_descriptor *io)
{
	//uint8_t status = readMeasurement(hall_sensor, X_FLAG | Y_FLAG | Z_FLAG | T_FLAG, io);
	uint8_t status = readMeasurement(hall_sensor, X_FLAG | Y_FLAG | Z_FLAG , i2c, io);
	convertRaw(hall_sensor);
	return checkStatus(status);
};


uint8_t triggerReadoutArray(struct MLX90393 *hall_sensor_1, struct MLX90393 *hall_sensor_2, struct MLX90393 *hall_sensor_3, 
						    struct MLX90393 *hall_sensor_4, struct MLX90393 *hall_sensor_5, struct MLX90393 *hall_sensor_6, 
					        struct MLX90393 *hall_sensor_7, struct MLX90393 *hall_sensor_8, struct MLX90393 *hall_sensor_9,
					        struct i2c_m_sync_desc *const i2c, struct io_descriptor *io)
{
	uint8_t status1 = triggerReadout(hall_sensor_1,i2c,io);
	uint8_t status2 = triggerReadout(hall_sensor_2,i2c,io);
	uint8_t status3 = triggerReadout(hall_sensor_3,i2c,io);
	uint8_t status4 = triggerReadout(hall_sensor_4,i2c,io);
	uint8_t status5 = triggerReadout(hall_sensor_5,i2c,io);
	uint8_t status6 = triggerReadout(hall_sensor_6,i2c,io);
	uint8_t status7 = triggerReadout(hall_sensor_7,i2c,io);
	uint8_t status8 = triggerReadout(hall_sensor_8,i2c,io);
	uint8_t status9 = triggerReadout(hall_sensor_9,i2c,io);
	
	return checkStatus(status1) | checkStatus(status2) | checkStatus(status3) | checkStatus(status4) | checkStatus(status5) | checkStatus(status6) | checkStatus(status7) | checkStatus(status8) | checkStatus(status9);
};

void SensorArray_Init(struct MLX90393 *hall_sensor_1, struct MLX90393 *hall_sensor_2, struct MLX90393 *hall_sensor_3,
					  struct MLX90393 *hall_sensor_4, struct MLX90393 *hall_sensor_5, struct MLX90393 *hall_sensor_6,
					  struct MLX90393 *hall_sensor_7, struct MLX90393 *hall_sensor_8, struct MLX90393 *hall_sensor_9,
					  struct i2c_m_sync_desc *const i2c, struct io_descriptor *io)
{
	//bottom row left
	initialize(hall_sensor_1);
	begin(hall_sensor_1,1,0,0,false, i2c, io);
	triggerInitialize(hall_sensor_1, i2c, io);
	delay_ms(5);
	
	//bottom row middle
	initialize(hall_sensor_2);
	begin(hall_sensor_2,1,0,1,false, i2c, io);
	triggerInitialize(hall_sensor_2, i2c, io);
	delay_ms(5);
	
	//bottom row right
	initialize(hall_sensor_3);
	begin(hall_sensor_3,1,1,0,false, i2c, io);
	triggerInitialize(hall_sensor_3, i2c, io);
	delay_ms(5);
	
	//middle row left
	initialize(hall_sensor_4);
	begin(hall_sensor_4,2,0,0,false, i2c, io);
	triggerInitialize(hall_sensor_4, i2c, io);
	delay_ms(5);
	
	//middle row middle
	initialize(hall_sensor_5);
	begin(hall_sensor_5,2,0,1,false, i2c, io);
	triggerInitialize(hall_sensor_5, i2c, io);
	delay_ms(5);
	
	//middle row right
	initialize(hall_sensor_6);
	begin(hall_sensor_6,2,1,0,false, i2c, io);
	triggerInitialize(hall_sensor_6, i2c, io);
	delay_ms(5);
	
	//top row left
	initialize(hall_sensor_7);
	begin(hall_sensor_7,3,0,0,false, i2c, io);
	triggerInitialize(hall_sensor_7, i2c, io);
	delay_ms(5);
	
	//top row middle
	initialize(hall_sensor_8);
	begin(hall_sensor_8,3,0,1,false, i2c, io);
	triggerInitialize(hall_sensor_8, i2c, io);
	delay_ms(5);
	
	//top row right
	initialize(hall_sensor_9);
	begin(hall_sensor_9,3,1,0,false, i2c, io);
	triggerInitialize(hall_sensor_9, i2c, io);
	delay_ms(5);
}


void update_struct_values(struct sensorRow_Values *sensor_row, struct MLX90393 *hall_sensor_top, struct MLX90393 *hall_sensor_middle, struct MLX90393 *hall_sensor_bottom){
		//allocate every data to corresponding struct value
		sensor_row->b_x_top = hall_sensor_top->data.x;
		sensor_row->b_y_top = hall_sensor_top->data.y;
		sensor_row->b_z_top = hall_sensor_top->data.z;
		
		sensor_row->b_x_middle = hall_sensor_middle->data.x;
		sensor_row->b_y_middle = hall_sensor_middle->data.y;
		sensor_row->b_z_middle = hall_sensor_middle->data.z;
		
		sensor_row->b_x_bottom = hall_sensor_bottom->data.x;
		sensor_row->b_y_bottom = hall_sensor_bottom->data.y;
		sensor_row->b_z_bottom = hall_sensor_bottom->data.z;
		
		/* not necessary anymore due to calculation with Bx and By instead
		//Combine X and Y Axis Into Br
		sensor_row->b_r_top = (sensor_row->b_x_top*sensor_row->b_x_top) + (sensor_row->b_y_top*sensor_row->b_y_top);
		sensor_row->b_r_top = sqrt(sensor_row->b_r_top);

		sensor_row->b_r_middle = (sensor_row->b_x_middle*sensor_row->b_x_middle) + (sensor_row->b_y_middle*sensor_row->b_y_middle);
		sensor_row->b_r_middle = sqrt(sensor_row->b_r_middle);
		
		sensor_row->b_r_bottom = (sensor_row->b_x_bottom*sensor_row->b_x_bottom) + (sensor_row->b_y_bottom *sensor_row->b_y_bottom );
		sensor_row->b_r_bottom = sqrt(sensor_row->b_r_bottom);
		*/
	
}

float calibration_function(float c1, float c2, float c3, float c4, float c5, float c6, float c7, float c8, float c9, float c10, 
						   float c11, float c12, float c13, float c14, float c15, float c16, float c17, float c18, float c19, float c20,
						   float Bx, float By, float Bz)
{
	float result;
	float cubedBx,squaredBx;
	float cubedBy,squaredBy;
	float cubedBz,squaredBz;
	cubedBx = pow(Bx,3);
	cubedBy = pow(By,3);
	cubedBz = pow(Bz,3);
	squaredBx = pow(Bx,2);
	squaredBy = pow(By,2);
	squaredBz = pow(Bz,2);
	result = (c1*cubedBx) + (c2*squaredBx*By) + (c3*squaredBx*Bz) + (c4*squaredBx) + (c5*Bx*squaredBy) + (c6*Bx*By*Bz) + (c7*Bx*By) + (c8*Bx*squaredBz) + (c9*Bx*Bz) + (c10*Bx) +
			 (c11*cubedBy) + (c12*squaredBy*Bz) + (c13*squaredBy) + (c14*By*squaredBz) + (c15*By*Bz) + (c16*By) + (c17*cubedBz) + (c18*squaredBz) + (c19*Bz) + c20;
	return result;
}

void mag_to_force(uint8_t row_select, struct sensorRow_Values *sensor_row, struct function_Parameters *parameters_array){
	
	switch(row_select){
		
		case 1: ; // Left Row
			// Top Sensor
			sensor_row->force_x_top = calibration_function(parameters_array->sensor_topLeft[0][0],parameters_array->sensor_topLeft[1][0],parameters_array->sensor_topLeft[2][0],parameters_array->sensor_topLeft[3][0],parameters_array->sensor_topLeft[4][0],parameters_array->sensor_topLeft[5][0],parameters_array->sensor_topLeft[6][0],parameters_array->sensor_topLeft[7][0],parameters_array->sensor_topLeft[8][0],parameters_array->sensor_topLeft[9][0],parameters_array->sensor_topLeft[10][0],
														   parameters_array->sensor_topLeft[11][0],parameters_array->sensor_topLeft[12][0],parameters_array->sensor_topLeft[13][0],parameters_array->sensor_topLeft[14][0],parameters_array->sensor_topLeft[15][0],parameters_array->sensor_topLeft[16][0],parameters_array->sensor_topLeft[17][0],parameters_array->sensor_topLeft[18][0],parameters_array->sensor_topLeft[19][0],
														   sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
			sensor_row->force_y_top = calibration_function(parameters_array->sensor_topLeft[0][1],parameters_array->sensor_topLeft[1][1],parameters_array->sensor_topLeft[2][1],parameters_array->sensor_topLeft[3][1],parameters_array->sensor_topLeft[4][1],parameters_array->sensor_topLeft[5][1],parameters_array->sensor_topLeft[6][1],parameters_array->sensor_topLeft[7][1],parameters_array->sensor_topLeft[8][1],parameters_array->sensor_topLeft[9][1],parameters_array->sensor_topLeft[10][1],
														   parameters_array->sensor_topLeft[11][1],parameters_array->sensor_topLeft[12][1],parameters_array->sensor_topLeft[13][1],parameters_array->sensor_topLeft[14][1],parameters_array->sensor_topLeft[15][1],parameters_array->sensor_topLeft[16][1],parameters_array->sensor_topLeft[17][1],parameters_array->sensor_topLeft[18][1],parameters_array->sensor_topLeft[19][1],
														   sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
			sensor_row->force_z_top = calibration_function(parameters_array->sensor_topLeft[0][2],parameters_array->sensor_topLeft[1][2],parameters_array->sensor_topLeft[2][2],parameters_array->sensor_topLeft[3][2],parameters_array->sensor_topLeft[4][2],parameters_array->sensor_topLeft[5][2],parameters_array->sensor_topLeft[6][2],parameters_array->sensor_topLeft[7][2],parameters_array->sensor_topLeft[8][2],parameters_array->sensor_topLeft[9][2],parameters_array->sensor_topLeft[10][2],
														   parameters_array->sensor_topLeft[11][2],parameters_array->sensor_topLeft[12][2],parameters_array->sensor_topLeft[13][2],parameters_array->sensor_topLeft[14][2],parameters_array->sensor_topLeft[15][2],parameters_array->sensor_topLeft[16][2],parameters_array->sensor_topLeft[17][2],parameters_array->sensor_topLeft[18][2],parameters_array->sensor_topLeft[19][2],
														   sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
			sensor_row->force_r_top = (sensor_row->force_x_top*sensor_row->force_x_top) + (sensor_row->force_y_top*sensor_row->force_y_top);
			sensor_row->force_r_top = sqrt(sensor_row->force_r_top);
			
			// Middle Sensor
			sensor_row->force_x_middle = calibration_function(parameters_array->sensor_middleLeft[0][0],parameters_array->sensor_middleLeft[1][0],parameters_array->sensor_middleLeft[2][0],parameters_array->sensor_middleLeft[3][0],parameters_array->sensor_middleLeft[4][0],parameters_array->sensor_middleLeft[5][0],parameters_array->sensor_middleLeft[6][0],parameters_array->sensor_middleLeft[7][0],parameters_array->sensor_middleLeft[8][0],parameters_array->sensor_middleLeft[9][0],parameters_array->sensor_middleLeft[10][0],
															  parameters_array->sensor_middleLeft[11][0],parameters_array->sensor_middleLeft[12][0],parameters_array->sensor_middleLeft[13][0],parameters_array->sensor_middleLeft[14][0],parameters_array->sensor_middleLeft[15][0],parameters_array->sensor_middleLeft[16][0],parameters_array->sensor_middleLeft[17][0],parameters_array->sensor_middleLeft[18][0],parameters_array->sensor_middleLeft[19][0],
															  sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
			sensor_row->force_y_middle = calibration_function(parameters_array->sensor_middleLeft[0][1],parameters_array->sensor_middleLeft[1][1],parameters_array->sensor_middleLeft[2][1],parameters_array->sensor_middleLeft[3][1],parameters_array->sensor_middleLeft[4][1],parameters_array->sensor_middleLeft[5][1],parameters_array->sensor_middleLeft[6][1],parameters_array->sensor_middleLeft[7][1],parameters_array->sensor_middleLeft[8][1],parameters_array->sensor_middleLeft[9][1],parameters_array->sensor_middleLeft[10][1],
															  parameters_array->sensor_middleLeft[11][1],parameters_array->sensor_middleLeft[12][1],parameters_array->sensor_middleLeft[13][1],parameters_array->sensor_middleLeft[14][1],parameters_array->sensor_middleLeft[15][1],parameters_array->sensor_middleLeft[16][1],parameters_array->sensor_middleLeft[17][1],parameters_array->sensor_middleLeft[18][1],parameters_array->sensor_middleLeft[19][1],
															  sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
			sensor_row->force_z_middle = calibration_function(parameters_array->sensor_middleLeft[0][2],parameters_array->sensor_middleLeft[1][2],parameters_array->sensor_middleLeft[2][2],parameters_array->sensor_middleLeft[3][2],parameters_array->sensor_middleLeft[4][2],parameters_array->sensor_middleLeft[5][2],parameters_array->sensor_middleLeft[6][2],parameters_array->sensor_middleLeft[7][2],parameters_array->sensor_middleLeft[8][2],parameters_array->sensor_middleLeft[9][2],parameters_array->sensor_middleLeft[10][2],
															  parameters_array->sensor_middleLeft[11][2],parameters_array->sensor_middleLeft[12][2],parameters_array->sensor_middleLeft[13][2],parameters_array->sensor_middleLeft[14][2],parameters_array->sensor_middleLeft[15][2],parameters_array->sensor_middleLeft[16][2],parameters_array->sensor_middleLeft[17][2],parameters_array->sensor_middleLeft[18][2],parameters_array->sensor_middleLeft[19][2],
															  sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
			sensor_row->force_r_middle = (sensor_row->force_x_middle*sensor_row->force_x_middle) + (sensor_row->force_y_middle*sensor_row->force_y_middle);
			sensor_row->force_r_middle = sqrt(sensor_row->force_r_middle);
	
			// Bottom Sensor
			sensor_row->force_x_bottom = calibration_function(parameters_array->sensor_bottomLeft[0][0],parameters_array->sensor_bottomLeft[1][0],parameters_array->sensor_bottomLeft[2][0],parameters_array->sensor_bottomLeft[3][0],parameters_array->sensor_bottomLeft[4][0],parameters_array->sensor_bottomLeft[5][0],parameters_array->sensor_bottomLeft[6][0],parameters_array->sensor_bottomLeft[7][0],parameters_array->sensor_bottomLeft[8][0],parameters_array->sensor_bottomLeft[9][0],parameters_array->sensor_bottomLeft[10][0],
															  parameters_array->sensor_bottomLeft[11][0],parameters_array->sensor_bottomLeft[12][0],parameters_array->sensor_bottomLeft[13][0],parameters_array->sensor_bottomLeft[14][0],parameters_array->sensor_bottomLeft[15][0],parameters_array->sensor_bottomLeft[16][0],parameters_array->sensor_bottomLeft[17][0],parameters_array->sensor_bottomLeft[18][0],parameters_array->sensor_bottomLeft[19][0],
															  sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
			sensor_row->force_y_bottom = calibration_function(parameters_array->sensor_bottomLeft[0][1],parameters_array->sensor_bottomLeft[1][1],parameters_array->sensor_bottomLeft[2][1],parameters_array->sensor_bottomLeft[3][1],parameters_array->sensor_bottomLeft[4][1],parameters_array->sensor_bottomLeft[5][1],parameters_array->sensor_bottomLeft[6][1],parameters_array->sensor_bottomLeft[7][1],parameters_array->sensor_bottomLeft[8][1],parameters_array->sensor_bottomLeft[9][1],parameters_array->sensor_bottomLeft[10][1],
															  parameters_array->sensor_bottomLeft[11][1],parameters_array->sensor_bottomLeft[12][1],parameters_array->sensor_bottomLeft[13][1],parameters_array->sensor_bottomLeft[14][1],parameters_array->sensor_bottomLeft[15][1],parameters_array->sensor_bottomLeft[16][1],parameters_array->sensor_bottomLeft[17][1],parameters_array->sensor_bottomLeft[18][1],parameters_array->sensor_bottomLeft[19][1],
															  sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
			sensor_row->force_z_bottom = calibration_function(parameters_array->sensor_bottomLeft[0][2],parameters_array->sensor_bottomLeft[1][2],parameters_array->sensor_bottomLeft[2][2],parameters_array->sensor_bottomLeft[3][2],parameters_array->sensor_bottomLeft[4][2],parameters_array->sensor_bottomLeft[5][2],parameters_array->sensor_bottomLeft[6][2],parameters_array->sensor_bottomLeft[7][2],parameters_array->sensor_bottomLeft[8][2],parameters_array->sensor_bottomLeft[9][2],parameters_array->sensor_bottomLeft[10][2],
															  parameters_array->sensor_bottomLeft[11][2],parameters_array->sensor_bottomLeft[12][2],parameters_array->sensor_bottomLeft[13][2],parameters_array->sensor_bottomLeft[14][2],parameters_array->sensor_bottomLeft[15][2],parameters_array->sensor_bottomLeft[16][2],parameters_array->sensor_bottomLeft[17][2],parameters_array->sensor_bottomLeft[18][2],parameters_array->sensor_bottomLeft[19][2],
															  sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
			
			sensor_row->force_r_bottom = (sensor_row->force_x_bottom*sensor_row->force_x_bottom) + (sensor_row->force_y_bottom*sensor_row->force_y_bottom);
			sensor_row->force_r_bottom = sqrt(sensor_row->force_r_bottom);
		break;
	
		case 2: ; // Middle Row
			// Top Sensor
			sensor_row->force_x_top = calibration_function(parameters_array->sensor_topMiddle[0][0],parameters_array->sensor_topMiddle[1][0],parameters_array->sensor_topMiddle[2][0],parameters_array->sensor_topMiddle[3][0],parameters_array->sensor_topMiddle[4][0],parameters_array->sensor_topMiddle[5][0],parameters_array->sensor_topMiddle[6][0],parameters_array->sensor_topMiddle[7][0],parameters_array->sensor_topMiddle[8][0],parameters_array->sensor_topMiddle[9][0],parameters_array->sensor_topMiddle[10][0],
														   parameters_array->sensor_topMiddle[11][0],parameters_array->sensor_topMiddle[12][0],parameters_array->sensor_topMiddle[13][0],parameters_array->sensor_topMiddle[14][0],parameters_array->sensor_topMiddle[15][0],parameters_array->sensor_topMiddle[16][0],parameters_array->sensor_topMiddle[17][0],parameters_array->sensor_topMiddle[18][0],parameters_array->sensor_topMiddle[19][0],
														   sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
			sensor_row->force_y_top = calibration_function(parameters_array->sensor_topMiddle[0][1],parameters_array->sensor_topMiddle[1][1],parameters_array->sensor_topMiddle[2][1],parameters_array->sensor_topMiddle[3][1],parameters_array->sensor_topMiddle[4][1],parameters_array->sensor_topMiddle[5][1],parameters_array->sensor_topMiddle[6][1],parameters_array->sensor_topMiddle[7][1],parameters_array->sensor_topMiddle[8][1],parameters_array->sensor_topMiddle[9][1],parameters_array->sensor_topMiddle[10][1],
														   parameters_array->sensor_topMiddle[11][1],parameters_array->sensor_topMiddle[12][1],parameters_array->sensor_topMiddle[13][1],parameters_array->sensor_topMiddle[14][1],parameters_array->sensor_topMiddle[15][1],parameters_array->sensor_topMiddle[16][1],parameters_array->sensor_topMiddle[17][1],parameters_array->sensor_topMiddle[18][1],parameters_array->sensor_topMiddle[19][1],
														   sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
			sensor_row->force_z_top = calibration_function(parameters_array->sensor_topMiddle[0][2],parameters_array->sensor_topMiddle[1][2],parameters_array->sensor_topMiddle[2][2],parameters_array->sensor_topMiddle[3][2],parameters_array->sensor_topMiddle[4][2],parameters_array->sensor_topMiddle[5][2],parameters_array->sensor_topMiddle[6][2],parameters_array->sensor_topMiddle[7][2],parameters_array->sensor_topMiddle[8][2],parameters_array->sensor_topMiddle[9][2],parameters_array->sensor_topMiddle[10][2],
														   parameters_array->sensor_topMiddle[11][2],parameters_array->sensor_topMiddle[12][2],parameters_array->sensor_topMiddle[13][2],parameters_array->sensor_topMiddle[14][2],parameters_array->sensor_topMiddle[15][2],parameters_array->sensor_topMiddle[16][2],parameters_array->sensor_topMiddle[17][2],parameters_array->sensor_topMiddle[18][2],parameters_array->sensor_topMiddle[19][2],
														   sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
			
			sensor_row->force_r_top = (sensor_row->force_x_top*sensor_row->force_x_top) + (sensor_row->force_y_top*sensor_row->force_y_top);
			sensor_row->force_r_top = sqrt(sensor_row->force_r_top);
			
			// Middle Sensor
			sensor_row->force_x_middle = calibration_function(parameters_array->sensor_middleMiddle[0][0],parameters_array->sensor_middleMiddle[1][0],parameters_array->sensor_middleMiddle[2][0],parameters_array->sensor_middleMiddle[3][0],parameters_array->sensor_middleMiddle[4][0],parameters_array->sensor_middleMiddle[5][0],parameters_array->sensor_middleMiddle[6][0],parameters_array->sensor_middleMiddle[7][0],parameters_array->sensor_middleMiddle[8][0],parameters_array->sensor_middleMiddle[9][0],parameters_array->sensor_middleMiddle[10][0],
															  parameters_array->sensor_middleMiddle[11][0],parameters_array->sensor_middleMiddle[12][0],parameters_array->sensor_middleMiddle[13][0],parameters_array->sensor_middleMiddle[14][0],parameters_array->sensor_middleMiddle[15][0],parameters_array->sensor_middleMiddle[16][0],parameters_array->sensor_middleMiddle[17][0],parameters_array->sensor_middleMiddle[18][0],parameters_array->sensor_middleMiddle[19][0],
														      sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
			sensor_row->force_y_middle = calibration_function(parameters_array->sensor_middleMiddle[0][1],parameters_array->sensor_middleMiddle[1][1],parameters_array->sensor_middleMiddle[2][1],parameters_array->sensor_middleMiddle[3][1],parameters_array->sensor_middleMiddle[4][1],parameters_array->sensor_middleMiddle[5][1],parameters_array->sensor_middleMiddle[6][1],parameters_array->sensor_middleMiddle[7][1],parameters_array->sensor_middleMiddle[8][1],parameters_array->sensor_middleMiddle[9][1],parameters_array->sensor_middleMiddle[10][1],
															  parameters_array->sensor_middleMiddle[11][1],parameters_array->sensor_middleMiddle[12][1],parameters_array->sensor_middleMiddle[13][1],parameters_array->sensor_middleMiddle[14][1],parameters_array->sensor_middleMiddle[15][1],parameters_array->sensor_middleMiddle[16][1],parameters_array->sensor_middleMiddle[17][1],parameters_array->sensor_middleMiddle[18][1],parameters_array->sensor_middleMiddle[19][1],
														      sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
			sensor_row->force_z_middle = calibration_function(parameters_array->sensor_middleMiddle[0][2],parameters_array->sensor_middleMiddle[1][2],parameters_array->sensor_middleMiddle[2][2],parameters_array->sensor_middleMiddle[3][2],parameters_array->sensor_middleMiddle[4][2],parameters_array->sensor_middleMiddle[5][2],parameters_array->sensor_middleMiddle[6][2],parameters_array->sensor_middleMiddle[7][2],parameters_array->sensor_middleMiddle[8][2],parameters_array->sensor_middleMiddle[9][2],parameters_array->sensor_middleMiddle[10][2],
															  parameters_array->sensor_middleMiddle[11][2],parameters_array->sensor_middleMiddle[12][2],parameters_array->sensor_middleMiddle[13][2],parameters_array->sensor_middleMiddle[14][2],parameters_array->sensor_middleMiddle[15][2],parameters_array->sensor_middleMiddle[16][2],parameters_array->sensor_middleMiddle[17][2],parameters_array->sensor_middleMiddle[18][2],parameters_array->sensor_middleMiddle[19][2],
															  sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
			
			sensor_row->force_r_middle = (sensor_row->force_x_middle*sensor_row->force_x_middle) + (sensor_row->force_y_middle*sensor_row->force_y_middle);
			sensor_row->force_r_middle = sqrt(sensor_row->force_r_middle);
			
			// Bottom Sensor
			sensor_row->force_x_bottom = calibration_function(parameters_array->sensor_bottomMiddle[0][0],parameters_array->sensor_bottomMiddle[1][0],parameters_array->sensor_bottomMiddle[2][0],parameters_array->sensor_bottomMiddle[3][0],parameters_array->sensor_bottomMiddle[4][0],parameters_array->sensor_bottomMiddle[5][0],parameters_array->sensor_bottomMiddle[6][0],parameters_array->sensor_bottomMiddle[7][0],parameters_array->sensor_bottomMiddle[8][0],parameters_array->sensor_bottomMiddle[9][0],parameters_array->sensor_bottomMiddle[10][0],
															  parameters_array->sensor_bottomMiddle[11][0],parameters_array->sensor_bottomMiddle[12][0],parameters_array->sensor_bottomMiddle[13][0],parameters_array->sensor_bottomMiddle[14][0],parameters_array->sensor_bottomMiddle[15][0],parameters_array->sensor_bottomMiddle[16][0],parameters_array->sensor_bottomMiddle[17][0],parameters_array->sensor_bottomMiddle[18][0],parameters_array->sensor_bottomMiddle[19][0],
															  sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
			sensor_row->force_y_bottom = calibration_function(parameters_array->sensor_bottomMiddle[0][1],parameters_array->sensor_bottomMiddle[1][1],parameters_array->sensor_bottomMiddle[2][1],parameters_array->sensor_bottomMiddle[3][1],parameters_array->sensor_bottomMiddle[4][1],parameters_array->sensor_bottomMiddle[5][1],parameters_array->sensor_bottomMiddle[6][1],parameters_array->sensor_bottomMiddle[7][1],parameters_array->sensor_bottomMiddle[8][1],parameters_array->sensor_bottomMiddle[9][1],parameters_array->sensor_bottomMiddle[10][1],
															  parameters_array->sensor_bottomMiddle[11][1],parameters_array->sensor_bottomMiddle[12][1],parameters_array->sensor_bottomMiddle[13][1],parameters_array->sensor_bottomMiddle[14][1],parameters_array->sensor_bottomMiddle[15][1],parameters_array->sensor_bottomMiddle[16][1],parameters_array->sensor_bottomMiddle[17][1],parameters_array->sensor_bottomMiddle[18][1],parameters_array->sensor_bottomMiddle[19][1],
															  sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
			sensor_row->force_z_bottom = calibration_function(parameters_array->sensor_bottomMiddle[0][2],parameters_array->sensor_bottomMiddle[1][2],parameters_array->sensor_bottomMiddle[2][2],parameters_array->sensor_bottomMiddle[3][2],parameters_array->sensor_bottomMiddle[4][2],parameters_array->sensor_bottomMiddle[5][2],parameters_array->sensor_bottomMiddle[6][2],parameters_array->sensor_bottomMiddle[7][2],parameters_array->sensor_bottomMiddle[8][2],parameters_array->sensor_bottomMiddle[9][2],parameters_array->sensor_bottomMiddle[10][2],
															  parameters_array->sensor_bottomMiddle[11][2],parameters_array->sensor_bottomMiddle[12][2],parameters_array->sensor_bottomMiddle[13][2],parameters_array->sensor_bottomMiddle[14][2],parameters_array->sensor_bottomMiddle[15][2],parameters_array->sensor_bottomMiddle[16][2],parameters_array->sensor_bottomMiddle[17][2],parameters_array->sensor_bottomMiddle[18][2],parameters_array->sensor_bottomMiddle[19][2],
															  sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
			
			sensor_row->force_r_bottom = (sensor_row->force_x_bottom*sensor_row->force_x_bottom) + (sensor_row->force_y_bottom*sensor_row->force_y_bottom);
			sensor_row->force_r_bottom = sqrt(sensor_row->force_r_bottom);
		break;
	
		case 3: ; // Right Row
			// Top Sensor
			sensor_row->force_x_top = calibration_function(parameters_array->sensor_topRight[0][0],parameters_array->sensor_topRight[1][0],parameters_array->sensor_topRight[2][0],parameters_array->sensor_topRight[3][0],parameters_array->sensor_topRight[4][0],parameters_array->sensor_topRight[5][0],parameters_array->sensor_topRight[6][0],parameters_array->sensor_topRight[7][0],parameters_array->sensor_topRight[8][0],parameters_array->sensor_topRight[9][0],parameters_array->sensor_topRight[10][0],
														   parameters_array->sensor_topRight[11][0],parameters_array->sensor_topRight[12][0],parameters_array->sensor_topRight[13][0],parameters_array->sensor_topRight[14][0],parameters_array->sensor_topRight[15][0],parameters_array->sensor_topRight[16][0],parameters_array->sensor_topRight[17][0],parameters_array->sensor_topRight[18][0],parameters_array->sensor_topRight[19][0],
														   sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
			sensor_row->force_y_top = calibration_function(parameters_array->sensor_topRight[0][1],parameters_array->sensor_topRight[1][1],parameters_array->sensor_topRight[2][1],parameters_array->sensor_topRight[3][1],parameters_array->sensor_topRight[4][1],parameters_array->sensor_topRight[5][1],parameters_array->sensor_topRight[6][1],parameters_array->sensor_topRight[7][1],parameters_array->sensor_topRight[8][1],parameters_array->sensor_topRight[9][1],parameters_array->sensor_topRight[10][1],
														   parameters_array->sensor_topRight[11][1],parameters_array->sensor_topRight[12][1],parameters_array->sensor_topRight[13][1],parameters_array->sensor_topRight[14][1],parameters_array->sensor_topRight[15][1],parameters_array->sensor_topRight[16][1],parameters_array->sensor_topRight[17][1],parameters_array->sensor_topRight[18][1],parameters_array->sensor_topRight[19][1],
														   sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
			sensor_row->force_z_top = calibration_function(parameters_array->sensor_topRight[0][2],parameters_array->sensor_topRight[1][2],parameters_array->sensor_topRight[2][2],parameters_array->sensor_topRight[3][2],parameters_array->sensor_topRight[4][2],parameters_array->sensor_topRight[5][2],parameters_array->sensor_topRight[6][2],parameters_array->sensor_topRight[7][2],parameters_array->sensor_topRight[8][2],parameters_array->sensor_topRight[9][2],parameters_array->sensor_topRight[10][2],
														   parameters_array->sensor_topRight[11][2],parameters_array->sensor_topRight[12][2],parameters_array->sensor_topRight[13][2],parameters_array->sensor_topRight[14][2],parameters_array->sensor_topRight[15][2],parameters_array->sensor_topRight[16][2],parameters_array->sensor_topRight[17][2],parameters_array->sensor_topRight[18][2],parameters_array->sensor_topRight[19][2],
														   sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
	
			sensor_row->force_r_top = (sensor_row->force_x_top*sensor_row->force_x_top) + (sensor_row->force_y_top*sensor_row->force_y_top);
			sensor_row->force_r_top = sqrt(sensor_row->force_r_top);
	
			// Right Sensor
			sensor_row->force_x_middle = calibration_function(parameters_array->sensor_middleRight[0][0],parameters_array->sensor_middleRight[1][0],parameters_array->sensor_middleRight[2][0],parameters_array->sensor_middleRight[3][0],parameters_array->sensor_middleRight[4][0],parameters_array->sensor_middleRight[5][0],parameters_array->sensor_middleRight[6][0],parameters_array->sensor_middleRight[7][0],parameters_array->sensor_middleRight[8][0],parameters_array->sensor_middleRight[9][0],parameters_array->sensor_middleRight[10][0],
															  parameters_array->sensor_middleRight[11][0],parameters_array->sensor_middleRight[12][0],parameters_array->sensor_middleRight[13][0],parameters_array->sensor_middleRight[14][0],parameters_array->sensor_middleRight[15][0],parameters_array->sensor_middleRight[16][0],parameters_array->sensor_middleRight[17][0],parameters_array->sensor_middleRight[18][0],parameters_array->sensor_middleRight[19][0],
															  sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
			sensor_row->force_y_middle = calibration_function(parameters_array->sensor_middleRight[0][1],parameters_array->sensor_middleRight[1][1],parameters_array->sensor_middleRight[2][1],parameters_array->sensor_middleRight[3][1],parameters_array->sensor_middleRight[4][1],parameters_array->sensor_middleRight[5][1],parameters_array->sensor_middleRight[6][1],parameters_array->sensor_middleRight[7][1],parameters_array->sensor_middleRight[8][1],parameters_array->sensor_middleRight[9][1],parameters_array->sensor_middleRight[10][1],
															  parameters_array->sensor_middleRight[11][1],parameters_array->sensor_middleRight[12][1],parameters_array->sensor_middleRight[13][1],parameters_array->sensor_middleRight[14][1],parameters_array->sensor_middleRight[15][1],parameters_array->sensor_middleRight[16][1],parameters_array->sensor_middleRight[17][1],parameters_array->sensor_middleRight[18][1],parameters_array->sensor_middleRight[19][1],
															  sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
			sensor_row->force_z_middle = calibration_function(parameters_array->sensor_middleRight[0][2],parameters_array->sensor_middleRight[1][2],parameters_array->sensor_middleRight[2][2],parameters_array->sensor_middleRight[3][2],parameters_array->sensor_middleRight[4][2],parameters_array->sensor_middleRight[5][2],parameters_array->sensor_middleRight[6][2],parameters_array->sensor_middleRight[7][2],parameters_array->sensor_middleRight[8][2],parameters_array->sensor_middleRight[9][2],parameters_array->sensor_middleRight[10][2],
															  parameters_array->sensor_middleRight[11][2],parameters_array->sensor_middleRight[12][2],parameters_array->sensor_middleRight[13][2],parameters_array->sensor_middleRight[14][2],parameters_array->sensor_middleRight[15][2],parameters_array->sensor_middleRight[16][2],parameters_array->sensor_middleRight[17][2],parameters_array->sensor_middleRight[18][2],parameters_array->sensor_middleRight[19][2],
															  sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
			sensor_row->force_r_middle = (sensor_row->force_x_middle*sensor_row->force_x_middle) + (sensor_row->force_y_middle*sensor_row->force_y_middle);
			sensor_row->force_r_middle = sqrt(sensor_row->force_r_middle);
	
			// Bottom Sensor
			sensor_row->force_x_bottom = calibration_function(parameters_array->sensor_bottomRight[0][0],parameters_array->sensor_bottomRight[1][0],parameters_array->sensor_bottomRight[2][0],parameters_array->sensor_bottomRight[3][0],parameters_array->sensor_bottomRight[4][0],parameters_array->sensor_bottomRight[5][0],parameters_array->sensor_bottomRight[6][0],parameters_array->sensor_bottomRight[7][0],parameters_array->sensor_bottomRight[8][0],parameters_array->sensor_bottomRight[9][0],parameters_array->sensor_bottomRight[10][0],
															  parameters_array->sensor_bottomRight[11][0],parameters_array->sensor_bottomRight[12][0],parameters_array->sensor_bottomRight[13][0],parameters_array->sensor_bottomRight[14][0],parameters_array->sensor_bottomRight[15][0],parameters_array->sensor_bottomRight[16][0],parameters_array->sensor_bottomRight[17][0],parameters_array->sensor_bottomRight[18][0],parameters_array->sensor_bottomRight[19][0],
															  sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
			sensor_row->force_y_bottom = calibration_function(parameters_array->sensor_bottomRight[0][1],parameters_array->sensor_bottomRight[1][1],parameters_array->sensor_bottomRight[2][1],parameters_array->sensor_bottomRight[3][1],parameters_array->sensor_bottomRight[4][1],parameters_array->sensor_bottomRight[5][1],parameters_array->sensor_bottomRight[6][1],parameters_array->sensor_bottomRight[7][1],parameters_array->sensor_bottomRight[8][1],parameters_array->sensor_bottomRight[9][1],parameters_array->sensor_bottomRight[10][1],
															  parameters_array->sensor_bottomRight[11][1],parameters_array->sensor_bottomRight[12][1],parameters_array->sensor_bottomRight[13][1],parameters_array->sensor_bottomRight[14][1],parameters_array->sensor_bottomRight[15][1],parameters_array->sensor_bottomRight[16][1],parameters_array->sensor_bottomRight[17][1],parameters_array->sensor_bottomRight[18][1],parameters_array->sensor_bottomRight[19][1],
															  sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
			sensor_row->force_z_bottom = calibration_function(parameters_array->sensor_bottomRight[0][2],parameters_array->sensor_bottomRight[1][2],parameters_array->sensor_bottomRight[2][2],parameters_array->sensor_bottomRight[3][2],parameters_array->sensor_bottomRight[4][2],parameters_array->sensor_bottomRight[5][2],parameters_array->sensor_bottomRight[6][2],parameters_array->sensor_bottomRight[7][2],parameters_array->sensor_bottomRight[8][2],parameters_array->sensor_bottomRight[9][2],parameters_array->sensor_bottomRight[10][2],
															  parameters_array->sensor_bottomRight[11][2],parameters_array->sensor_bottomRight[12][2],parameters_array->sensor_bottomRight[13][2],parameters_array->sensor_bottomRight[14][2],parameters_array->sensor_bottomRight[15][2],parameters_array->sensor_bottomRight[16][2],parameters_array->sensor_bottomRight[17][2],parameters_array->sensor_bottomRight[18][2],parameters_array->sensor_bottomRight[19][2],
															  sensor_row->b_x_top, sensor_row->b_y_top, sensor_row->b_z_top);
	
			sensor_row->force_r_bottom = (sensor_row->force_x_bottom*sensor_row->force_x_bottom) + (sensor_row->force_y_bottom*sensor_row->force_y_bottom);
			sensor_row->force_r_bottom = sqrt(sensor_row->force_r_bottom);
			break;

	}
}