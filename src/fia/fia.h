#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdbool.h>
#include "../debug.h"

struct int_array {
    int* body;     // 数组数据指针
    int capacity;  // 数组的最大容量
    struct int_array* origin;
};

typedef struct int_array* IntArray;
typedef IntArray IA;

IA int_array_create(int capacity);
EXEC_STATUS int_array_destroy(IA arr);

int int_array_get(const IA arr, int index);
void int_array_set(IA arr, int index, int value);
int int_array_capacity(const IA arr);
void int_array_print(const IA arr);
void int_array_fill_random(IA arr);
void int_array_fill_random_with_bound(IA arr, int bound);
bool int_array_is_ordered_asc(IA arr);
bool int_array_is_ordered_desc(IA arr);

IA int_array_slice(IA arr, int start, int end);
IA int_array_reference(IA arr, int start, int end);
void int_array_reverse(IA arr);
void int_array_shuffle(IA arr);
