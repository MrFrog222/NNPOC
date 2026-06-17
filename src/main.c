#include "network.h"
#include <stdio.h>

int main(int argc, char** argv) {
  Network net = Network_create((Layer){(Neuron[]){InputNeuron_create(0.5), InputNeuron_create(0.6)
      , InputNeuron_create(0.376), InputNeuron_create(0.275)}, 4}
      , (Arr_size_t){(size_t[]){32, 32, 5}, 3});

  printf("%d\n", Network_forwardPass(net));
}
