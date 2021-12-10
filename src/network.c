#include "network.h"

Network *network_create(size_t sizeInput, size_t sizeHidden, size_t nbHiddenLayers, size_t sizeOutput)
{
    Network *network = malloc(sizeof(Network));
    network->nbLayers = nbHiddenLayers + 2;
    network->sizeInput = sizeInput;
    network->sizeHidden = sizeHidden;
    network->sizeOutput = sizeOutput;

    // Allocate memory for all layers
    network.layers = malloc((network.nbLayers + 1) * sizeof(Layer));
    if (network.layers == NULL)
    {
        errx(EXIT_FAILURE, "Error while allocating memory");
    }

    // Create the input layer
    network.layers[0] = newLayer(sizeInput, 0);

    // Create all hidden layer with the nbNeurons of the previous one
    for (size_t i = 1; i < network.nbLayers - 1; i++)
    {
        network.layers[i] =
            newLayer(sizeHidden, network.layers[i - 1].nbNeurons);
    }

    // Create the ouput layer
    network.layers[network.nbLayers - 1] =
        newLayer(sizeOutput, network.layers[network.nbLayers - 2].nbNeurons);

    return network;
}

// Initialize neural network
void network_init(Network *network)
{
    srand(time(NULL));
    size_t nbLayers = network->nbLayers;
    size_t nbNeurons;

    for (size_t i = 0; i < nbLayers; i++)
    {
        Layer *layer = &(network->layers[i]);
        nbNeurons = layer->nbNeurons;
        for (size_t j = 0; j < nbNeurons; j++)
        {
            initNeuron(&(layer->neurons[j]));
        }
    }
}

void network_train(Network *network, size_t n_epochs, double n_learning_rate, void *input, void *output)
{
    // TODO : implement
}

void network_test(Network *network, void *input, void *output)
{
    // TODO : implement
}

void network_save(Network *network, char *filename)
{
    network_save_weights(network, filename);
}

Network *network_load(char *filename)
{
    Network *network = malloc(sizeof(Network));
    network_load_weights(network, filename);
    return network;
}

void network_free(Network *network)
{
    for (size_t i = 0; i < network->nbLayers; i++)
    {
        Layer *layer = &(network->layers[i]);
        freeLayer(layer);
    }
    free(network->layers);
    free(network);
}