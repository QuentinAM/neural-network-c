#include "Utils/matrix.h"

double **matrix_alloc(size_t n_rows, size_t n_cols)
{
    double **matrix = calloc(n_rows, sizeof(double *));
    if (matrix == NULL)
    {
        errx(EXIT_FAILURE, "matrix_alloc: calloc failed");
    }

    for (size_t i = 0; i < n_rows; i++)
    {
        matrix[i] = calloc(n_cols, sizeof(double));
        if (matrix[i] == NULL)
        {
            // Free already allocated matrix
            for (size_t j = 0; j < i; j++)
            {
                free(matrix[j]);
            }
            free(matrix);
           
            errx(EXIT_FAILURE, "matrix_alloc: calloc failed");
        }
    }

    return matrix;
}

void matrix_free(double **matrix, size_t n_rows)
{
    for (size_t i = 0; i < n_rows; i++)
        free(matrix[i]);
    free(matrix);
}