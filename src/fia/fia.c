#include "./fia.h"
#include <stdio.h>
#include <stdlib.h>

int f_sqrt(int n) {
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

public_func void delete_IA(IA ia) {
  if (ia != NULL) {
    if (ia->body != NULL) {
      free(ia->body);
    }
    free(ia);
  }
}
public_func void reset_IA(IA ia) { return; }

public_func void reverse_IA(const IA ia) { return; }

public_func void print_IA(const IA ia) {
  int tab = f_sqrt(ia->capacity);
  printf("[\n ");
  for (int i = 0; i < ia->capacity; i++) {
    printf("%d, ", *(ia->body + i));
    if (i % tab == tab - 1)
      printf("\n ");
  }
  printf("\n]");
}

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

public_func IA create_IA(const ia_index capacity) {
  IA ia = (IA)malloc(sizeof(struct int_array));
  ia->body = (int *)calloc(capacity, sizeof(int));
  ia->capacity = capacity;
  return ia;
}

public_func IA slice_IA(const IA ia, const ia_index i, const ia_index j) {
  return NULL;
}
