# 💻 Neural network

Working on neural network libs in C

## 📈 Advantages

- You'll be able to use the same code for different types of neural networks
- You'll be able to modify the code to fit your needs

## ⚙️ [Usage](https://github.com/QuentinAM/neural-network-c/blob/main/src/main.c) (expectation)

```c
#include "network.h"

// Create a network with 1 hidden layer of 15 neurons to train on XOR
// Here XOR is just an exemple of usage

int main(void)
{
    // Neural network of 1 hidden layer with 15 neurons
    // Using sigmoid activation function
    // Using sigmoid prime activation function
    Network_args args = { .n_inputs = 2,
                          .n_outputs = 1,
                          .n_hidden_layers = 1,
                          .n_neurons_per_hidden_layer = 15,
                          .n_act_f = SIGMOID,
                          .n_act_f_prime = SIGMOID_PRIME };

    // Create the network
    Network *network = network_create(&args);

    size_t n_epochs = 10000;
    double n_learning_rate = 0.01;

    // Train the network on XOR
    network_train(network, n_epochs, n_learning_rate, "xor_data.txt");

    // Test the network on XOR
    network_test(network, "xor_test.txt");

    // Save the network
    network_save(network, "network.data");

    // Free the network
    network_free(network);
}
```

## 📖 Documentation
The code will be fully documented in the headers (.h) file in the include folder.

# ⚖️ LICENSE

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
