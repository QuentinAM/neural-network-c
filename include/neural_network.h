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
 * @brief
 *
 * @param network
 * @param input
 */
void frontPropagation(Network *network, int input[]);

/**
 * @brief
 *
 * @param network
 * @param expected
 * @return double
 */
double backPropagation(Network *network, double expected[]);

/**
 * @brief
 *
 * @param network
 * @param learningRate
 */
void gradientDescent(Network *network, double learningRate);

/**
 * @brief
 *
 * @param network
 */
void printWeights(Network *network);

/**
 * @brief
 *
 * @param network
 * @return double
 */
double averageErrorRate(Network *network);

#endif