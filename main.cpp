#include "iostream"
#include "network.h"

int main(){
    Network net = initNetwork(Layer({InputNeuron(77.8), InputNeuron(635), InputNeuron(45.8), InputNeuron(3.7)}), 5);
    std::cout << net.getPrediction() << "\n";

    return 0;
}