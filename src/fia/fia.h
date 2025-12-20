#pragma once

#include "../debug.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef T
#define T int
#endif


typedef enum storage_type {
  STACK = 0,
  HEAP = 1,
} StorageType;

#ifndef Public
#define Public
#endif

#ifndef Private
#define Private static
#endif

struct array;
typedef struct array* Array;
struct result_of_ia_methods {
  void* value;
  EXEC_STATUS status;
};
typedef struct result_of_ia_methods iamResult;

typedef struct fia_package_methods {
  iamResult (*create)              (int capacity);
  iamResult (*slice)               (Array origin, int start, int offset);
  iamResult (*reference)           (Array origin, Array ref, int start, int offset);
  iamResult (*destroy)             (Array arr);
  T         (*getByPosition)       (const Array arr, int index);
  iamResult (*setByPosition)       (Array arr, int index, T value);
  int       (*getCapacity)         (const Array arr);
  void      (*display)             (const Array arr);
  void      (*fillRandomWithBound) (Array arr, int bound);
  void      (*fillSequential)      (Array arr);
  void      (*fillAlmostSorted)    (Array arr, int swaps);
  void      (*fillFewUnique)       (Array arr, int bound);
  bool      (*isOrderedAsc)        (Array arr);
  bool      (*isOrderedDesc)       (Array arr);
  void      (*shuffle)             (Array arr);
  void      (*reverse)             (Array arr);
} FiaPackageMethods;

FiaPackageMethods FiaPackageTopMethod_Initialize();
bool FiaPackageTopMethod_UnitTest();

// struct array {
//   T *body;      // 数组数据指针
//   int capacity; // 数组的最大容量
//   int storage;
//   struct array *origin;
// };




Array array_create(int capacity);
EXEC_STATUS array_destroy(Array arr);

T array_get(const Array arr, int index);
void array_set(Array arr, int index, T value);
int array_capacity(const Array arr);

void array_print(const Array arr);
void array_fill_random(Array arr);
void array_fill_random_with_bound(Array arr, int bound);

// 用 0, 1, 2, ..., capacity-1 填充数组，便于构造特定数据或进行稳定性测试
void array_fill_sequential(Array arr);

// 生成一个近似有序数组，通过对已排序数组进行 N 次随机交换
void array_fill_almost_sorted(Array arr, int swaps);

// 生成一个包含大量重复元素的数组，bound 应该远小于 capacity
void array_fill_few_unique(Array arr, int bound);

bool array_is_ordered_asc(Array arr);
bool array_is_ordered_desc(Array arr);

Array array_slice(Array arr, int start, int end);
struct array array_reference(Array arr, int start, int end);
void array_reverse(Array arr);
void array_shuffle(Array arr);

