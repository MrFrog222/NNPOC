#pragma once
#include <vector>
#include "neuron.h"

class Layer{
    public:
        Layer(std::vector<Neuron> neurons);
        std::vector<Neuron> neurons;
};