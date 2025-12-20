#include "./fia.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct array {
  T *body;      // 数组数据指针
  int capacity; // 数组的最大容量
  StorageType s_type;
  struct array *origin;
};

#ifdef raise
#undef raise
#endif
#define raise return

/****************** Private Function ********************/
Private int f_sqrt(int n);
Private void dispaly(const Array arr);
Private iamResult simple_error_wrapper(ERROR_CODE err, const char* msg);
Private iamResult create(int capacity);
Private iamResult slice(Array origin, int start, int offset);
Private iamResult reference(Array origin, Array ref, int start, int offset);
Private iamResult destroy(Array arr);
Private iamResult set_by_position(Array arr, int index, T value);
Private T get_by_position(const Array arr, int index);
Private int get_capacity(const Array arr);
Private void fill_random_with_bound(Array arr, int bound);
Private void fill_sequential(Array arr);
Private void fill_almost_sorted(Array arr, int swaps);
Private void fill_few_unique(Array arr, int bound);
Private bool is_ordered_asc(Array arr);
Private bool is_ordered_desc(Array arr);
Private void reverse(Array arr);
Private void shuffle(Array arr);





/***************** Public Function *********************/

Public FiaPackageMethods FiaPackageTopMethod_Initialize() {
  FiaPackageMethods FIA = {
    .create = create,
    .slice = slice,
    .reference = reference,
    .destroy = destroy,
    .getByPosition = get_by_position,
    .setByPosition = set_by_position,
    .getCapacity = get_capacity,
    .display = dispaly,
    .fillRandomWithBound = fill_random_with_bound,
    .fillSequential = fill_sequential,
    .fillAlmostSorted = fill_almost_sorted,
    .fillFewUnique = fill_few_unique,
    .isOrderedAsc = is_ordered_asc,
    .isOrderedDesc = is_ordered_desc,
    .shuffle = shuffle,
    .reverse = reverse,
  };
  return FIA;  
}

// TODO
Public bool FiaPackageTopMethod_UnitTest() {


  printf("Part I: Basic test, initialize and free and small functions\n");
  
  FiaPackageMethods Fia = FiaPackageTopMethod_Initialize();
  iamResult rt = Fia.create(30);
  Array arr;
  if (rt.status != SUCCESS) {
    __ERROR("TEST FAILED, Cannot initialize object on heap");
    return false;
  } else {
    arr = (Array) rt.value;
  }

  printf("Insert random ints\n");
  Fia.fillRandomWithBound(arr, arr->capacity << 4);
  Fia.display(arr);
  printf("shuffle it\n");
  Fia.shuffle(arr);
  Fia.display(arr);
  printf("reversed it\n");
  Fia.reverse(arr);
  Fia.display(arr);
  printf("free it\n");
  rt = Fia.destroy(arr);
  if (rt.status != SUCCESS) {
    __ERROR("TEST FAILED, Cannot free object on heap");
    return false;
  }
  if (rt.value != NULL) {
    __ERROR("TEST FAILED, Unknown Error");
    return false;
  }


  printf("Part II: initialize, slice and reference\n");

  rt = Fia.create(20);
  Fia.destroy((Array) rt.value);


  
  return true;
}

Private iamResult slice(Array origin, int start, int offset) {
  if (origin == NULL) {
    raise simple_error_wrapper(FAIL, "NullPointerError, Object Not Found");
  } else {
    if (start < 0 || start + offset > origin->capacity) raise simple_error_wrapper(FAIL, "Invalid argument, may caused index out of bound.");
    if (origin->body == NULL) {
      raise simple_error_wrapper(FAIL, "NullPointerError, Object Not Found");
    } else {
      iamResult res = create(offset);
      if (res.status != SUCCESS) return res;

      Array tmp = (Array) res.value;
      for (int i = 0; i < offset; i++) {
        tmp->body[i] = origin->body[start + i];
      }
      tmp->origin = origin;
      return res;
    }
  }
}

Private iamResult reference(Array origin, Array ref, int start, int offset) {
  if (origin == NULL) {
    raise simple_error_wrapper(FAIL, "NullPointerError, Object Not Found");
  } else {
    if (start < 0 || start + offset > origin->capacity) raise simple_error_wrapper(FAIL, "Invalid argument, may caused index out of bound.");
    if (origin->body == NULL) {
      raise simple_error_wrapper(FAIL, "NullPointerError, Object Not Found");
    } else {
      ref->body = origin->body + start;
      ref->capacity = offset; 
      ref->s_type = STACK;
      ref->origin = origin;

      iamResult res = {.value = (void*) ref, .status = SUCCESS};
      return res;
    }
  }
}



Private void reverse(Array arr) {
  int step = arr->capacity / 2;
  for (int i = 0; i < step; i++) {
    T tmp = arr->body[i];
    arr->body[i] = arr->body[arr->capacity - i - 1];
    arr->body[arr->capacity - i - 1] = tmp;
  }
}

Private void shuffle(Array arr) {
  srand((unsigned)time(NULL));
  for (int i = arr->capacity - 1; i > 0; i--) {
    int j = rand() % (i + 1);
    T tmp = arr->body[i];
    arr->body[i] = arr->body[j];
    arr->body[j] = tmp;
  }
}

Private bool is_ordered_asc(Array arr) {
  for (int i = 0; i < arr->capacity - 2; i++)  {
    if (arr->body[i] <= arr->body[i+1]) continue;
    else return false;
  }
  return true;
}

Private bool is_ordered_desc(Array arr) {
  for (int i = 0; i < arr->capacity - 2; i++)  {
    if (arr->body[i] >= arr->body[i+1]) continue;
    else return false;
  }
  return true;
  
}

Private void fill_random_with_bound(Array arr, int bound) {
  if (bound <= 0) {
    __WARNING("+RANDMAX")
    bound += RAND_MAX;
  }
  srand((unsigned)time(NULL));
  for (int i = 0; i < arr->capacity; i++) {
    arr->body[i] = rand() % bound;
  }
}
Private void fill_sequential(Array arr) {
  if (arr != NULL) {
    for (int i = 0; i < arr->capacity; i++) {
      arr->body[i] = i;
    }
  } else {
    __WARNING("Null pointer Error");
    return;
  }
}



Private void fill_almost_sorted(Array arr, int swaps) {
  // 1. 先生成一个完全有序的数组

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



Private void fill_few_unique(Array arr, int bound) {
  if (arr == NULL) return;
  if (bound <= 0) bound = 1; // 至少包含一个键值
  
  srand((unsigned)time(NULL));
  for (int i = 0; i < arr->capacity; i++) {
    // 确保键值分布在 [0, bound - 1] 之间，bound 越小，重复越多
    arr->body[i] = rand() % bound;
  }
}

Private int get_capacity(const Array arr) {
  return arr->capacity;
}

Private iamResult set_by_position(Array arr, int index, T value) {
  if (index < 0 || index >= arr->capacity) {
    raise simple_error_wrapper(FAIL, "Invalid argument, position argument was negative or out of index");
  }
  arr->body[index] = value;
  iamResult res = {.value = NULL, .status = SUCCESS};
  return res;
}

Private T get_by_position(const Array arr, int index) {
  if (index >= arr->capacity) {
    __ERROR("Int Array Index Out of Bound");
    exit(ER100_ARRAY_INDEX_OUT_OF_BOUND);
  } else {
    return arr->body[index];
  }
}

Private iamResult destroy(Array arr) {
  if (arr == NULL) {
    raise simple_error_wrapper(FAIL, "Free on NullPointer");
  }
  else {
    if (arr->body == NULL) {
     raise simple_error_wrapper(ER200_DOUBLE_FREE, "Double Free!");
    } else {
      if (arr->s_type == STACK) raise simple_error_wrapper(ER201_FREE_ON_NOHEAP_OBJECT, "Cannot free a reference object");
      else /*if (arr->s_type == HEAP)*/ {
        free(arr->body);
        free(arr);
        iamResult res = {.status = SUCCESS, .value = NULL};
        return res;
      }
    }
  }
}

Private iamResult simple_error_wrapper(ERROR_CODE err, const char* msg) {
    fprintf(stderr,
            "\e[31m==[%s]==\e[0m \e[4m\e[35m%s\e[0m\e[0m:\e[4m%d\e[0m :(%s)\n",
            "WARNN",
            __FILE__,
            __LINE__,
            msg
        );

  iamResult error_result = {
    .value = NULL,
    .status = err,
  };

  return error_result;
}

// A safe way to create an Array object on heap
// if failed, nothing will leak.
Private iamResult create(int capacity) {
  if (capacity <= 0) raise simple_error_wrapper(FAIL, "Invalid Argument about capacity, capacity can not be an negative number");

  Array ia = (Array) malloc(sizeof(struct array));
  if (ia == NULL) raise simple_error_wrapper(ER050_RUN_OUT_OF_MEMORY, "Heap Malloc Failed");

  ia->body = (T*) calloc(capacity, sizeof(T));
  if (ia->body == NULL) {
    free(ia);
    raise simple_error_wrapper(ER050_RUN_OUT_OF_MEMORY, "Heap Malloc Failed");
  }
  ia->capacity = capacity;
  ia->s_type = HEAP;
  ia->origin = NULL;

  iamResult result = {
    .value = ia,
    .status = SUCCESS,
  };

  return result;
}

Private void dispaly(const Array arr) {
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


/**************************************/
Private int f_sqrt(int n) {
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

Public void int_array_print(const Array arr) {
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


Public Array int_array_create(int capacity) {
  if (capacity < 0) {
    __ERROR("Invalid argument");
    exit(FAIL);
  }
  if (capacity == 0) {
    __WARNING("Not a proper argument, IA created faild with NULL retur type");
    return NULL;
  }

  Array ia = (Array) malloc(sizeof(struct array));
  ia->body = (T*) calloc(capacity, sizeof(T));
  ia->capacity = capacity;
  ia->origin = NULL;
  return ia;
}

Public EXEC_STATUS int_array_destroy(Array arr) {

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

Public T int_array_get(const Array arr, int index) {
  if (index >= arr->capacity) {
    __ERROR("Int Array Index Out of Bound");
    exit(ER100_ARRAY_INDEX_OUT_OF_BOUND);
  } else {
    return arr->body[index];
  }
}

Public void int_array_set(Array arr, int index, T value) {
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

Public int int_array_capacity(const Array arr) {
  return arr->capacity;
}

Public void int_array_fill_random_with_bound(Array arr, int bound) {
  if (bound > RAND_MAX) exit(FAIL);
  srand((unsigned)time(NULL));
  for (int i = 0; i < arr->capacity; i++) {
    arr->body[i] = rand() % bound;
  }
}

Public void int_array_fill_random(Array arr) {
  srand((unsigned)time(NULL));
  for (int i = 0; i < arr->capacity; i++) {
    arr->body[i] = rand();
  }
}

Public void int_array_fill_sequential(Array arr) {
  if (arr != NULL) {
    for (int i = 0; i < arr->capacity; i++) {
      arr->body[i] = i;
    }
  } else {
    __WARNING("Null pointer Error");
    return;
  }
}

Public void int_array_fill_almost_sorted(Array arr, int swaps) {
  // 1. 先生成一个完全有序的数组

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

Public void int_array_fill_few_unique(Array arr, int bound) {
  if (arr == NULL) return;
  if (bound <= 0) bound = 1; // 至少包含一个键值
  
  srand((unsigned)time(NULL));
  for (int i = 0; i < arr->capacity; i++) {
    // 确保键值分布在 [0, bound - 1] 之间，bound 越小，重复越多
    arr->body[i] = rand() % bound;
  }
}

// DOING
Public Array int_array_slice(Array arr, int start, int end) {
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

  Array res = int_array_create(cap);

  for (int i = 0; i < res->capacity; i++) {
    res->body[i] = arr->body[start + i];
  }

  return res;
}

struct array int_array_reference(Array arr, int start, int end) {
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

  struct array array_ref;
  array_ref.origin = arr;
  array_ref.capacity = cap;
  array_ref.body = arr->body + start;

  return array_ref;
}

Public void int_array_reverse(Array arr) {
  int step = arr->capacity / 2;
  for (int i = 0; i < step; i++) {
    T tmp = arr->body[i];
    arr->body[i] = arr->body[arr->capacity - i - 1];
    arr->body[arr->capacity - i - 1] = tmp;
  }
}

Public void int_array_shuffle(Array arr) {
  srand((unsigned)time(NULL));
  for (int i = arr->capacity - 1; i > 0; i--) {
    int j = rand() % (i + 1);
    T tmp = arr->body[i];
    arr->body[i] = arr->body[j];
    arr->body[j] = tmp;
  }
}

Public bool int_array_is_ordered_asc(Array arr) {
  for (int i = 0; i < arr->capacity - 2; i++)  {
    if (arr->body[i] <= arr->body[i+1]) continue;
    else return false;
  }
  __INFO("%p is ordered ASC", arr);
  return true;
}

Public bool int_array_is_ordered_desc(Array arr) {
  for (int i = 0; i < arr->capacity - 2; i++)  {
    if (arr->body[i] >= arr->body[i+1]) continue;
    else return false;
  }
  __INFO("%p is ordered DESC", arr);
  return true;
  
}
