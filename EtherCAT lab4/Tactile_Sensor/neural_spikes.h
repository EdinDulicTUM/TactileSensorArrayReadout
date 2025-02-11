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
};


void RS(struct fneuron_t *neuron);
void force_parameters(struct fneuron_t *neuron);
void calc_current_normal_force(struct fneuron_t *neuron, float force_z);
void calc_current_shear_force(struct fneuron_t *neuron,float force_r);
void step_f(struct fneuron_t *neuron, float synapse, float ms);
void neuron_init(struct fneuron_t *neuron1_normal, struct fneuron_t *neuron1_shear, struct fneuron_t *neuron2_normal, struct fneuron_t *neuron2_shear, struct fneuron_t *neuron3_normal, struct fneuron_t *neuron3_shear);
void neuron_calc(struct sensorRow_Values *sensor_row, struct fneuron_t *neuron1_normal, struct fneuron_t *neuron1_shear, struct fneuron_t *neuron2_normal, struct fneuron_t *neuron2_shear, struct fneuron_t *neuron3_normal, struct fneuron_t *neuron3_shear);

#endif