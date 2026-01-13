#pragma once

#include "vector"

struct Neuron{
    std::vector<float> weights;
    float bias;
};

typedef std::vector<Neuron> Layer;

struct Network{
    std::vector<int> input;
    //std::vector<Layer> hidden;  //TODO: Only prototyping as of now
    Layer output;
};