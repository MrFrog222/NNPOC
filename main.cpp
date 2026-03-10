#include "iostream"
#include "network.h"

int main(){
    Network net = initNetwork(Layer({InputNeuron(4.67), InputNeuron(6.35), InputNeuron(7.547), InputNeuron(3.7)}), 5);
    std::cout << net.getPrediction() << "\n";

    return 0;
}