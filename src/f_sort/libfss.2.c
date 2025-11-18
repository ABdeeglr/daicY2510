/**
 * libfss.h 实现
 * 返回值第一
 * @author ramsay
 * @date 2024.04.10
 */
#include "libfss.h"
#include <stdlib.h>
#include <time.h>

long arrayProcessorTiming(ArrayProcessor ap, int* __array, const int __size) {
    clock_t start = clock();
    ap(__array, __size);
    clock_t end = clock();
    clock_t diff = end - start;
    return (long) diff;
}

bool ascendOrderTest(int* __array, const int __array_size) {
    if (__array_size <= 1) return true;
    for (int i = 0; i < __array_size - 1; i++) {
        if (__array[i] <= __array[i+1]) continue;
        else return false;
    }
    return true;
}

int ascendingSearch(int* ascending_array,
                    const int size,
                    const int value)
{
    int start = 0;
    int end = size;
    if (value <= ascending_array[0]) return 0;
    if (value >= ascending_array[size - 1]) return size; 
    
    int pos = (start + end) / 2;
    do {
        if (ascending_array[pos - 1] <= value 
        && value <= ascending_array[pos]) break;

        if (ascending_array[pos] < value) start = pos;
        else if (ascending_array[pos] > value) end = pos;
        else return pos;
        pos = (start + end) / 2;
    } while (true);

    return pos;
}



int* arraySlice(int* __array, const int __start, const int __end) {
    int* ret = (int*) malloc(sizeof(int) * (__end - __start));
    for (int i = __start, j = 0; i < __end; i++, j++) ret[j] = __array[i];
    return ret;
}

int* intArrayGenerator(const int size, const int boundary) {
    int* numbers = (int*)malloc(sizeof(int) * size);
    srand((unsigned) time(NULL));

    if (size % 10 != 0) {
        for (int i = 0; i < size; i++) numbers[i] = rand() % boundary;
        return numbers;
    }
    
    for (int i = 0; i < size; i += 10)
    {
        numbers[i + 0] = rand() % boundary;
        numbers[i + 1] = rand() % boundary;
        numbers[i + 2] = rand() % boundary;
        numbers[i + 3] = rand() % boundary;
        numbers[i + 4] = rand() % boundary;
        numbers[i + 5] = rand() % boundary;
        numbers[i + 6] = rand() % boundary;
        numbers[i + 7] = rand() % boundary;
        numbers[i + 8] = rand() % boundary;
        numbers[i + 9] = rand() % boundary;
    }
    return numbers;
}


int binarySearch(int* ascending_array, const int __size, const int __value) {
    int start = 0;
    int end = __size;
    int interval = (end + start) / 2;

    while (end - start > 1) {
        if (ascending_array[interval] > __value) end = interval;
        else if (ascending_array[interval] < __value) start = interval;
        else break;
        interval = (end + start) / 2;
    }

    if (ascending_array[interval] == __value) {
        while (ascending_array[interval - 1] == __value)
        {
            interval--;
        }
        return interval;
    }
    else return -1;
}