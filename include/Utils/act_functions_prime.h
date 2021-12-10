#ifndef ACT_FUNCTION_PRIMES_H
#define ACT_FUNCTION_PRIMES_H

#include "layer.h"

typedef void (*n_act_f)(Layer *layer);

/**
 * @brief The ActFunctionPrimes class
 *
 */
enum ActFunctionPrime
{
    SIGMOID_PRIME,
    TANH_PRIME,
    RELU_PRIME,
    LEAKY_RELU_PRIME,
    LINEAR_PRIME,
    SOFTMAX_PRIME,
};

/**
 * @brief Get the prime function of the activation function
 *
 */
n_act_f get_act_function_prime(ActFunctionPrime act_function_prime);

/**
 * @brief Perform sigmoid prime operation on the given layer.
 *
 * @param layer The layer to perform the operation on.
 */
void sigmoid_prime(Layer *layer);

/**
 * @brief Perform tanh prime operation on the given layer.
 *
 * @param layer The layer to perform the operation on.
 */
void tanh_prime(Layer *layer);

/**
 * @brief Perform relu prime operation on the given layer.
 *
 * @param layer The layer to perform the operation on.
 */
void relu_prime(Layer *layer);

/**
 * @brief Perform leaky relu prime operation on the given layer.
 *
 * @param layer The layer to perform the operation on.
 */
void leaky_relu_prime(Layer *layer);

/**
 * @brief Perform softmax prime operation on the given layer.
 *
 * @param layer The layer to perform the operation on.
 */
void softmax_prime(Layer *layer);

/**
 * @brief Perform linear prime operation on the given layer.
 *
 * @param layer The layer to perform the operation on.
 */
void linear_prime(Layer *layer);

#endif