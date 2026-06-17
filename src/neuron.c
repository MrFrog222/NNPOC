#include "neuron.h"
#include <math.h>

Neuron Neuron_create(Arr_float weights, float bias) {
  return (Neuron){weights, bias, 0, 0, 0};
}

Neuron InputNeuron_create(float output) {
  return (Neuron){(Arr_float){}, 0, 0, output, 0};
}

void rectifier(Layer layer) {
  for(size_t i = 0; i < layer.len; i++) {
    layer.arr[i].output = layer.arr[i].sum < 0 ? 0:layer.arr[i].sum;
  }
}

void Neuron_computeSum(Neuron *neuron, Layer prev) {
  neuron->sum = 0;
  for(size_t i = 0; i < prev.len; i++) neuron->sum += prev.arr[i].output * neuron->weights.arr[i];

  neuron->sum += neuron->bias;
}

int softmax(Layer output) {
  float sum = 0.0f;
  for(size_t i = 0; i < output.len; i++) sum += expf(output.arr[i].sum);

  int bestIdx = 0;
  float bestProb = 0.0f;

  for(size_t i = 0; i < output.len; i++) {
    output.arr[i].output = expf(output.arr[i].sum)/sum;
    if(output.arr[i].output <= bestProb) continue;
    bestProb = output.arr[i].output;
    bestIdx = i;
  }

  return bestIdx;
}
