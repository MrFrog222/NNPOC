#pragma once

#include "vector"
#include "neuron.h"
#include <cmath>

extern float softmax(float currentOutput, std::vector<Neuron> output);