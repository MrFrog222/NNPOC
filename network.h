#pragma once

#include "funcs.h"
#include <vector>
#include "layer.h"
#include <fstream>

class Network{
    public:
        Network(std::vector<Layer> layers);
        std::vector<Layer> layers;
        int getPrediction();
        void train(int correctIndex);
        void computeOutputDeltas(int correctIndex);
        void computeHiddenDeltas();
        void updateWeights(float learningRate);
        void train(int correctIndex, float learningRate);
};

extern Network initNetwork(Layer input, int outputs, int hidden, int hidden_neurons);
extern Network initNetworkFromFile(std::string filePath);
extern void NetworkToFile(std::string filePath, Network& net);
