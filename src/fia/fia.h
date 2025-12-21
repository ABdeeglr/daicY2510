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
