#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H

#include "network.h"

#include <ctype.h> // To use toupper()
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * @brief
 *
 * @param network
 * @param path
 */
void saveWeights(Network *network, char *path);

/**
 * @brief
 *
 * @param network
 * @param path
 * @param verbose
 * @param gui
 */
void launchWeights(Network *network, char *path, int verbose, int gui);

#endif