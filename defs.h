#pragma once

#include "vector"
#include "neuron.h"
#include <cmath>

float softmax(float currentOutput, std::vector<Neuron> output) {
    float sum = 0;

    for(Neuron neuron : output) {
        sum += std::exp(neuron.sum);
    }

    return std::exp(currentOutput)/sum;
}