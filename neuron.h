#pragma once

#include <vector>
#include "defs.h"

class Neuron{
    public:
        Neuron(std::vector<float> weights, float bias);
        std::vector<float> weights;
        float bias;
        float output;
        float sum;
        void computeSum(std::vector<Neuron> prev);
};

class InputNeuron: public Neuron{
    public:
        InputNeuron(float output): Neuron({}, 0){
            this->output = output;
        }
};