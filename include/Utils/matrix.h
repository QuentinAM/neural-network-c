#ifndef MATRIX_H
#define MATRIX_H

#include <err.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief
 *
 * @param n_rows
 * @param n_cols
 * @return double**
 */
double **matrix_alloc(size_t n_rows, size_t n_cols);

/**
 * @brief Free a matrix
 *
 * @param matrix The matrix to free
 * @param n_rows The number of rows in the matrix
 */
void matrix_free(double **matrix, size_t n_rows);

/**
 * @brief Print a matrix
 *
 * @param matrix The matrix to print
 * @param n_rows The number of rows in the matrix
 * @param n_cols The number of columns in the matrix
 */
void matrix_print(double **matrix, size_t n_rows, size_t n_cols);

#endif