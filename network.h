#pragma once

#include "defs.h"
#include <vector>

class Network{
    public:
        Network(Layer input,Layer output);
        Layer input;
        std::vector<Layer> hidden; //TODO
        Layer output;
        float getPrediction();
};

extern Network initNetwork(Layer input, int outputs);