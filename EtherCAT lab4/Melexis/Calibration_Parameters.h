
#ifndef CALBRATION_PARAMETERS_H_INCLUDED
#define CALBRATION_PARAMETERS_H_INCLUDED
#include <stdint.h>

struct function_Parameters{
	//[c1-c20][x,y,z]
	float sensor_topLeft[20][3];
	float sensor_middleLeft[20][3];
	float sensor_bottomLeft[20][3];
	float sensor_topMiddle[20][3];
	float sensor_middleMiddle[20][3];
	float sensor_bottomMiddle[20][3];
	float sensor_topRight[20][3];
	float sensor_middleRight[20][3];
	float sensor_bottomRight[20][3];
	}; // function needs to be confirmed meaning if this is enough or if typedef is necessairy

void initialize_calibration_parameters(struct function_Parameters *parameters_array, uint8_t array_select);

#endif /* CALBRATION_PARAMETERS_H_INCLUDED*/