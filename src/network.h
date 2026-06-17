#ifndef NETWORK_H
#define NETWORK_H

//#include "ext/list.h" not sure if this is needed yet
#include "ext/array.h"
#include "neuron.h"
#include <stddef.h>

DEFINE_ARR(Layer, Layer)
typedef Arr_Layer Network;

DEFINE_ARR(size_t, size_t)

Network Network_create(Layer input, Arr_size_t layerDesc);
void Network_free(Network *net);
int Network_forwardPass(Network net);
void Network_computeOutputDelta(Network net, int correctIndex);
void Network_computeHiddenDeltas(Network net);
void Network_correctVals(Network net, float learningRate);
int Network_train(Network net, int correctIndex, float learningRate);

#endif
