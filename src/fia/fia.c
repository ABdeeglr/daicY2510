#include "./fia.h"

#define public_func
#define private_func static


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
  printf("[");
  for (int i = 0; i < arr->capacity - 1; i++) {
    printf("%d, ", *(arr->body + i));
    if (i % tab == tab - 1)
      printf("\n ");
  }
  printf("%d]\n\n", *(arr->body + arr->capacity - 1));
}

public_func IA int_array_create(int capacity) {
  if (capacity < 0) {
    __ERROR("Invalid argument");
    exit(FAIL);
  }
  if (capacity == 0) {
    __WARNING("Not a proper argument, IA created faild with NULL retur type");
    return NULL;
  }
  IA ia = (IA) malloc(sizeof(struct int_array));
  ia->body = (int *)calloc(capacity, sizeof(int));
  ia->capacity = capacity;
  ia->origin = NULL;
  return ia;
}

public_func EXEC_STATUS int_array_destroy(IA arr) {

  // Pointer has been freed or reasigned
  if (arr == NULL) {
    __ERROR("Double Free!");
    if (DEBUG_MODE) exit(ER200_DOUBLE_FREE);
    return ER200_DOUBLE_FREE;
  }

  // Not a real IA pointer but an reference
  if (arr->origin != NULL) {
    free(arr);
    return SUCCESS;
  }

  // Unknown Error
  if (arr->body == NULL) {
    __ERROR("Unknow error on free IA's body!");
    if (DEBUG_MODE) exit(FAIL);
    return FAIL;
  }
  
  free(arr->body);
  free(arr);
  return SUCCESS;
}

public_func int int_array_get(const IA arr, int index) {
  if (index >= arr->capacity) {
    __ERROR("Int Array Index Out of Bound");
    exit(ER100_ARRAY_INDEX_OUT_OF_BOUND);
  } else {
    return arr->body[index];
  }
}

public_func void int_array_set(IA arr, int index, int value) {
  if (index < 0) {
    __ERROR("Invalid argument: index: %d < 0", index);
    exit(FAIL);
  }
  if (index >= arr->capacity) {
    __ERROR("Int Array Index Out of Bound");
    exit(ER100_ARRAY_INDEX_OUT_OF_BOUND);
  } else {
    arr->body[index] = value;
  }
}

public_func int int_array_capacity(const IA arr) {
  return arr->capacity;
}

public_func void int_array_fill_random_with_bound(IA arr, int bound) {
  if (bound > RAND_MAX) exit(FAIL);
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

public_func void int_array_fill_sequential(IA arr) {
  if (arr != NULL) {
    for (int i = 0; i < arr->capacity; i++) {
      arr->body[i] = i;
    }
  } else {
    __WARNING("Null pointer Error");
    return;
  }
}

public_func void int_array_fill_almost_sorted(IA arr, int swaps) {
  if (arr == NULL || swaps < 0) return;
  
  // 1. 先生成一个完全有序的数组
  int_array_fill_sequential(arr); 

  // 2. 进行少量随机交换，破坏其有序性
  srand((unsigned)time(NULL));
  for (int i = 0; i < swaps; i++) {
    int idx1 = rand() % arr->capacity;
    int idx2 = rand() % arr->capacity;
    
    // 简单交换（使用 IA 的底层 body 访问更高效）
    int tmp = arr->body[idx1];
    arr->body[idx1] = arr->body[idx2];
    arr->body[idx2] = tmp;
  }
}

public_func void int_array_fill_few_unique(IA arr, int bound) {
  if (arr == NULL) return;
  if (bound <= 0) bound = 1; // 至少包含一个键值
  
  srand((unsigned)time(NULL));
  for (int i = 0; i < arr->capacity; i++) {
    // 确保键值分布在 [0, bound - 1] 之间，bound 越小，重复越多
    arr->body[i] = rand() % bound;
  }
}

public_func IA int_array_slice(IA arr, int start, int end) {
  if (end > arr->capacity || start < 0) {
    __ERROR("Int Array Index Out of Bound");
    exit(ER100_ARRAY_INDEX_OUT_OF_BOUND);
  }

  int cap;
  if (end < start) {
    __WARNING("Array Index shoule be reverse");
    cap = start - end;
  } else {
    cap = end - start;
  }
  
  if (cap > arr->capacity) {
    __ERROR("Cannot clone an array larger than its origin");
    __ERROR("Int Array Index Out of Bound");
    exit(ER100_ARRAY_INDEX_OUT_OF_BOUND);
  }
  
  IA res = int_array_create(cap);

  for (int i = 0; i < res->capacity; i++) {
    res->body[i] = arr->body[start + i];
  }

  return res;
}

IA int_array_reference(IA arr, int start, int end) {
  if (end > arr->capacity || start < 0) {
    __ERROR("Int Array Index Out of Bound");
    exit(ER100_ARRAY_INDEX_OUT_OF_BOUND);
  }

  int cap;
  if (end < start) {
    __WARNING("Array Index shoule be reverse");
    cap = start - end;
  } else {
    cap = end - start;
  }
  
  if (cap > arr->capacity) {
    __ERROR("Cannot reference an array larger than its origin");
    __ERROR("Int Array Index Out of Bound");
    exit(ER100_ARRAY_INDEX_OUT_OF_BOUND);
  }

  IA res = (IA) malloc(sizeof(struct int_array));
  res->origin = arr;
  res->capacity = cap;
  res->body = arr->body + start;

  return res;
}


public_func void int_array_reverse(IA arr) {
  int step = arr->capacity / 2;
  for (int i = 0; i < step; i++) {
    int tmp = arr->body[i];
    arr->body[i] = arr->body[arr->capacity - i - 1];
    arr->body[arr->capacity - i - 1] = tmp;
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
  __INFO("%p is ordered ASC", arr);
  return true;
}

public_func bool int_array_is_ordered_desc(IA arr) {
  for (int i = 0; i < arr->capacity - 2; i++)  {
    if (arr->body[i] >= arr->body[i+1]) continue;
    else return false;
  }
  __INFO("%p is ordered DESC", arr);
  return true;
  
}
