#include "iostream"
#include "network.h"

int main(){
    Network net = initNetwork(Layer({InputNeuron(0.77), InputNeuron(0.12), InputNeuron(0.45), InputNeuron(0.03)}), 5, 2, 32);
    std::cout << net.getPrediction() << "\n";

    return 0;
}
