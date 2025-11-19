#include "./fia.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
  printf("[\n ");
  for (int i = 0; i < arr->capacity; i++) {
    printf("%d, ", *(arr->body + i));
    if (i % tab == tab - 1)
      printf("\n ");
  }
  printf("\n]");
}

public_func void reset_IA(IA ia) { return; }

public_func void reverse_IA(const IA ia) { return; }


public_func void shuffle_IA(const IA ia) { return; }

public_func void is_ordered_IA(const IA ia) { return; }

public_func void is_descend_IA(const IA ia) { return; }

public_func void exchange_IA(const IA ia, const ia_index i, const ia_index j) {
  return;
}

public_func void left_insert_IA(const IA ia, const int value,
                                const ia_index position) {
  return;
}

public_func IA int_array_create(unsigned int capacity) {
    IA ia = (IA)malloc(sizeof(struct int_array));
    ia->body = (int *)calloc(capacity, sizeof(int));
    ia->capacity = capacity;
    ia->at = on_heap;
    return ia;
}


public_func void int_array_destroy(IA arr) {
    if (arr->at == on_heap) { 
        if (arr != NULL) {
            if (arr->body != NULL) free(arr->body);
            free(arr);
        }
    }
}

public_func IA slice_IA(const IA ia, const ia_index i, const ia_index j) {
  return NULL;
}




int int_array_get(const IA arr, unsigned int index);

void int_array_set(IA arr, unsigned int index, int value);

unsigned int int_array_capacity(const IA arr) {
  return arr->capacity;
}

void int_array_fill_random(IA arr);

IA int_array_slice(IA arr, unsigned int start, unsigned int end);

void int_array_reverse(IA arr);

void int_array_shuffle(IA arr);
