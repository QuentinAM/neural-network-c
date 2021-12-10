#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <err.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // To call srand(time(NULL));

#include "Utils/act_functions.h"
#include "Utils/act_functions_prime.h"

#include "neuron.h"
#include "layer.h"
#include "network.h"

/**
 * @brief Perform front propagation on the network
 *
 * @param network The network to perform front propagation on
 * @param input The input to the network
 */
void network_front_propagation(Network *network, int input[]);

/**
 * @brief Perform back propagation on the network
 *
 * @param network The network to perform back propagation on
 * @param expected The expected output of the network
 * @return double The error of the network
 */
double network_back_propagation(Network *network, double expected[]);

/**
 * @brief Perform gradient descent on the network
 *
 * @param network The network to perform gradient descent on
 * @param learningRate The learning rate to use
 */
void network_gradient_descent(Network *network, double learningRate);

/**
 * @brief Print the network
 *
 * @param network The network to print
 */
void network_print_weights(Network *network);

/**
 * @brief Calculate the error rate of the network
 *
 * @param network The network to calculate the error rate of
 * @return double The error rate of the network
 */
double network_average_error_rate(Network *network);

#endif