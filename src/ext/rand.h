#ifndef RAND_H
#define RAND_H

#include <stdlib.h>
#include <time.h>
#include <stddef.h>

float randFloat(float min, float max) {
  srand(time(NULL));
  return min + rand() / (float)RAND_MAX * (max - min);
}

#endif
