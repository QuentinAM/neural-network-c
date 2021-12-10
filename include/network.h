#ifndef NETWORK_H
#define NETWORK_H

#include "layer.h"
#include "Utils/save_load.h"

typedef struct Network
{
    size_t nbLayers;
    size_t sizeInput;
    size_t sizeHidden;
    size_t sizeOutput;
    Layer *layers;
} Network;

/**
 * @brief Create a new network
 *
 * @param sizeInput size of the input layer
 * @param sizeHidden size of the hidden layer
 * @param nbHiddenLayers number of hidden layers
 * @param sizeOutput size of the output layer
 * @return Network
 */
Network *network_create(size_t sizeInput, size_t sizeHidden, size_t nbHiddenLayers, size_t sizeOutput);

/**
 * @brief Initialize a network
 *
 * @param network the network to be initialized
 */
void network_init(Network *network);

/**
 * @brief Train a network
 * 
 * @param network the network to be trained
 * @param n_epochs  number of epochs
 * @param n_learning_rate learning rate
 * @param input input data
 * @param output output data
 */
// TODO : Change the void * properly
void network_train(Network *network, size_t n_epochs, double n_learning_rate, void *input, void *output);

/**
 * @brief Predict the output of a network
 * 
 * @param network the network to be used
 * @param input input data
 * @param output output data
 */
// TODO : Change the void * properly
void network_test(Network *network, void *input, void *output);

/**
 * @brief Save a network
 *
 * @param network the network to be saved
 * @param input input data
 * @param output output data
 */
void network_save(Network *network, char *filename);

/**
 * @brief Load a network
 * 
 * @param filename the file to be loaded
 * @return Network* the loaded network
 */
Network *network_load(char *filename);

/**
 * @brief Free a network
 *
 * @param network the network to be free
 */
void network_free(Network *network);

#endif