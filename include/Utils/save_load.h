#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H

#include <ctype.h> // To use toupper()
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "network.h"

/**
 * @brief
 *
 * @param network
 * @param path
 */
void network_save_weights(Network *network, char *path);

/**
 * @brief
 *
 * @param network
 * @param path
 * @param verbose
 * @param gui
 */
void network_load_weights(Network *network, char *path, int verbose, int gui);

#endif