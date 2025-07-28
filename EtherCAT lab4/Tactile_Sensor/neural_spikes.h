#ifndef NEURAL_SPIKES_H_INCLUDED
#define NEURAL_SPIKES_H_INCLUDED

#include <Melexis/SensorArray.h>


typedef struct fneuron_t{
	float a, b, c, d;
	float potential, recovery, cell_current;
	float timestep_neuron;
	float normal_force, shear_force;
	float normal_force_past, shear_force_past;
	float beta, k_s, k_d;
	float theta, r_s, r_d;
	float timestep_force; // depending on force sensor example 250 HZ results in 4 ms
} fneuron_t;

typedef struct neuron_pair{
	struct fneuron_t neuron_normal;
	struct fneuron_t neuron_shear;
	}neuron_pair;
	
typedef struct neuronRow_Values{
	float neuron_top_normal;
	float neuron_top_shear;
	float neuron_middle_normal;
	float neuron_middle_shear;
	float neuron_bottom_normal;
	float neuron_bottom_shear;
	}neuronRow_Values;


void RS(struct fneuron_t *neuron);
void force_parameters(struct fneuron_t *neuron);
void calc_current_normal_force(struct fneuron_t *neuron, float force_z);
void calc_current_shear_force(struct fneuron_t *neuron,float force_r);
void step_f(struct fneuron_t *neuron, float synapse, float ms);
void neuron_init_row(struct neuron_pair *neuron_pair_top, struct neuron_pair *neuron_pair_middle, struct neuron_pair *neuron_pair_bottom);
void neuron_init_array(struct neuron_pair *neuron_pair_1, struct neuron_pair *neuron_pair_2, struct neuron_pair *neuron_pair_3, struct neuron_pair *neuron_pair_4, struct neuron_pair *neuron_pair_5, struct neuron_pair *neuron_pair_6, struct neuron_pair *neuron_pair_7, struct neuron_pair *neuron_pair_8, struct neuron_pair *neuron_pair_9);
//void neuron_init(struct fneuron_t *neuron1_normal, struct fneuron_t *neuron1_shear, struct fneuron_t *neuron2_normal, struct fneuron_t *neuron2_shear, struct fneuron_t *neuron3_normal, struct fneuron_t *neuron3_shear);
void neuron_calc_row(struct sensorRow_Values *sensor_row, struct neuron_pair *neuron_pair_top, struct neuron_pair *neuron_pair_middle,struct neuron_pair *neuron_pair_bottom);
//void neuron_calc(struct sensorRow_Values *sensor_row, struct fneuron_t *neuron1_normal, struct fneuron_t *neuron1_shear, struct fneuron_t *neuron2_normal, struct fneuron_t *neuron2_shear, struct fneuron_t *neuron3_normal, struct fneuron_t *neuron3_shear);
void update_struct_values_neural(struct neuronRow_Values *neuron_row, struct neuron_pair *neuron_pair_top, struct neuron_pair *neuron_pair_middle, struct neuron_pair *neuron_pair_bottom);

#endif