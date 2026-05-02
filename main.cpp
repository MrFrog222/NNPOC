#include "iostream"
#include "layer.h"
#include "network.h"
#include "mnist_reader.h"
#include "neuron.h"
#include "rand.h"
#include <algorithm>

int main() {
#if 0
  float learningRate = 0.001f;
  int epochs = 10;

  std::vector<Sample> dataset = loadMNIST("train-images-idx3-ubyte", "train-labels-idx1-ubyte");
  Layer nullInput({});
  for(int i = 0; i < dataset[0].pixels.size(); i++) nullInput.neurons.push_back(InputNeuron(0.0f));
  Network net = initNetwork(nullInput, 10, 2, 32);

  for(int i = 0; i < epochs; i++) {
    int correct = 0;

    std::shuffle(dataset.begin(), dataset.end(), rand_gen);
    for(Sample& sample : dataset) {
      for(int j = 0; j < sample.pixels.size(); j++) {
        net.layers[0].neurons[j].output = sample.pixels[j];
      }

      if(net.train(sample.label, learningRate) == sample.label) correct++;
    }

    std::cout << "Epoch: " << i <<" | Accuracy: " << ((float)correct / dataset.size()) * 100.0f << "%\n";
  }
  NetworkToFile("net_save.txt", net);
#endif

  std::vector<Sample> datasetT = loadMNIST("t10k-images-idx3-ubyte", "t10k-labels-idx1-ubyte");
  Network netT = initNetworkFromFile("net_save.txt");

  int correct = 0;

  std::shuffle(datasetT.begin(), datasetT.end(), rand_gen);
  for(Sample& sample : datasetT) {
    for(int j = 0; j < sample.pixels.size(); j++) {
      netT.layers[0].neurons[j].output = sample.pixels[j];
    }

    if(netT.getPrediction() == sample.label) correct++;
  }

  std::cout << "Accuracy: " << ((float)correct/datasetT.size()) * 100.0f << "%\n";

  return 0;
}
