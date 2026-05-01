#pragma once

#include "funcs.h"
#include <vector>
#include "layer.h"

class Network{
    public:
        Network(std::vector<Layer> layers);
        std::vector<Layer> layers;
        int getPrediction();
        void train(int correctIndex);
        void computeOutputDeltas(int correctIndex);
        void computeHiddenDeltas();
        void updateWeights();
        float learningRate;
};

extern Network initNetwork(Layer input, int outputs, int hidden, int hidden_neurons);
