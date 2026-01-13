#include "network.h"
#include "rand.h"
#include "math.h"

Network initNetwork(std::vector<int> input, int outputs) {
    Layer output = {};

    for(int i = 0; i < outputs; i++) {
        std::vector<float> weights = {};
        for(int i = 0; i < input.size(); i++) {
            weights.push_back(randFloat(-(1/sqrt(input.size())), 1/sqrt(input.size())));
        }
        output.push_back(Neuron{weights, 0});
    }
    return Network{input, output};
}