#ifndef LAYER_H
#define LAYER_H

#include "neuron.h"
#include <err.h>

typedef struct Layer
{
    size_t nbNeurons;
    Neuron *neurons;
} Layer;

/**
 * @brief Create a new layer
 *
 * @param sizeLayer The size of the layer
 * @param sizePreviousLayer The size of the previous layer
 * @return Layer The new layer
 */
Layer newLayer(size_t sizeLayer, size_t sizePreviousLayer);

/**
 * @brief Free the memory of a layer
 *
 * @param layer The layer to free
 */
void freeLayer(Layer *layer);

#endif