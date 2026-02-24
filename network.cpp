#include "network.h"
#include "rand.h"
#include "math.h"

Network::Network(Layer input, Layer output) {
    this->input = input;
    this->output = output;
}

float Network::getPrediction() {
    if(this->hidden.size() == 0) {
        
    }
}

Network initNetwork(Layer input, int outputs) {
    Layer output = {};

    for(int i = 0; i < outputs; i++) {
        std::vector<float> weights = {};
        for(int i = 0; i < input.size(); i++) {
            weights.push_back(randFloat(-(1/sqrt(input.size())), 1/sqrt(input.size())));
        }
        output.push_back(Neuron(weights, 0/*Temporary Value assuming no hidden Layers*/));
    }
    return Network(input, output);
}