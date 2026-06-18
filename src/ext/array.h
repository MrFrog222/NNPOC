#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>
#include <stdlib.h>

#define DEFINE_ARR(type, name)\
typedef struct Arr_##name {\
  type* arr;\
  size_t len;\
} Arr_##name;\
\
static inline void Arr_##name##_free(Arr_##name *arr) {\
  free(arr->arr);\
  arr->arr = NULL;\
  arr->len = 0;\
}\
\
static inline void Arr_##name##_shuffle(Arr_##name *arr) {\
  for(size_t i = 0; i < arr->len; i++) {\
    int j = rand() % (arr->len);\
    type temp[sizeof(type)];\
    *temp = arr->arr[i];\
    arr->arr[i] = arr->arr[j];\
    arr->arr[j] = *temp;\
  }\
}\

#endif
