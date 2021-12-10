#include "network_steps.h"

void network_front_propagation(Network *network, int input[])
{
    // First layer
    Layer *layer = &(network->layers[0]);
    for (unsigned int i = 0; i < layer->nbNeurons; i++)
    {
        layer->neurons[i].value = input[i];
    }

    // Hiddens layer
    unsigned int nbLayers = network->nbLayers;
    unsigned int nbNeurons;
    // For each layer
    for (unsigned int i = 1; i < nbLayers; i++)
    {
        Layer prevLayer = network->layers[i - 1];
        layer = &(network->layers[i]);
        nbNeurons = layer->nbNeurons;

        // For each neuron of the actual layer
        for (unsigned int j = 0; j < nbNeurons; j++)
        {
            Neuron *neuron = &(layer->neurons[j]);
            double sum = 0.0;

            // Calcul new neuron value based on his weights and the value of
            // previous layer
            for (unsigned int k = 0; k <= prevLayer.nbNeurons; k++)
            {
                sum += neuron->weights[k] * prevLayer.neurons[k].value;
            }
            // sum += neuron->bias;
            layer->neurons[j].value = sigmoid(sum);
        }
    }

    layer = &(network->layers[network->nbLayers - 1]);
    softmax(layer);
}

double network_back_propagation(Network *network, double expected[])
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
        neuron->delta = errorTemp * sigmoidPrime(neuron->value);
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
            neuron->delta = errorTemp * sigmoidPrime(neuron->value);
        }
    }
    return errorRate;
}

void network_gradient_descent(Network *network, double learningRate)
{
    // Gradient descent
    for (unsigned int i = network->nbLayers - 1; i >= 1; i--)
    {
        Layer *layer = &(network->layers[i]);
        Layer *previousLayer = &(network->layers[i - 1]);
        // For each neurons in the layer
        for (unsigned int j = 0; j < layer->nbNeurons; j++)
        {
            // For each neurons on the layer
            Neuron *neuron = &(layer->neurons[j]);
            for (unsigned int k = 0; k < previousLayer->nbNeurons; k++)
            {
                // For each weights on the neuron of the previous layer
                neuron->weights[k] += neuron->delta
                    * previousLayer->neurons[k].value * learningRate;

                neuron->bias += neuron->delta * previousLayer->neurons[k].value
                    * learningRate;
            }
        }
    }
}

// Apply softmax with cross entropy

void network_print_weights(Network *network)
{
    printf("\n######## ALL WEIGHTS ########\n");
    for (unsigned int i = 0; i < network->nbLayers; i++)
    {
        printf("###### LAYER %u ######\n", i);
        for (unsigned int j = 0; j < network->layers[i].nbNeurons; j++)
        {
            printf("#### NEURONS %u #### \n", j);
            for (unsigned int k = 0;
                 k < network->layers[i].neurons[j].nbWeights; k++)
            {
                printf("Weight %u : %f\n", k,
                       network->layers[i].neurons[j].weights[k]);
            }
        }
    }
}

double network_average_error_rate(Network *network)
{
    double average = 0.0;
    for (unsigned int i = 0; i < network->nbLayers; i++)
    {
        for (unsigned int j = 0; j < network->layers[i].nbNeurons; j++)
        {
            average += network->layers[i].neurons[j].delta;
        }
        average /= network->layers[i].nbNeurons;
    }

    return average * -1;
}