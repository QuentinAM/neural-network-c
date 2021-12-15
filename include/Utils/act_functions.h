#ifndef ACT_FUNCTION_H
#define ACT_FUNCTION_H

/**
 * @brief The ActFunction class
 *
 */
enum ActFunction
{
    LINEAR,
    SIGMOID,
    TANH,
    RELU,
    SOFTMAX
};

#include "Utils/vector.h"
#include "network.h"

/**
 * @brief Get the activation function
 *
 */
void (*get_activation_f(enum ActFunction act_function))(Network *network);

/**
 * @brief Performs the sigmoid function on the given layer.
 *
 * @param Layer The layer to perform the activation function on.
 */
void sigmoid(Network *network);

/**
 * @brief Performs the softmax function on the given layer.
 *
 * @param Layer The layer to perform the activation function on.
 */
void softmax_layer(Layer *layer);

/**
 * @brief
 *
 * @param network
 */
void softmax(Network *network);

/**
 * @brief Performs the linear function on the given layer.
 *
 * @param Layer The layer to perform the activation function on.
 */
void linear(Network *network);

/**
 * @brief Performs the tanh function on the given layer.
 *
 * @param Layer The layer to perform the activation function on.
 */
void tanh_(Network *network);

/**
 * @brief Performs the relu function on the given layer.
 *
 * @param Layer The layer to perform the activation function on.
 */
void relu(Network *network);

#endif