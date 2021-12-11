#include "Utils/act_functions_prime.h"

double (*get_activation_f_prime(enum ActFunctionPrime act_function_prime)) (Network *network, double *expected)
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

double sigmoid_prime(Network *network, double *expected)
{
    double errorRate = 0.0;
    double errorTemp = 0.0;

    unsigned int nbLayers = network->nbLayers;

    // Output layer
    Layer *outputLayer = &(network->layers[nbLayers - 1]);

    // NbNeurons of lastlayer and expected are equals
    for (unsigned int i = 0; i < outputLayer->nbNeurons; i++)
    {
        Neuron *neuron = &(outputLayer->neurons[i]);
        errorTemp = expected[i] - neuron->value;
        neuron->delta = errorTemp * (neuron->value * (1 - neuron->value));
        errorRate += (errorTemp * errorTemp);
    }

    // For all layer except the input
    for (unsigned int i = nbLayers - 1; i >= 2; i--)
    {
        Layer layer = network->layers[i];
        Layer *previousLayer =
            &(network->layers[i - 1]); // Modify weights of this layer
        // For each neurons
        for (unsigned int j = 0; j < previousLayer->nbNeurons; j++)
        {
            errorTemp = 0.0;
            Neuron *neuron = &(previousLayer->neurons[j]);
            // Calculate error rate based on all neuron in the next layer and
            // all weights of the actual neuron
            for (unsigned int k = 0; k < layer.nbNeurons; k++)
            {
                errorTemp +=
                    layer.neurons[k].delta * layer.neurons[k].weights[j];
            }
            neuron->delta = errorTemp * (neuron->value * (1 - neuron->value));
        }
    }
    return errorRate;
}

double tanh_prime(Network *network, double *expected)
{}

double relu_prime(Network *network, double *expected)
{}

double leaky_relu_prime(Network *network, double *expected)
{}

double softmax_prime(Network *network, double *expected)
{}

double linear_prime(Network *network, double *expected)
{}