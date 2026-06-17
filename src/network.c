#include "network.h"
#include "ext/rand.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

Network Network_create(Layer input, Arr_size_t layerDesc) {
  srand(time(NULL));
  Network net = (Arr_Layer){malloc((layerDesc.len + 1) * sizeof(Layer)), layerDesc.len + 1};
  
  Neuron* inputCopy = malloc(sizeof(Neuron) * input.len);
  memcpy(inputCopy, input.arr, input.len * sizeof(Neuron));
  net.arr[0] = (Layer){inputCopy, input.len};

  for(size_t i = 1; i < net.len; i++) {
    Layer layer = (Layer){malloc(layerDesc.arr[i-1] * sizeof(Neuron)), layerDesc.arr[i-1]};

    for(size_t j = 0; j < layer.len; j++) {
      Neuron neuron = (Neuron){(Arr_float){malloc(sizeof(float) * net.arr[i-1].len), net.arr[i-1].len}, randFloat(-0.01, 0.01), 0, 0, 0};

      for(size_t k = 0; k < neuron.weights.len; k++) {
        neuron.weights.arr[k] = randFloat(-1.0f/sqrtf(net.arr[i - 1].len), 1.0f/sqrtf(net.arr[i-1].len));
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

int Network_forwardPass(Network net) {
  for(size_t i = 1; i < net.len; i++) {
    Layer *layer = &net.arr[i];

    for(size_t j = 0; j < layer->len; j++) {
      Neuron_computeSum(&layer->arr[j], net.arr[i - 1]);
      printf("%f\n", layer->arr[j].sum);
    }

    if(i == net.len - 1) return softmax(*layer);
    rectifier(*layer);
  }

  return -1;
}

int Network_train(Network net, int correctIndex, float learningRate) {
  int predict = Network_forwardPass(net);
  Network_computeOutputDeltas(net, correctIndex);
  Network_computeHiddenDeltas(net);
  Network_correctVals(net, learningRate);
  return predict;
}

void Network_computeOutputDeltas(Network net, int correctIndex) {
  for(size_t i = 0; i < net.arr[net.len - 1].len; i++) {
    Neuron *neuron = &net.arr[net.len - 1].arr[i];
    neuron->delta = neuron->output - (i == correctIndex ? 1:0);
  }
}

void Network_computeHiddenDeltas(Network net) {
  for(size_t i = net.len - 2; i > 0; i--) {
    Layer *layer = &net.arr[i];
    for(size_t j = 0; j < layer->len; j++) {
      Neuron *neuron = &layer->arr[j];
      float sum = 0.0f;

      for(size_t k = 0; k < net.arr[i + 1].len; k++) {
        Neuron *nextNeuron = &net.arr[i+1].arr[k];
        sum += nextNeuron->weights.arr[j] * nextNeuron->delta;
      }

      neuron->delta = sum * (neuron->sum < 0 ? 0:1); //sum * rectifier derivative
    }
  }
}
