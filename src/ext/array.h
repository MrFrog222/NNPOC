#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>

#define DEFINE_ARR(type, name)\
typedef struct Arr_##name {\
  type* arr;\
  size_t len;\
} Arr_##name;\
\
void Arr_##name##_free(Arr_##name *arr) {\
  free(arr->arr);\
  arr->arr = NULL;\
  arr->len = 0;\
}\

#endif
