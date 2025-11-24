#include "./fia.h"
#include "../debug.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define public_func
#define private_func

typedef unsigned int ia_index;

private_func int f_sqrt(int n) {
  int x = 1;
  bool decreased = false;
  for (;;) {
    int nx = (x + n / x) >> 1;
    if (x == nx || (nx > x && decreased))
      break;
    decreased = nx < x;
    x = nx;
  }
  return x;
}

public_func void int_array_print(const IA arr) {
  int tab = f_sqrt(arr->capacity);
  if (tab < 16)
    tab = 16;
  printf("[\n ");
  for (int i = 0; i < arr->capacity; i++) {
    printf("%d, ", *(arr->body + i));
    if (i % tab == tab - 1)
      printf("\n ");
  }
  printf("\n]\n");
}

public_func IA int_array_create(unsigned int capacity) {
  IA ia = (IA)malloc(sizeof(struct int_array));
  ia->body = (int *)calloc(capacity, sizeof(int));
  ia->capacity = capacity;
  return ia;
}

public_func void int_array_destroy(IA arr) {
  if (1) {
    if (arr != NULL) {
      if (arr->body != NULL)
        free(arr->body);
      free(arr);
    }
  }
}

public_func int int_array_get(const IA arr, unsigned int index) {
  if (index >= arr->capacity) {
    __WARNING("Int Array Index Out of Bound");
    exit(1);
  } else {
    return arr->body[index];
  }
}

public_func void int_array_set(IA arr, unsigned int index, int value) {
  if (index >= arr->capacity) {
    __WARNING("Int Array Index Out of Bound");
    exit(1);
  } else {
    arr->body[index] = value;
  }
}

public_func unsigned int int_array_capacity(const IA arr) {
  return arr->capacity;
}

public_func void int_array_fill_random(IA arr) {
  srand((unsigned)time(NULL));
  for (int i = 0; i < arr->capacity; i++) {
    arr->body[i] = rand();
  }
}

public_func IA int_array_slice(IA arr, unsigned int start, unsigned int end) {
  unsigned int cap;
  if (end < start) {
    __WARNING("Array Index shoule be reverse");
    cap = start - end;
  } else {
    cap = end - start;
  }
  IA res = int_array_create(cap);
  for (int i = 0; i < res->capacity; i++) {
    res->body[i] = arr->body[start + i];
  }
}

public_func void int_array_reverse(IA arr) {
  int step = arr->capacity / 2;
  for (int i = 0; i < step; i++) {
    int tmp = arr->body[i];
    arr->body[i] = arr->body[arr->capacity - i - 1];
    arr->body[arr->capacity - i - 1];
  }
}

public_func void int_array_shuffle(IA arr) { return; }
