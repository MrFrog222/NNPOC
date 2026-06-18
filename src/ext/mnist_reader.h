#ifndef MNIST_READER_H
#define MNIST_READER_H

#include "array_types.h"
#include <stdint.h>
#include <stdio.h>

typedef struct Sample{
  Arr_float pixels;
  uint8_t label;
} Sample;
DEFINE_ARR(Sample, Sample)

uint32_t readBigEndian(FILE* file);
Arr_Sample loadMNIST(const char* imgPath, const char* labelPath);

#endif
