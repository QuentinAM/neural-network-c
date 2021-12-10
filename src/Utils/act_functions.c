#include "Utils/act_functions.h"

n_act_f get_activation_f(ActFunction f)
{
    switch (f)
    {
    case LINEAR:
        return linear;
    case SIGMOID:
        return sigmoid;
    case TANH:
        return tanh;
    case RELU:
        return relu;
    case SOFTMAX:
        return softmax;
    default:
        return sigmoid;
    }
}

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

void linear(Layer *Layer)
{}

void tanh(Layer *Layer)
{}

void relu(Layer *Layer)
{}