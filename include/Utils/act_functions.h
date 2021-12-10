#ifndef ACT_FUNCTION_H
#define ACT_FUNCTION_H

#include "layer.h"

/**
 * @brief The ActFunction class
 * 
 */
enum ActFunction {
    LINEAR,
    SIGMOID,
    TANH,
    RELU,
    SOFTMAX
};

/**
 * @brief Performs the sigmoid function on the given layer. 
 * 
 * @param Layer The layer to perform the activation function on. 
 */
void sigmoid(Layer *Layer);

/**
 * @brief Performs the softmax function on the given layer. 
 * 
 * @param Layer The layer to perform the activation function on.
 */
void softmax(Layer *Layer);

#endif