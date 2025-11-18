/**
 * libfss.h 实现
 * 过程副作用第一
 * @author ramsay
 * @date 2024.04.10
 */
#include "libfss.h"
#include <stdio.h>
#include <stdlib.h>


bool safeInsert(int* array, const int array_size,
    const int ori_position, const int new_position)
{
    if (ori_position > array_size) return false;
    if (new_position > array_size) return false;

    if (new_position < ori_position) {
        int tmp = array[ori_position];
        for (int i = ori_position; i > new_position; i--) {
            array[i] = array[i - 1];
        }
        array[new_position] = tmp;
    }
    else {
        int tmp = array[ori_position];
        for (int i = ori_position; i < new_position; i++) {
            array[i] = array[i + 1];
        }
        array[new_position] = tmp;
    }

    return true;
}

void printArray(int* array, const int size) {
    printf("[");
    for (int i = 0; i < size - 1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[size-1]);
}

void exchange(int* ary, const int index_a, const int index_b) {
    int tmp = *(ary + index_a);
    *(ary + index_a) = *(ary + index_b);
    *(ary + index_b) = tmp;
}

void reverseArray(int* __array, const int __size) {
    int* tmp = (int*) malloc(sizeof(int) * __size);
    for (int i = 0; i < __size; i++) {
        tmp[i] = __array[__size - 1 - i];
    }
    for (int i = 0; i < __size; i++) {
        __array[i] = tmp[i];
    }
    free(tmp);
}