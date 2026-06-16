#include "neuron.h"

Neuron Neuron_create(List_float weights, float bias) {
  return (Neuron){weights, bias, 0, 0, 0};
}

Neuron InputNeuron_create(float output) {
  return (Neuron){(List_float){}, 0, 0, output, 0};
}
