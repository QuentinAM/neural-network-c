#ifndef NETWORK_H
#define NETWORK_H

#include "layer.h"

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
Network newNetwork(unsigned int sizeInput, unsigned int sizeHidden,
                   unsigned int nbHiddenLayers, unsigned int sizeOutput);

/**
 * @brief
 *
 * @param network
 */
void initNetwork(Network *network);


/**
 * @brief
 *
 * @param network
 */
void freeNetwork(Network *network);

#endif