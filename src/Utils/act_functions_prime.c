#include "Utils/act_functions_prime.h"

void (*get_activation_f_prime(enum ActFunctionPrime act_function_prime))(
    Network *network)
{
    switch (act_function_prime)
    {
    case SIGMOID_PRIME:
        return sigmoid_prime;
    case TANH_PRIME:
        return tanh_prime;
    case RELU_PRIME:
        return relu_prime;
    case LEAKY_RELU_PRIME:
        return leaky_relu_prime;
    case SOFTMAX_PRIME:
        return softmax_prime;
    case LINEAR_PRIME:
        return linear_prime;
    default:
        return sigmoid_prime;
    }
}

void sigmoid_prime(Network *network)
{
    double errorTemp = 0.0;

    size_t nbLayers = network->nbLayers;

    // For all layer except the input
    for (size_t i = nbLayers - 1; i >= 2; i--)
    {
        Layer layer = network->layers[i];
        Layer *previousLayer =
            &(network->layers[i - 1]); // Modify weights of this layer
        // For each neurons
        for (size_t j = 0; j < previousLayer->nbNeurons; j++)
        {
            errorTemp = 0.0;
            Neuron *neuron = &(previousLayer->neurons[j]);
            // Calculate error rate based on all neuron in the next layer and
            // all weights of the actual neuron
            for (size_t k = 0; k < layer.nbNeurons; k++)
            {
                errorTemp +=
                    layer.neurons[k].delta * layer.neurons[k].weights[j];
            }
            neuron->delta = errorTemp * (neuron->value * (1 - neuron->value));
        }
    }
}

void tanh_prime(Network *network)
{}

void relu_prime(Network *network)
{}

void leaky_relu_prime(Network *network)
{}

void softmax_prime(Network *network)
{}

void linear_prime(Network *network)
{}