#ifndef NEURON_H
#define NEURON_H

#include "ext/list.h"

DEFINE_LIST(float, float)

typedef struct Neuron {
  List_float weights;
  float bias;
  float sum;
  float output;
  float delta;
} Neuron;

Neuron Neuron_create(List_float weights, float bias);
Neuron InputNeuron_create(float output); //only use this to create input neurons

#endif
