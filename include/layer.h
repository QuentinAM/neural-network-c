#ifndef LAYER_H
#define LAYER_H

#include "neuron.h"

typedef struct Layer
{
    unsigned int nbNeurons;
    Neuron *neurons;
} Layer;

/**
 * @brief
 *
 * @param sizeLayer
 * @param sizePreviousLayer
 * @return Layer
 */
Layer newLayer(unsigned int sizeLayer, unsigned int sizePreviousLayer);

/**
 * @brief
 *
 * @param layer
 */
void freeLayer(Layer *layer);

#endif