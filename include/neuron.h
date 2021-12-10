#ifndef NEURON_H
#define NEURON_H

typedef struct Neuron
{
    unsigned int nbWeights;
    double *weights;

    double value;
    double bias;
    double delta;
} Neuron;

/**
 * @brief
 *
 * @param nbWeights
 * @return Neuron
 */
Neuron newNeuron(unsigned int nbWeights);

/**
 * @brief
 *
 * @param neuron
 */
void initNeuron(Neuron *neuron);

/**
 * @brief
 *
 * @param neuron
 */
void freeNeuron(Neuron *neuron);

#endif