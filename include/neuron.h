#ifndef NEURON_H
#define NEURON_H

#include <stdlib.h>

typedef struct Neuron
{
    size_t nbWeights;
    double *weights;

    double value;
    double bias;
    double delta;
} Neuron;

/**
 * @brief createNeuron
 *
 * @param nbWeights number of weights
 * @return Neuron
 */
Neuron newNeuron(size_t nbWeights);

/**
 * @brief Initialize a neuron with random weights
 *
 * @param neuron
 */
void initNeuron(Neuron *neuron);

/**
 * @brief freeNeuron
 *
 * @param neuron
 */
void freeNeuron(Neuron *neuron);

#endif