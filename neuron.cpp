#include "neuron.h"

Neuron::Neuron(std::vector<float> weights, float bias) {
    this->weights = weights;
    this->bias = bias;
}

void Neuron::computeOutput(Layer prev) {
    float net = 0;

    for(int i = 0; i < prev.size(); i++) {
        net += prev[i].output * this->weights[i];
    }

    net += this->bias;

    this->output = net;
}