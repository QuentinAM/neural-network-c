#include "neuron.h"

Neuron newNeuron(unsigned int nbWeights)
{
    Neuron neuron = {
        .nbWeights = nbWeights,
        .weights = NULL,
        .value = 0,
        .bias = 0,
        .delta = 0,
    };

    // Allocate memory for weights
    if (nbWeights != 0)
    {
        neuron.weights = malloc((nbWeights + 1) * sizeof(double));
        if (neuron.weights == NULL)
        {
            errx(EXIT_FAILURE, "Error while allocating memory");
        }
    }
    return neuron;
}

// Should only be called in initNetwork because of : srand ( time ( NULL));
void initNeuron(Neuron *neuron)
{
    unsigned int nbWeights = neuron->nbWeights;
    for (unsigned int i = 0; i < nbWeights; i++)
    {
        neuron->weights[i] = (double)rand() / RAND_MAX * 2.0 - 1.0;
    }

    neuron->bias = (double)rand() / RAND_MAX * 2.0 - 1.0;
}

void freeNeuron(Neuron *neuron)
{
    free(neuron->weights);
}
