#include "network.h"
#include "ext/rand.h"
#include <math.h>

Network Network_create(Layer input, Arr_size_t layerDesc) {
  Network net = (Arr_Layer){malloc((layerDesc.len + 1) * sizeof(Layer)), layerDesc.len + 1};
  
  Neuron* inputCopy = malloc(sizeof(Neuron) * input.len);
  memcpy(inputCopy, input.arr, input.len * sizeof(Neuron));
  net.arr[0] = (Layer){inputCopy, input.len};

  for(size_t i = 1; i < net.len; i++) {
    Layer layer = (Layer){malloc(layerDesc.arr[i-1] * sizeof(Neuron)), layerDesc.arr[i-1]};

    for(size_t j = 0; j < layer.len; j++) {
      Neuron neuron = (Neuron){(Arr_float){malloc(sizeof(float) * net.arr[i-1].len), net.arr[i-1].len}, randFloat(-0.01, 0.01), 0, 0, 0};

      for(size_t k = 0; k < neuron.weights.len; k++) {
        neuron.weights.arr[i] = randFloat(-1.0f/sqrtf(layer.len), 1.0f/sqrtf(layer.len));
      }
      layer.arr[j] = neuron;
    }
    net.arr[i] = layer;
  }
  return net;
}

void Network_free(Network *net) {
  for(size_t i = 0; i < net->len; i++) {
    Layer *layer = &net->arr[i];

    for(size_t j = 0; j < net->arr[i].len; j++) {
      Neuron *neuron = &layer->arr[j];
      Arr_float_free(&neuron->weights);
    }
    Arr_Neuron_free(layer);
  }

  Arr_Layer_free(net);
}

int Network_forwardPass() {

}
