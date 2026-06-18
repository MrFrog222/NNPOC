#include "mnist_reader.h"

uint32_t readBigEndian(FILE *file) {
  uint8_t buffer[4];
  fgets((char*)buffer, 4, file);
  return (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | buffer[3];
}

Arr_Sample loadMNIST(const char *imgPath, const char *labelPath) {
  FILE* img = fopen(imgPath, "rb");
  FILE* label = fopen(labelPath, "rb");

  if(!img || !label) {
    perror("Failed to find files!\n");
    exit(EXIT_FAILURE);
  }

  uint32_t magicImgs = readBigEndian(img);
  uint32_t numImgs = readBigEndian(img);
  uint32_t rows = readBigEndian(img);
  uint32_t cols = readBigEndian(img);

  uint32_t magicLabels = readBigEndian(label);
  uint32_t numLabels = readBigEndian(label);

  if(numImgs != numLabels) {
    perror("Missmatched image and label files!\n");
    exit(EXIT_FAILURE);
  }

  Arr_Sample dataset = (Arr_Sample){malloc(numImgs * sizeof(Sample)), numImgs};

  for(uint32_t i = 0; i < numImgs; i++) {
    Arr_float pixels = (Arr_float){malloc(rows * cols * sizeof(float)), rows * cols};

    for(size_t j = 0; j < pixels.len; j++) {
      uint8_t pixel;
      fgets((char*)&pixel, 1, img);

      pixels.arr[j] = pixel / 255.0f;
    }

    uint8_t lab;
    fgets((char*)&lab, 1, label);
    
    dataset.arr[i] = (Sample){pixels, lab};
  }

  return dataset;
}
