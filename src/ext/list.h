#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFINE_LIST(type, name)\
typedef struct List_##name {\
  type* arr;\
  size_t len;\
  size_t capacity;\
} List_##name;\
\
List_##name List_##name##_create(size_t capacity) {\
  capacity += capacity == 0;\
  type* arr = malloc(capacity * sizeof(type));\
  return (List_##name){arr, 0, capacity};\
}\
\
void List_##name##_push(List_##name *list, type *obj) {\
  if(list->len >= list->capacity) {\
    list->capacity *= 2;\
    list->arr = realloc(list->arr, list->capacity * sizeof(type));\
  }\
  memcpy(list->arr + list->len, obj, sizeof(type));\
  list->len++;\
}\
\
void List_##name##_free(List_##name *list) {\
  free(list->arr);\
  list->arr = NULL;\
  list->len = 0;\
  list->capacity = 0;\
}\

#endif
