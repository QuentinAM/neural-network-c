#ifndef NETWORK_H
#define NETWORK_H

#include "layer.h"
#include "Utils/save_load.h"

typedef struct Network
{
    unsigned int nbLayers;
    unsigned int sizeInput;
    unsigned int sizeHidden;
    unsigned int sizeOutput;
    Layer *layers;
} Network;

/**
 * @brief
 *
 * @param sizeInput
 * @param sizeHidden
 * @param nbHiddenLayers
 * @param sizeOutput
 * @return Network
 */
Network *network_create(unsigned int sizeInput, unsigned int sizeHidden,
                   unsigned int nbHiddenLayers, unsigned int sizeOutput);

/**
 * @brief
 *
 * @param network
 */
void network_init(Network *network);

/**
 * @brief 
 * 
 * @param network 
 * @param n_epochs 
 * @param n_learning_rate 
 * @param input 
 * @param output 
 */
// TODO : Change the void * properly
void network_train(Network *network, size_t n_epochs, double n_learning_rate, void *input, void *output);

/**
 * @brief 
 * 
 * @param network 
 * @param input 
 * @param output 
 */
// TODO : Change the void * properly
void network_test(Network *network, void *input, void *output);

/**
 * @brief
 *
 * @param network
 * @param input
 * @param output
 */
void network_save(Network *network, char *filename);


/**
 * @brief
 *
 * @param network
 */
void network_free(Network *network);

#endif