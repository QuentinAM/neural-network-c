#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>

#include "neuron.h"

/**
 * @brief Prints a vector
 *
 * @param vector The vector to print
 * @param size The size of the vector
 */
void vector_print(double *vector, size_t size);

/**
 * @brief Prints a vector of neurons
 *
 * @param vector The vector to print
 * @param size The size of the vector
 */
void vector_print_neuron(Neuron *vector, size_t size);

#endif