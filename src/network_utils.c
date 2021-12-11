#include "network_utils.h"

void network_front_propagation(Network *network, double *input)
{
    // First layer
    Layer *layer = &(network->layers[0]);
    for (unsigned int i = 0; i < layer->nbNeurons; i++)
    {
        layer->neurons[i].value = input[i];
    }

    network->act_f(network);
}

double network_back_propagation(Network *network, double *expected)
{
    double errorRate = network->act_f_prime(network, expected);
    return errorRate;
}

void network_gradient_descent(Network *network, double learningRate)
{
    // Gradient descent
    for (unsigned int i = network->nbLayers - 1; i >= 1; i--)
    {
        Layer *layer = &(network->layers[i]);
        Layer *previousLayer = &(network->layers[i - 1]);
        // For each neurons in the layer
        for (unsigned int j = 0; j < layer->nbNeurons; j++)
        {
            // For each neurons on the layer
            Neuron *neuron = &(layer->neurons[j]);
            for (unsigned int k = 0; k < previousLayer->nbNeurons; k++)
            {
                // For each weights on the neuron of the previous layer
                neuron->weights[k] += neuron->delta
                    * previousLayer->neurons[k].value * learningRate;

                neuron->bias += neuron->delta * previousLayer->neurons[k].value
                    * learningRate;
            }
        }
    }
}

size_t get_nb_data(char *file_name)
{
    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        errx(EXIT_FAILURE, "Error: file %s not found\n", file_name);
    }

    char *line = NULL;
    size_t len = 0;
    size_t nb_data = 0;

    // Calculate the number of data
    for (; fgets(line, &len, file) != NULL; nb_data++);

    fclose(file);
    return nb_data;
}

void network_create_data(char *data_path, size_t n_inputs, size_t n_outputs, double **input, double **expected)
{
    // Open data file
    FILE *file = fopen(data_path, "r");
    if (file == NULL)
    {
        errx(EXIT_FAILURE, "Error while opening data file");
    }

    char ch;
    char temp_str[100];
    size_t input_index = 0;
    size_t output_index = 0;
    size_t data_index = 0;

    bool is_input = true;
    while ((ch = getc(file)) != EOF)
    {
        if (ch == ' ')
            continue;

        if (ch == '\n')
        {
            data_index++;
        }

        if (ch == '/')
        {
            // Check for error
            if (!is_input)
            {
                errx(EXIT_FAILURE, "Data error : have a / in the expected section");
            }

            expected[data_index][output_index] = atof(temp_str);
            output_index++;

            // Reset string
            memset(temp_str, 0, 100);
        }
        else if (ch == '|')
        {
            if (is_input)
            {
                expected[data_index][output_index] = atof(temp_str);
                output_index++;


                // Reset string
                memset(temp_str, 0, 100);

                is_input = false;
            }
            else
            {
                
                input[data_index][input_index] = atof(temp_str);
                input_index++;

                // Reset string
                memset(temp_str, 0, 100);
            }
        }
        else
        {
            // Add digit to string
            strncat(temp_str, &ch, 1);
        }
    }

    // Don't forget to add the last output
    output[data_index][output_index] = atof(temp_str);

    if (input_index != n_inputs || output_index != n_outputs)
    {
        errx(EXIT_FAILURE, "Data error : the specified size of input and output is different than the data provided\n");
    }
    fclose(file);
}

void network_print_weights(Network *network)
{
    printf("\n######## ALL WEIGHTS ########\n");
    for (unsigned int i = 0; i < network->nbLayers; i++)
    {
        printf("###### LAYER %u ######\n", i);
        for (unsigned int j = 0; j < network->layers[i].nbNeurons; j++)
        {
            printf("#### NEURONS %u #### \n", j);
            for (unsigned int k = 0;
                 k < network->layers[i].neurons[j].nbWeights; k++)
            {
                printf("Weight %u : %f\n", k,
                       network->layers[i].neurons[j].weights[k]);
            }
        }
    }
}

double network_average_error_rate(Network *network)
{
    double average = 0.0;
    for (unsigned int i = 0; i < network->nbLayers; i++)
    {
        for (unsigned int j = 0; j < network->layers[i].nbNeurons; j++)
        {
            average += network->layers[i].neurons[j].delta;
        }
        average /= network->layers[i].nbNeurons;
    }

    return average * -1;
}