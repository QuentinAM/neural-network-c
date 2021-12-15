#include "Utils/vector.h"

void vector_print(double *vector, size_t size)
{
    printf("[");
    for (size_t i = 0; i < size; i++)
    {
        printf("%f ", vector[i]);
    }
    printf("]\n");
}

void vector_print_neuron(Neuron *vector, size_t size)
{
    printf("[");
    for (size_t i = 0; i < size; i++)
    {
        printf("%f ", vector[i].value);
    }
    printf("]\n");
}