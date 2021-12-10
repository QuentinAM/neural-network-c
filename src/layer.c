#include "layer.h"

Layer newLayer(unsigned int size, unsigned int sizePreviousLayer)
{
    Layer layer = { .nbNeurons = size, .neurons = NULL };

    // Allocate memory for neurons, calloc already put the + 1 for the \0
    layer.neurons = malloc((size + 1) * sizeof(struct Neuron));
    if (layer.neurons == NULL)
    {
        errx(EXIT_FAILURE, "Error while allocating memory");
    }

    // Create all the neurons depending on the size of the previous layer
    for (unsigned int i = 0; i < size; i++)
    {
        layer.neurons[i] = newNeuron(sizePreviousLayer);
    }

    return layer;
}

void freeLayer(Layer *layer)
{
    for (unsigned int i = 0; i < layer->nbNeurons; i++)
    {
        Neuron *neuron = &(layer->neurons[i]);
        freeNeuron(neuron);
    }
    free(layer->neurons);
}