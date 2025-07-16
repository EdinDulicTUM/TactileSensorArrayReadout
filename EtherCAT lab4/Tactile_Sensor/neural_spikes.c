#include "stdio.h"
#include "string.h"
#include "math.h"
#include <Tactile_Sensor/neural_spikes.h>

void RS(struct fneuron_t *neuron) {
	// create a "regular spiking" floating point neuron
	neuron->a = 0.02;
	neuron->b = 0.2;
	neuron->c = -65;
	neuron->d = 6;
	neuron->potential = neuron->recovery = 0;
	neuron->timestep_neuron = 1; // junan recommendation 0.05, bigger timesteps till 1.5 is fine (see paper) 
}

void force_parameters (struct fneuron_t *neuron) {
	// initiate parameters for normal and shear force
	// parameters normal force
	neuron->beta = 0;
	neuron->k_s	= 1.2; //0.0000003
	neuron->k_d = 0;//0.003
	neuron-> normal_force_past = 0; 
	// parameters shear force
	neuron->theta = 0;
	neuron->r_s = 4.8;
	neuron->r_d = 0;
	neuron-> shear_force_past = 0; 
	neuron->timestep_force = 10; 
}

void calc_current_normal_force(struct fneuron_t *neuron, float force_z){
	neuron->normal_force = force_z;
	neuron->cell_current = neuron->beta + (neuron->k_s * neuron->normal_force);
	neuron->normal_force_past = neuron->normal_force;
}

void calc_current_shear_force(struct fneuron_t *neuron,float force_r){//(fneuron_t *neuron, bool start, float force_x, float force_y
	
	neuron->shear_force = force_r;
	neuron->cell_current = neuron->theta + (neuron->r_s * neuron->shear_force);
	neuron->shear_force_past = neuron->shear_force;
	
}

void step_f(struct fneuron_t *neuron, float synapse, float ms) {
	// step a neuron through ms milliseconds with synapse input
	//   if you don't have a good reason to do otherwise, keep ms between 0.1
	//   and 1.0
	if (neuron->potential >= 30) {
		neuron->potential = neuron->c;
		neuron->recovery += neuron->d;
		return;
	}
	float v = neuron->potential;
	float u = neuron->recovery;
	neuron->potential = v + ms * (0.04 * v * v + 5 * v + 140 - u + synapse);
	if (neuron -> potential > 30) {
		neuron -> potential = 30;
	}
	neuron->recovery = u + ms * (neuron->a * (neuron->b * v - u));
	return;
}

/*
void neuron_init(struct fneuron_t *neuron1_normal, struct fneuron_t *neuron1_shear, struct fneuron_t *neuron2_normal, struct fneuron_t *neuron2_shear, struct fneuron_t *neuron3_normal, struct fneuron_t *neuron3_shear){
	
	RS(neuron1_normal);
	force_parameters(neuron1_normal);
	
	RS(neuron1_shear);
	force_parameters(neuron1_shear);
	
	
	RS(neuron2_normal);
	force_parameters(neuron2_normal);
	
	RS(neuron2_shear);
	force_parameters(neuron2_shear);
	
	
	RS(neuron3_normal);
	force_parameters(neuron3_normal);
	
	RS(neuron3_shear);
	force_parameters(neuron3_shear);
	
	//repeatition = (uint8_t) (neuron_middle_normal.timestep_force/neuron_middle_normal.timestep_neuron);
}
*/

void neuron_init_row(struct neuron_pair *neuron_pair_top, struct neuron_pair *neuron_pair_middle, struct neuron_pair *neuron_pair_bottom){
	
	RS(&neuron_pair_top->neuron_normal);
	force_parameters(&neuron_pair_top->neuron_normal);
	
	RS(&neuron_pair_top->neuron_shear);
	force_parameters(&neuron_pair_top->neuron_shear);
	
	
	RS(&neuron_pair_middle->neuron_normal);
	force_parameters(&neuron_pair_middle->neuron_normal);
	
	RS(&neuron_pair_middle->neuron_shear);
	force_parameters(&neuron_pair_middle->neuron_shear);
	
	
	RS(&neuron_pair_bottom->neuron_normal);
	force_parameters(&neuron_pair_bottom->neuron_normal);
	
	RS(&neuron_pair_bottom->neuron_shear);
	force_parameters(&neuron_pair_bottom->neuron_shear);
	
	//repeatition = (uint8_t) (neuron_middle_normal.timestep_force/neuron_middle_normal.timestep_neuron);
}

 void neuron_calc_row(struct sensorRow_Values *sensor_row, struct neuron_pair *neuron_pair_top, struct neuron_pair *neuron_pair_middle, struct neuron_pair *neuron_pair_bottom){
	 
	 uint8_t repeatition = (uint8_t) (neuron_pair_top->neuron_normal.timestep_force/neuron_pair_top->neuron_normal.timestep_neuron);
	 
	 calc_current_normal_force(&neuron_pair_top->neuron_normal,sensor_row->force_z_top);
	 calc_current_shear_force(&neuron_pair_top->neuron_shear,sensor_row->force_r_top);
	 calc_current_normal_force(&neuron_pair_middle->neuron_normal,sensor_row->force_z_middle);
	 calc_current_shear_force(&neuron_pair_middle->neuron_shear,sensor_row->force_r_middle);
	 calc_current_normal_force(&neuron_pair_bottom->neuron_normal,sensor_row->force_z_bottom);
	 calc_current_shear_force(&neuron_pair_bottom->neuron_shear,sensor_row->force_r_bottom);
	 
	 for(int i = 0; i<repeatition; i++){
		step_f(&neuron_pair_top->neuron_normal, neuron_pair_top->neuron_normal.cell_current,neuron_pair_top->neuron_normal.timestep_neuron);//neuron_pair_top->neuron_normal.timestep_neuron
		step_f(&neuron_pair_top->neuron_shear, neuron_pair_top->neuron_shear.cell_current, neuron_pair_top->neuron_shear.timestep_neuron);
		step_f(&neuron_pair_middle->neuron_normal, neuron_pair_middle->neuron_normal.cell_current, neuron_pair_middle->neuron_normal.timestep_neuron);
		step_f(&neuron_pair_middle->neuron_shear, neuron_pair_middle->neuron_shear.cell_current, neuron_pair_middle->neuron_shear.timestep_neuron);
		step_f(&neuron_pair_bottom->neuron_normal, neuron_pair_bottom->neuron_normal.cell_current, neuron_pair_bottom->neuron_normal.timestep_neuron);
		step_f(&neuron_pair_bottom->neuron_shear, neuron_pair_bottom->neuron_shear.cell_current, neuron_pair_bottom->neuron_shear.timestep_neuron);
	 }
}
 
 
 
/*
void neuron_calc(struct sensorRow_Values *sensor_row, struct fneuron_t *neuron1_normal, struct fneuron_t *neuron1_shear, struct fneuron_t *neuron2_normal, struct fneuron_t *neuron2_shear, struct fneuron_t *neuron3_normal, struct fneuron_t *neuron3_shear){
	
	calc_current_normal_force(neuron1_normal,sensor_row->force_z_top);
	calc_current_shear_force(neuron1_shear,sensor_row->force_r_top);
	step_f(neuron1_normal, neuron1_normal->cell_current, neuron1_normal->timestep_neuron);
	step_f(neuron1_shear, neuron1_shear->cell_current, neuron1_shear->timestep_neuron);
	
	calc_current_normal_force(neuron2_normal,sensor_row->force_z_middle);
	calc_current_shear_force(neuron2_shear,sensor_row->force_r_middle);
	step_f(neuron2_normal, neuron2_normal->cell_current, neuron2_normal->timestep_neuron);
	step_f(neuron2_shear, neuron2_shear->cell_current, neuron2_shear->timestep_neuron);
	
	calc_current_normal_force(neuron3_normal,sensor_row->force_z_bottom);
	calc_current_shear_force(neuron3_shear,sensor_row->force_r_bottom);
	step_f(neuron3_normal, neuron3_normal->cell_current, neuron3_normal->timestep_neuron);
	step_f(neuron3_shear, neuron3_shear->cell_current, neuron3_shear->timestep_neuron);
}
*/

void update_struct_values_neural(struct neuronRow_Values *neuron_row, struct neuron_pair *neuron_pair_top, struct neuron_pair *neuron_pair_middle, struct neuron_pair *neuron_pair_bottom){
	neuron_row->neuron_top_normal = neuron_pair_top->neuron_normal.potential;
	neuron_row->neuron_top_shear = neuron_pair_top->neuron_shear.potential;
	
	neuron_row->neuron_middle_normal = neuron_pair_middle->neuron_normal.potential;
	neuron_row->neuron_middle_shear = neuron_pair_middle->neuron_shear.potential;
	
	neuron_row->neuron_bottom_normal = neuron_pair_bottom->neuron_normal.potential;
	neuron_row->neuron_bottom_shear = neuron_pair_bottom->neuron_shear.potential;
}