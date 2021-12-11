#include "Utils/act_functions.h"

void (*get_activation_f(enum ActFunction f))(Network *network)
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

void sigmoid(Network *network)
{
    // Hiddens layer
    size_t nbLayers = network->nbLayers;
    size_t nbNeurons;
    // For each layer
    for (size_t i = 1; i < nbLayers; i++)
    {
        Layer prevLayer = network->layers[i - 1];
        Layer *layer = &(network->layers[i]);
        nbNeurons = layer->nbNeurons;

        // For each neuron of the actual layer
        for (size_t j = 0; j < nbNeurons; j++)
        {
            Neuron *neuron = &(layer->neurons[j]);
            double sum = 0.0;

            // Calcul new neuron value based on his weights and the value of
            // previous layer
            for (size_t k = 0; k <= prevLayer.nbNeurons; k++)
            {
                sum += neuron->weights[k] * prevLayer.neurons[k].value;
            }
            // sum += neuron->bias;
            layer->neurons[j].value = 1 / (1 + exp(-sum));
        }
    }
}

void softmax_layer(Layer *layer)
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

void softmax(Network *network)
{
    for (size_t i = 1; i < network->nbLayers; i++)
    {
        softmax_layer(&network->layers[i]);
    }
}

void linear(Network *network)
{}

void tanh_(Network *network)
{}

void relu(Network *network)
{}