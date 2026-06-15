#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define DEFINE_LIST(type, name)\
typedef struct List_##name {
  type* arr;
  size_t len;
  size_t capacity;
} List_##name;

List_##name List_##name##_create(size_t capacity) {
  type* arr = malloc(capacity * sizeof(type));
  return (List_##name){arr, 0, capacity};
}

void List_##name##_push(List_##name *list, type* obj) {
  if(list->len >= list->capacity) {
    list->capacity = list->capacity == 0 ? 1:list->capacity*2;
    type* newArr = realloc(list->arr, list->capacity * sizeof(type));
    if(!newArr) {
      perror("Failed to reallocate memory for list!\n");
      exit(EXIT_FAILURE);
    }
    list->arr = newArr;
  }
  memcpy(list->arr + list->len, obj, sizeof(type));
  list->len++;
}

#endif
