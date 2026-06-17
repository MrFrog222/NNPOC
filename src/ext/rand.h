#ifndef RAND_H
#define RAND_H

#include <stdlib.h>
#include <time.h>
#include <stddef.h>

static inline float randFloat(float min, float max) {
  return min + rand() / (float)RAND_MAX * (max - min);
}

#endif
