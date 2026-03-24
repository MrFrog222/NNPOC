#include "funcs.h"

float softmax(float currentOutput, std::vector<Neuron> output) {
    float sum = 0;
    float maxVal = output[0].sum;

    for(Neuron neuron : output) {
        if(neuron.sum > maxVal) maxVal = neuron.sum;
    }

    for(Neuron neuron : output) {
        sum += std::exp(neuron.sum - maxVal);
    }

    return std::exp(currentOutput - maxVal)/sum;
}