#include <criterion/criterion.h>
#include "network.h"

Test (xor, basic)
{
    // Neural network of 1 hidden layer with 15 neurons
    // Using sigmoid activation function
    // Using sigmoid prime activation function
    Network_args args = { .n_inputs = 2,
                          .n_outputs = 1,
                          .n_hidden_layers = 1,
                          .n_neurons_per_hidden_layer = 15,
                          .n_act_f = SIGMOID,
                          .n_act_f_prime = SIGMOID_PRIME };

    // Create the network
    Network *network = network_create(&args);

    size_t n_epochs = 100;
    double n_learning_rate = 0.1;

    // Train the network on XOR
    network_train(network, n_epochs, n_learning_rate, "xor_data.txt");
}