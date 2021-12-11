#include "network.h"
#include "Utils/act_functions.h"
#include "Utils/act_functions_prime.h"

Network *network_create(Network_args *args)
{
    printf("Creating network...\n");

    Network *network = malloc(sizeof(Network));
    network->nbLayers = args->n_hidden_layers + 2;
    network->sizeInput = args->n_inputs;
    network->sizeHidden = args->n_neurons_per_hidden_layer;
    network->sizeOutput = args->n_outputs;

    // Allocate memory for all layers
    network->layers = malloc((network->nbLayers + 1) * sizeof(Layer));
    if (network->layers == NULL)
    {
        errx(EXIT_FAILURE, "Error while allocating memory");
    }

    // Create the input layer
    network->layers[0] = newLayer(network->sizeInput, 0);

    // Create all hidden layer with the nbNeurons of the previous one
    for (size_t i = 1; i < network->nbLayers - 1; i++)
    {
        network->layers[i] =
            newLayer(network->sizeHidden, network->layers[i - 1].nbNeurons);
    }

    // Create the ouput layer
    network->layers[network->nbLayers - 1] =
        newLayer(network->sizeOutput, network->layers[network->nbLayers - 2].nbNeurons);

    // Get activation function
    network->act_f = get_activation_f(args->n_act_f);
    network->act_f_prime = get_activation_f_prime(args->n_act_f_prime);

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

void network_train(Network *network, size_t n_epochs, double n_learning_rate,
                   char *data)
{
    printf("Training network...\n");

    size_t nb_data = get_nb_data(data);

    printf("nb_data: %zu\n", nb_data);

    double **input = matrix_alloc(nb_data, network->sizeInput);
    double **output = matrix_alloc(nb_data, network->sizeOutput);

    // Load data
    network_create_data(data, network->sizeInput, network->sizeOutput, input, output);

    // Train the network
    for (size_t epoch = 0; epoch < n_epochs; epoch++)
    {
        // For each data
        for (size_t data = 0; data < nb_data; data++)
        {
            // Forward propagation
            network_front_propagation(network, input[data]);
            
            // Back propagation
            network_back_propagation(network, output[data]);
            
            // Update weights
            network_gradient_descent(network, n_learning_rate);
        }
    }

    // Free memory
    matrix_free(input, nb_data);
    matrix_free(output, nb_data);
}

void network_test(Network *network, char *data)
{
    printf("Testing network...\n");

    size_t nb_data = get_nb_data(data);

    // Allocate memory for test data
    double **input = matrix_alloc(nb_data, network->sizeInput);

    for (size_t data = 0; data < nb_data; data++)
    {
        printf("Data %zu\n", data);
        printf("Input : ");
        for (size_t i = 0; i < network->sizeInput; i++)
        {
            printf("%f ", input[data][i]);
        }
        printf("\n");

        // Forward propagation
        network_front_propagation(network, input[data]);

        // Print output
        printf("Output : ");
        for (size_t i = 0; i < network->sizeOutput; i++)
        {
            printf("%f ", network->layers[network->nbLayers - 1].neurons[i].value);
        }
        printf("\n");
    }

    // Free memory
    matrix_free(input, nb_data);
}

void network_save(Network *network, char *filename)
{
    printf("Saving network...\n");

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
    printf("Freeing network...\n");

    for (size_t i = 0; i < network->nbLayers; i++)
    {
        Layer *layer = &(network->layers[i]);
        freeLayer(layer);
    }
    free(network->layers);
    free(network);
}