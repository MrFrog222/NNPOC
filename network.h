#pragma once

#include "funcs.h"
#include <vector>
#include "layer.h"

class Network{
    public:
        Network(std::vector<Layer> layers);
        std::vector<Layer> layers; //TODO
        int getPrediction();
};

extern Network initNetwork(Layer input, int outputs);