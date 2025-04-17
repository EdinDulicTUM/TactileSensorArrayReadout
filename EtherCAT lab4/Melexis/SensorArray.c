/*
 * SensorArray.c
 *
 * Created: 11.12.2024 18:02:12
 *  Author: dulic
 */ 
#include <Melexis/SensorArray.h>
#include <math.h>


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
	delay_ms(5);
	
	//bottom row middle
	initialize(hall_sensor_2);
	begin(hall_sensor_2,1,0,1,false, io);
	triggerInitialize(hall_sensor_2, io);
	delay_ms(5);
	
	//bottom row right
	initialize(hall_sensor_3);
	begin(hall_sensor_3,1,1,0,false, io);
	triggerInitialize(hall_sensor_3, io);
	delay_ms(5);
	
	//middle row left
	initialize(hall_sensor_4);
	begin(hall_sensor_4,2,0,0,false, io);
	triggerInitialize(hall_sensor_4, io);
	delay_ms(5);
	
	//middle row middle
	initialize(hall_sensor_5);
	begin(hall_sensor_5,2,0,1,false, io);
	triggerInitialize(hall_sensor_5, io);
	delay_ms(5);
	
	//middle row right
	initialize(hall_sensor_6);
	begin(hall_sensor_6,2,1,0,false, io);
	triggerInitialize(hall_sensor_6, io);
	delay_ms(5);
	
	//top row left
	initialize(hall_sensor_7);
	begin(hall_sensor_7,3,0,0,false, io);
	triggerInitialize(hall_sensor_7, io);
	delay_ms(5);
	
	//top row middle
	initialize(hall_sensor_8);
	begin(hall_sensor_8,3,0,1,false, io);
	triggerInitialize(hall_sensor_8, io);
	delay_ms(5);
	
	//top row right
	initialize(hall_sensor_9);
	begin(hall_sensor_9,3,1,0,false, io);
	triggerInitialize(hall_sensor_9, io);
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
		
		//Combine X and Y Axis Into Br
		sensor_row->b_r_top = (sensor_row->b_x_top*sensor_row->b_x_top) + (sensor_row->b_y_top*sensor_row->b_y_top);
		sensor_row->b_r_top = sqrt(sensor_row->b_r_top);

		sensor_row->b_r_middle = (sensor_row->b_x_middle*sensor_row->b_x_middle) + (sensor_row->b_y_middle*sensor_row->b_y_middle);
		sensor_row->b_r_middle = sqrt(sensor_row->b_r_middle);
		
		sensor_row->b_r_bottom = (sensor_row->b_x_bottom*sensor_row->b_x_bottom) + (sensor_row->b_y_bottom *sensor_row->b_y_bottom );
		sensor_row->b_r_bottom = sqrt(sensor_row->b_r_bottom);
		
		/*
		sensor_row->b_r_top = (hall_sensor_top->data.x*hall_sensor_top->data.x) + (hall_sensor_top->data.y*hall_sensor_top->data.y);
		sensor_row->b_r_top = sqrt(sensor_row->b_r_top);

		sensor_row->b_r_middle = (hall_sensor_middle->data.x*hall_sensor_middle->data.x) + (hall_sensor_middle->data.y*hall_sensor_middle->data.y);
		sensor_row->b_r_middle = sqrt(sensor_row->b_r_middle);
		
		sensor_row->b_r_bottom = (hall_sensor_bottom->data.x*hall_sensor_bottom->data.x) + (hall_sensor_bottom->data.y*hall_sensor_bottom->data.y);
		sensor_row->b_r_bottom = sqrt(sensor_row->b_r_bottom);
		*/
}


void mag_to_force(struct sensorRow_Values *sensor_row){
	
	sensor_row->force_x_top= 13.33 - (0.003288*sensor_row->b_x_top) + (0.003361*sensor_row->b_z_top) + (0.000000724*(sensor_row->b_x_top*sensor_row->b_x_top)) - (0.0000006201*(sensor_row->b_x_top*sensor_row->b_z_top)) + (0.0000002654*(sensor_row->b_z_top*sensor_row->b_z_top)) + (0.00000000004886*((sensor_row->b_x_top*sensor_row->b_x_top)*sensor_row->b_z_top)) - (0.0000000000242*(sensor_row->b_x_top*(sensor_row->b_z_top*sensor_row->b_z_top))) + (0.000000000006595*((sensor_row->b_z_top*sensor_row->b_z_top)*sensor_row->b_z_top));
	sensor_row->force_y_top= 2.824 - (0.0004832*sensor_row->b_y_top) + (0.001006*sensor_row->b_z_top) + (0.000000521*(sensor_row->b_y_top*sensor_row->b_y_top)) - (0.0000003988*(sensor_row->b_y_top*sensor_row->b_z_top)) + (0.000000135*(sensor_row->b_z_top*sensor_row->b_z_top)) + (0.00000000003199*((sensor_row->b_y_top*sensor_row->b_y_top)*sensor_row->b_z_top)) - (0.0000000000218*(sensor_row->b_y_top*(sensor_row->b_z_top*sensor_row->b_z_top))) + (0.000000000004829*((sensor_row->b_z_top*sensor_row->b_z_top)*sensor_row->b_z_top));
	sensor_row->force_z_top= 24.47 - (0.004608*sensor_row->b_r_top) + (0.006606*sensor_row->b_z_top) + (0.0000003998*(sensor_row->b_r_top*sensor_row->b_r_top)) - (0.0000006645*(sensor_row->b_r_top*sensor_row->b_z_top)) + (0.0000005293*(sensor_row->b_z_top*sensor_row->b_z_top)) + (0.000000000006865*((sensor_row->b_r_top*sensor_row->b_r_top)*sensor_row->b_z_top)) - (0.00000000002459*(sensor_row->b_r_top*(sensor_row->b_z_top*sensor_row->b_z_top))) + (0.0000000000106*((sensor_row->b_z_top*sensor_row->b_z_top)*sensor_row->b_z_top));
	sensor_row->force_r_top= (sensor_row->force_x_top*sensor_row->force_x_top) + (sensor_row->force_y_top*sensor_row->force_y_top);
	sensor_row->force_r_top = sqrt(sensor_row->force_r_top);
	
	sensor_row->force_x_middle= 1.411 - (0.0002827*sensor_row->b_x_middle) + (0.0003494*sensor_row->b_z_middle) + (0.0000001662*(sensor_row->b_x_middle*sensor_row->b_x_middle)) - (0.0000001945*(sensor_row->b_x_middle*sensor_row->b_z_middle)) + (0.00000003569*(sensor_row->b_z_middle*sensor_row->b_z_middle)) + (0.0000000000112*((sensor_row->b_x_middle*sensor_row->b_x_middle)*sensor_row->b_z_middle)) - (0.000000000009128*(sensor_row->b_x_middle*(sensor_row->b_z_middle*sensor_row->b_z_middle))) + (0.000000000001119*((sensor_row->b_z_middle*sensor_row->b_z_middle)*sensor_row->b_z_middle));
	sensor_row->force_y_middle= 7.812 - (0.004493*sensor_row->b_y_middle) + (0.002601*sensor_row->b_z_middle) - (0.0000001078*(sensor_row->b_y_middle*sensor_row->b_y_middle)) - (0.0000007358*(sensor_row->b_y_middle*sensor_row->b_z_middle)) + (0.0000002632*(sensor_row->b_z_middle*sensor_row->b_z_middle)) - (0.00000000001189*((sensor_row->b_y_middle*sensor_row->b_y_middle)*sensor_row->b_z_middle)) - (0.00000000002614*(sensor_row->b_y_middle*(sensor_row->b_z_middle*sensor_row->b_z_middle))) + (0.000000000007836*((sensor_row->b_z_middle*sensor_row->b_z_middle)*sensor_row->b_z_middle));
	sensor_row->force_z_middle= 14.21 - (0.005789*sensor_row->b_r_middle) + (0.004071*sensor_row->b_z_middle) + (0.0000005279*(sensor_row->b_r_middle*sensor_row->b_r_middle)) - (0.0000007658*(sensor_row->b_r_middle*sensor_row->b_z_middle)) + (0.0000003383*(sensor_row->b_z_middle*sensor_row->b_z_middle)) + (0.00000000001514*((sensor_row->b_r_middle*sensor_row->b_r_middle)*sensor_row->b_z_middle)) - (0.00000000002614*(sensor_row->b_r_middle*(sensor_row->b_z_middle*sensor_row->b_z_middle))) + (0.000000000006038*((sensor_row->b_z_middle*sensor_row->b_z_middle)*sensor_row->b_z_middle));
	sensor_row->force_r_middle= (sensor_row->force_x_middle*sensor_row->force_x_middle) + (sensor_row->force_y_middle*sensor_row->force_y_middle);
	sensor_row->force_r_middle = sqrt(sensor_row->force_r_middle);
	
	
	sensor_row->force_x_bottom= -10.33 - (0.003475*sensor_row->b_x_bottom) - (0.003007 *sensor_row->b_z_bottom) - (0.0000006456*(sensor_row->b_x_bottom*sensor_row->b_x_bottom)) - (0.0000007356*(sensor_row->b_x_bottom*sensor_row->b_z_bottom)) - (0.0000002724*(sensor_row->b_z_bottom*sensor_row->b_z_bottom)) - (0.00000000004405*((sensor_row->b_x_bottom*sensor_row->b_x_bottom)*sensor_row->b_z_bottom)) - (0.00000000003177*(sensor_row->b_x_bottom*(sensor_row->b_z_bottom*sensor_row->b_z_bottom))) - (0.00000000000747*((sensor_row->b_z_bottom*sensor_row->b_z_bottom)*sensor_row->b_z_bottom));
	sensor_row->force_y_bottom= -2.141 + (0.002644*sensor_row->b_y_bottom) - (0.000585*sensor_row->b_z_bottom) + (0.0000005642*(sensor_row->b_y_bottom*sensor_row->b_y_bottom)) + (0.0000001582*(sensor_row->b_y_bottom*sensor_row->b_z_bottom)) - (0.00000003274*(sensor_row->b_z_bottom*sensor_row->b_z_bottom)) + (0.00000000004031*((sensor_row->b_y_bottom*sensor_row->b_y_bottom)*sensor_row->b_z_bottom)) + (0.000000000000689*(sensor_row->b_y_bottom*(sensor_row->b_z_bottom*sensor_row->b_z_bottom))) - (0.0000000000005236*((sensor_row->b_z_bottom*sensor_row->b_z_bottom)*sensor_row->b_z_bottom));
	sensor_row->force_z_bottom= 25.61 - (0.005403*sensor_row->b_r_bottom) + (0.007253*sensor_row->b_z_bottom) + (0.000001078*(sensor_row->b_r_bottom*sensor_row->b_r_bottom)) - (0.0000006989*sensor_row->b_r_bottom*sensor_row->b_z_bottom) + (0.0000006109*(sensor_row->b_z_bottom*sensor_row->b_z_bottom)) + (0.00000000005541*(sensor_row->b_r_bottom*sensor_row->b_r_bottom)*sensor_row->b_z_bottom) - (0.00000000002099*sensor_row->b_r_bottom*(sensor_row->b_z_bottom*sensor_row->b_z_bottom)) + (0.00000000001312*(sensor_row->b_z_bottom*sensor_row->b_z_bottom)*sensor_row->b_z_bottom);
	sensor_row->force_r_bottom= (sensor_row->force_x_bottom*sensor_row->force_x_bottom) + (sensor_row->force_y_bottom*sensor_row->force_y_bottom);
	sensor_row->force_r_bottom = sqrt(sensor_row->force_r_bottom);
	
	/*
	sensor_row->force_z_top = 51.152 + (0.0068*sensor_row->b_r_top) + (0.0130*hall_sensor_top->data.z);
	sensor_row->force_r_top = 8.9701 + (0.0106*sensor_row->b_r_top) + (0.0026*hall_sensor_top->data.z);

	sensor_row->force_z_middle =-22.8835 + (0.0014*sensor_row->b_r_top) + (0.0017*hall_sensor_middle->data.z);
	sensor_row->force_r_middle =-10.1016 + (0.0031*sensor_row->b_r_top) + (-0.0014*hall_sensor_middle->data.z);
	
	sensor_row->force_z_bottom = 35.2728 + (-0.0130*sensor_row->b_r_top) + (0.0084*hall_sensor_bottom->data.z);
	sensor_row->force_r_bottom = 9.9403 + (-0.0075*sensor_row->b_r_top) + (0.0013*hall_sensor_bottom->data.z);
	*/
	
}