#ifndef NEURON_H
#define NEURON_H

#include "ext/array.h"
#include "ext/array_types.h"

typedef struct Neuron {
  Arr_float weights;
  float bias;
  float sum;
  float output;
  float delta;
} Neuron;

DEFINE_ARR(Neuron, Neuron)
typedef Arr_Neuron Layer;

Neuron Neuron_create(Arr_float weights, float bias);
Neuron InputNeuron_create(float output); //only use this to create input neurons
void Neuron_computeSum(Neuron *neuron, Layer prev);

int softmax(Layer output);
void rectifier(Layer layer);

#endif
