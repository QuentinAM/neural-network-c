#include "Utils/act_functions_prime.h"

n_act_f get_act_function_prime(ActFunctionPrime act_function_prime)
{
    switch (act_function_prime)
    {
    case SIGMOID_PRIME:
        return sigmoid_prime;
    case TANH_PRIME:
        return tanh_prime;
    case RELU_PRIME:
        return relu_prime;
    case LEAKY_RELU_PRIME:
        return leaky_relu_prime;
    case SOFTMAX_PRIME:
        return softmax_prime;
    case LINEAR_PRIME:
        return linear_prime;
    default:
        return sigmoid_prime;
    }
}

void sigmoid_prime(Layer *layer)
{
    // TODO: Implement sigmoid prime for a layer
    // sigmoid(x) * (1 - sigmoid(x));
}

void tanh_prime(Layer *layer)
{}

void relu_prime(Layer *layer)
{}

void leaky_relu_prime(Layer *layer)
{}

void softmax_prime(Layer *layer)
{}

void linear_prime(Layer *layer)
{}