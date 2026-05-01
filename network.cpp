#include "network.h"
#include "rand.h"
#include "math.h"

Network::Network(std::vector<Layer> layers) {
    this->layers = layers;
}

int Network::getPrediction() {
    for(int i = 1; i < layers.size(); i++) {
        bool output = i == layers.size() -1;
        for(Neuron &n: layers[i].neurons) {
            n.computeSum(layers[i-1].neurons);
            if(!output) n.output = std::max(0.0f, n.sum);
        }
        if(!output) continue;
        for(Neuron &n : layers[i].neurons) {
          n.output = softmax(n.sum, layers[i].neurons);
        }
    }

    float result = 0;
    int bestIndex = 0;
    for(int i = 0; i < layers[layers.size() - 1].neurons.size(); i++) {
        Neuron &n = layers[layers.size() -  1].neurons[i];
        if(n.output > result) {
          result = n.output;
          bestIndex = i;
        }
    }
    return bestIndex;
}

Network initNetwork(Layer input, int outputs, int hidden, int hidden_neurons) {
  std::vector<Layer> layers = {input};

  for(int i = 0; i < hidden; i++) {
    Layer hidden_layer({});
    for(int j = 0; j < hidden_neurons; j++) {
      std::vector<float> weights = {};
      for(int k = 0; k < layers[i].neurons.size(); k++) {
        weights.push_back(randFloat(-(1.0f/sqrt(layers[i].neurons.size())), 1.0f/sqrt(layers[i].neurons.size())));
      }
      hidden_layer.neurons.push_back(Neuron(weights, randFloat(-0.01, 0.01)));
    }
    layers.push_back(hidden_layer);
  }

  Layer output_layer({});
  for(int i = 0; i < outputs; i++) {
    std::vector<float> weights = {};
    for(int j = 0; j < layers[layers.size()-1].neurons.size(); j++) {
      weights.push_back(randFloat(-(1.0f/sqrt(layers[layers.size()-1].neurons.size())), 1.0f/sqrt(layers[layers.size()-1].neurons.size())));
    }
    output_layer.neurons.push_back(Neuron(weights, randFloat(-0.01, 0.01)));
  }
  layers.push_back(output_layer);
  return Network(layers);
}

void Network::computeOutputDeltas(int correctIndex) {
  for(int i = 0; i < layers[layers.size()-1].neurons.size(); i++) {
    float target = (i == correctIndex) ? 1.0f : 0.0f;
    layers[layers.size()-1].neurons[i].delta = layers[layers.size()-1].neurons[i].output - target;
  }
}

void Network::computeHiddenDeltas() {
  for(int i = layers.size() - 2; i > 0; i--) {
    for(int j = 0; j < layers[i].neurons.size(); j++) {
      float sum = 0;

      for(int k = 0; k < layers[i+1].neurons.size(); k++) {
        Neuron& n = layers[i+1].neurons[k];
        sum += n.weights[j] * n.delta;
      }

      float relu_deriv = (layers[i].neurons[j].sum > 0) ? 1.0f : 0.0f;

      layers[i].neurons[j].delta = sum * relu_deriv;
    }
  }
}

void Network::updateWeights(float learningRate) {
  for(int i = 1; i < layers.size(); i++) {
    for(int j = 0; j < layers[i].neurons.size(); j++) {
      Neuron& n = layers[i].neurons[j];
      for(int k = 0; k < layers[i-1].neurons.size(); k++) {
        float prev_output = layers[i-1].neurons[k].output;
        float gradient = prev_output * n.delta;

        n.weights[k] -= gradient * learningRate;
      }

      n.bias -= n.delta * learningRate;
    }
  }
}

void Network::train(int correctIndex, float learningRate) {
  getPrediction();
  computeOutputDeltas(correctIndex);
  computeHiddenDeltas();
  updateWeights(learningRate);
}