#ifndef ACT_FUNCTION_PRIMES_H
#define ACT_FUNCTION_PRIMES_H

#include "layer.h"

/**
 * @brief The ActFunctionPrimes class
 * 
 */
enum ActFunctionPrime {
    SIGMOID_PRIME,
    TANH_PRIME,
    RELU_PRIME,
    LEAKY_RELU_PRIME,
    LINEAR_PRIME,
    SOFTMAX_PRIME,
};

/**
 * @brief Perform sigmoid prime operation on the given layer. 
 * 
 * @param layer The layer to perform the operation on. 
 */
void sigmoid_prime(Layer *layer);

#endif