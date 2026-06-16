#ifndef NETWORK_H
#define NETWORK_H

#include "ext/list.h"
#include "neuron.h"
#include <stddef.h>

DEFINE_LIST(Neuron, Neuron)
typedef List_Neuron Layer;

DEFINE_LIST(Layer, Layer)
typedef List_Layer Network;

DEFINE_LIST(size_t, size_t)

Network Network_create(Layer input, List_size_t layerDesc);
int Network_forwardPass();
void Network_computeOutputDelta(Network net, int correctIndex);
void Network_computeHiddenDeltas(Network net);
void Network_correctVals(Network net, float learningRate);
int Network_train(Network net, int correctIndex, float learningRate);

#endif
