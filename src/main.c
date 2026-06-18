#include "network.h"
#include "ext/mnist_reader.h"
#include <stdio.h>

int main(int argc, char** argv) {
  if(argc < 2) return 1;
  if(strcmp(argv[1], "train")) {
    const char* imgFile = "datasets/train-images-idx3-ubyte";
    const char* labelFile = "datasets/train-labels-idx1-ubyte";
    Arr_Sample dataset = loadMNIST(imgFile, labelFile);


  }
}
