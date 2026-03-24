#include "network.h"
#include "rand.h"
#include "math.h"
#include <iostream>

Network::Network(std::vector<Layer> layers) {
    this->layers = layers;
}

int Network::getPrediction() {
    for(int i = 0; i < layers.size(); i++) {
        bool output = i == layers.size() -1;
        for(Neuron &n: layers[i].neurons) {
            n.computeSum(layers[i-1].neurons);
            if(!output) n.output = std::max(0.0f, n.sum);
            else n.output = softmax(n.sum, layers[i].neurons);
            std::cout << n.output << "op\n";
        }
    }

    float result = 0;
    for(Neuron n: layers[layers.size() - 1].neurons) {
        if(n.output > result) result = n.output;
    }
    return result;
}

Network initNetwork(Layer input, int outputs) {
    Layer output({});

    for(int i = 0; i < outputs; i++) {
        std::vector<float> weights = {};
        for(int i = 0; i < input.neurons.size(); i++) {
            weights.push_back(randFloat(-(1.0f/sqrt(input.neurons.size())), 1.0f/sqrt(input.neurons.size())));
        }
        output.neurons.push_back(Neuron(weights, 0/*Temporary Value assuming no hidden Layers*/));
    }
    return Network({input, output});
}