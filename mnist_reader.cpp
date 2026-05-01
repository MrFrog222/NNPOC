#include "mnist_reader.h"
#include <cstdio>
#include <cstdlib>

uint32_t readBigEndian(std::ifstream &file) {
  uint8_t bytes[4];
  file.read(reinterpret_cast<char*>(bytes), 4);
  return (bytes[0] << 24) | (bytes[1] << 16) | (bytes[2] << 8) | bytes[3];
}

std::vector<Sample> loadMNIST(std::string &imagePath, std::string &labelPath) {
  std::ifstream imgFile(imagePath, std::ios::binary);
  std::ifstream labelFile(labelPath, std::ios::binary);

  if(!imgFile || !labelFile) {
    perror("Failed to open files!");
    exit(EXIT_FAILURE);
  }

  uint32_t magicImages = readBigEndian(imgFile);
  uint32_t numImages = readBigEndian(imgFile);
  uint32_t rows = readBigEndian(imgFile);
  uint32_t cols = readBigEndian(imgFile);

  uint32_t magicLabels = readBigEndian(labelFile);
  uint32_t numLabels = readBigEndian(labelFile);

  if(numImages != numLabels) {
    perror("Missmatched image and label files!");
    exit(EXIT_FAILURE);
  }

  std::vector<Sample> dataset(numImages);

  for(int i = 0; i < numImages; i++) {
    std::vector<float> pixels(rows*cols);

    for(int j = 0; j < rows * cols; j++) {
      uint8_t pixel;
      imgFile.read(reinterpret_cast<char*>(&pixel), 1);

      pixels.push_back(pixel/255.0f);
    }

    uint8_t label;
    labelFile.read(reinterpret_cast<char*>(&label), 1);

    dataset.push_back((Sample){pixels, label});
  }
  return dataset;
}
