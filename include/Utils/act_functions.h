#ifndef ACT_FUNCTION_H
#define ACT_FUNCTION_H

#include "layer.h"

typedef void (*n_act_f)(Layer *layer);

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
n_act_f get_activation_f(ActFunction f);

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

/**
 * @brief Performs the linear function on the given layer.
 *
 * @param Layer The layer to perform the activation function on.
 */
void linear(Layer *Layer);

/**
 * @brief Performs the tanh function on the given layer.
 *
 * @param Layer The layer to perform the activation function on.
 */
void tanh(Layer *Layer);

/**
 * @brief Performs the relu function on the given layer.
 *
 * @param Layer The layer to perform the activation function on.
 */
void relu(Layer *Layer);

#endif