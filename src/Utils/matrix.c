#include "Utils/matrix.h"

double **matrix_alloc(size_t n_rows, size_t n_cols)
{
    double **matrix = calloc(n_rows + 1, sizeof(double *));
    if (matrix == NULL)
    {
        errx(EXIT_FAILURE, "matrix_alloc: calloc failed");
    }

    for (size_t i = 0; i < n_rows; i++)
    {
        matrix[i] = calloc(n_cols + 1, sizeof(double));
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

void matrix_print(double **matrix, size_t n_rows, size_t n_cols)
{
    printf("[\n");
    for (size_t i = 0; i < n_rows; i++)
    {
        printf("\t[");
        for (size_t j = 0; j < n_cols; j++)
        {
            printf("%f ", matrix[i][j]);
        }
        printf("]\n");
    }
    printf("]\n");
}