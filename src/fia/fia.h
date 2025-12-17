#pragma once

#include "../debug.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define T int

struct int_array {
  T *body;      // 数组数据指针
  int capacity; // 数组的最大容量
  struct int_array *origin;
};

typedef struct int_array *IntArray;
typedef IntArray IA;

IA int_array_create(int capacity);
EXEC_STATUS int_array_destroy(IA arr);

T int_array_get(const IA arr, int index);
void int_array_set(IA arr, int index, T value);
int int_array_capacity(const IA arr);

void int_array_print(const IA arr);
void int_array_fill_random(IA arr);
void int_array_fill_random_with_bound(IA arr, int bound);

// 用 0, 1, 2, ..., capacity-1 填充数组，便于构造特定数据或进行稳定性测试
void int_array_fill_sequential(IA arr);

// 生成一个近似有序数组，通过对已排序数组进行 N 次随机交换
void int_array_fill_almost_sorted(IA arr, int swaps);

// 生成一个包含大量重复元素的数组，bound 应该远小于 capacity
void int_array_fill_few_unique(IA arr, int bound);

bool int_array_is_ordered_asc(IA arr);
bool int_array_is_ordered_desc(IA arr);

IA int_array_slice(IA arr, int start, int end);
struct int_array int_array_reference(IA arr, int start, int end);
void int_array_reverse(IA arr);
void int_array_shuffle(IA arr);
