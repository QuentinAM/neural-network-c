#ifndef ACT_FUNCTION_H
#define ACT_FUNCTION_H

#include "network.h"

typedef void (*n_act_f)(Network *network) n_act_f;

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

/**
 * @brief Get the activation function
 *
 */
n_act_f get_activation_f(enum ActFunction f);

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
void tanh(Network *network);

/**
 * @brief Performs the relu function on the given layer.
 *
 * @param Layer The layer to perform the activation function on.
 */
void relu(Network *network);

#endif