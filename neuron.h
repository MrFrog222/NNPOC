#pragma once

#include <vector>
#include "defs.h"

class Neuron{
    public:
        Neuron(std::vector<float> weights, float bias);
        std::vector<float> weights;
        float bias;
        float output;
        void computeOutput(Layer prev);
};

class InputNeuron: public Neuron{
    public:
        InputNeuron(float output): Neuron({}, 0){
            this->output = output;
        }
};