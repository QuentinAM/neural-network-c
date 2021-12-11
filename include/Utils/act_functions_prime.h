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

#include "network.h"

/**
 * @brief Get the prime function of the activation function
 *
 */
double (*get_activation_f_prime(enum ActFunctionPrime act_function_prime)) (Network *network, double *expected);

/**
 * @brief Perform sigmoid prime operation on the given layer.
 *
 * @param layer The layer to perform the operation on.
 */
double sigmoid_prime(Network *network, double *expected);

/**
 * @brief Perform tanh prime operation on the given layer.
 *
 * @param layer The layer to perform the operation on.
 */
double tanh_prime(Network *network, double *expected);

/**
 * @brief Perform relu prime operation on the given layer.
 *
 * @param layer The layer to perform the operation on.
 */
double relu_prime(Network *network, double *expected);

/**
 * @brief Perform leaky relu prime operation on the given layer.
 *
 * @param layer The layer to perform the operation on.
 */
double leaky_relu_prime(Network *network, double *expected);

/**
 * @brief Perform softmax prime operation on the given layer.
 *
 * @param layer The layer to perform the operation on.
 */
double softmax_prime(Network *network, double *expected);

/**
 * @brief Perform linear prime operation on the given layer.
 *
 * @param layer The layer to perform the operation on.
 */
double linear_prime(Network *network, double *expected);

#endif