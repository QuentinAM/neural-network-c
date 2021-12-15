#ifndef ACT_FUNCTION_PRIMES_H
#define ACT_FUNCTION_PRIMES_H

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

#include "Utils/vector.h"
#include "network.h"

/**
 * @brief Get the prime function of the activation function
 *
 */
void (*get_activation_f_prime(enum ActFunctionPrime act_function_prime))(
    Network *network);

/**
 * @brief Perform sigmoid prime operation on the given layer.
 *
 * @param layer The layer to perform the operation on.
 */
void sigmoid_prime(Network *network);

/**
 * @brief Perform tanh prime operation on the given layer.
 *
 * @param layer The layer to perform the operation on.
 */
void tanh_prime(Network *network);

/**
 * @brief Perform relu prime operation on the given layer.
 *
 * @param layer The layer to perform the operation on.
 */
void relu_prime(Network *network);

/**
 * @brief Perform leaky relu prime operation on the given layer.
 *
 * @param layer The layer to perform the operation on.
 */
void leaky_relu_prime(Network *network);

/**
 * @brief Perform softmax prime operation on the given layer.
 *
 * @param layer The layer to perform the operation on.
 */
void softmax_prime(Network *network);

/**
 * @brief Perform linear prime operation on the given layer.
 *
 * @param layer The layer to perform the operation on.
 */
void linear_prime(Network *network);

#endif