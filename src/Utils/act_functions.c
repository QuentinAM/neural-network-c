#include "Utils/act_functions.h"

void sigmoid(Layer *Layer)
{
    // TODO : Implement sigmoid activation function for a layer
    // 1 / (1 + exp(-x));
}


void softmax(Layer *Layer)
{
    double sum = 0.0;
    
    // Calculate the sum of all the values in the layer
    for (unsigned int i = 0; i < layer->nbNeurons; i++)
    {
        layer->neurons[i].value = exp(layer->neurons[i].value);
        sum += layer->neurons[i].value;
    }

    // Normalize the values
    for (unsigned int i = 0; i < layer->nbNeurons; i++)
    {
        layer->neurons[i].value = layer->neurons[i].value / sum;
    }
}