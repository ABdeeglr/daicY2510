#include "./fia.h"
#include "../debug.h"

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

public_func void int_array_fill_random_with_bound(IA arr, u32 bound) {
  if (bound > RAND_MAX) exit(1);
  srand((unsigned)time(NULL));
  for (int i = 0; i < arr->capacity; i++) {
    arr->body[i] = rand() % bound;
  }
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
  return res;
}

public_func void int_array_reverse(IA arr) {
  int step = arr->capacity / 2;
  for (int i = 0; i < step; i++) {
    int tmp = arr->body[i];
    arr->body[i] = arr->body[arr->capacity - i - 1];
    arr->body[arr->capacity - i - 1];
  }
}

public_func void int_array_shuffle(IA arr) {
  srand((unsigned)time(NULL));
  for (int i = arr->capacity - 1; i >0; i--) {
    int j = rand() % (i + 1);
    int tmp = arr->body[i];
    arr->body[i] = arr->body[j];
    arr->body[j] = tmp;
  }
}

public_func bool int_array_is_ordered_asc(IA arr) {
  for (int i = 0; i < arr->capacity - 2; i++)  {
    if (arr->body[i] <= arr->body[i+1]) continue;
    else return false;
  }
  return true;
}

public_func bool int_array_is_ordered_desc(IA arr) {
  for (int i = 0; i < arr->capacity - 2; i++)  {
    if (arr->body[i] >= arr->body[i+1]) continue;
    else return false;
  }
  return true;
  
}
