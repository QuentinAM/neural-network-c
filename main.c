#include "network.h"

// Create a network with 1 hidden layer of 15 neurons to train on XOR
// Here XOR is just an exemple of usage

int main(void)
{
    // Neural network of 1 hidden layer with 15 neurons
    // Using sigmoid activation function
    // Using sigmoid prime activation function
    Network_args args = {
        .n_inputs = 2,
        .n_outputs = 1,
        .n_hidden_layers = 1,
        .n_neurons_per_hidden_layer = 15,
        .n_act_f = SIGMOID,
        .n_act_f_prime = SIGMOID_PRIME,
    };

    // Create the network
    Network *network = network_create(&args);

    size_t n_epochs = 100;
    double n_learning_rate = 0.1;

    // Train the network on XOR
    network_train(network, n_epochs, n_learning_rate, INPUTS, OUTPUTS);

    // Test the network on XOR
    network_test(network, TEST_INPUTS, TEST_INPUTS);

    // Save the network
    network_save(network, "network.data");

    // Free the network
    network_free(network);
}
