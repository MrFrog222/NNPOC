#include "network.h"
#include "ext/mnist_reader.h"
#include "neuron.h"
#include <stdio.h>
#include <stddef.h>

int main(int argc, char** argv) {
  if(argc < 2) return 1;
  if(strcmp(argv[1], "train")) {
    const char* imgFile = "datasets/train-images-idx3-ubyte";
    const char* labelFile = "datasets/train-labels-idx1-ubyte";
    Arr_Sample dataset = loadMNIST(imgFile, labelFile);

    Neuron firstBuf[dataset.arr[0].pixels.len];
    for(size_t i = 0; i < dataset.arr[0].pixels.len; i++) firstBuf[i] = InputNeuron_create(dataset.arr[0].pixels.arr[i]);
    Network net = Network_create((Layer){firstBuf, dataset.arr[0].pixels.len}, (Arr_size_t){(size_t[]){32, 32, 10}, 3});

    for(size_t i = 0; i < dataset.len; i++) {

    }
  }
}
