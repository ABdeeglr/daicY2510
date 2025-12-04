#pragma once
#include "../debug.h"
#include "../switchers.h"
#include "../fia/fia.h"
#include <stdint.h>

typedef struct {
  uint64_t comparisons;
  uint64_t exchanges;
} SortContext;

#ifndef public_func
#define public_func
#endif

#ifndef private_func
#define private_func static
#endif

typedef void (*Behavior)(void);
typedef void (*ArrayProcessor)(IA arr, SortContext* ctx);
typedef ArrayProcessor Sorter;

void selection_sort(IA arr, SortContext* ctx);
void insertion_sort(IA arr, SortContext* ctx);
void shell_sort(IA arr, SortContext* ctx);
void merge_sort(IA arr, SortContext* ctx);
void quick_sort(IA arrr, SortContext* ctx);
