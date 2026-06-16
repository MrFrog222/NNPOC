#include "neuron.h"

Neuron Neuron_create(Arr_float weights, float bias) {
  return (Neuron){weights, bias, 0, 0, 0};
}

Neuron InputNeuron_create(float output) {
  return (Neuron){(Arr_float){}, 0, 0, output, 0};
}

void softmax(Layer output) {

}
