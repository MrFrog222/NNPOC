#pragma once

#include <vector>

class Neuron{
    public:
        Neuron(std::vector<float> weights, float bias);
        std::vector<float> weights;
        float bias;
        float output;
        float sum;
        float delta;
        void computeSum(std::vector<Neuron> prev);
};

class InputNeuron: public Neuron{
    public:
        InputNeuron(float output): Neuron({}, 0){
            this->output = output;
        }
};
