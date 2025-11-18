/**
 * libfss.h 实现
 * 函数测试库
 * @author ramsay
 * @date 2024.04.10
 */
#include "libfss.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



void fSortAnalyzer(ArraySorter fs) {
    int i = 0;
    int size = 100;
    long timing = 0;
    do {
        for (int j = 0; j < 10; j++) {
            int* array = intArrayGenerator(size, size * 10);
            timing += arrayProcessorTiming(fs, array, size);
            free(array);
        }
        printf("In scale of 10^%d, average time cost is %ld.\n", i+2, timing / 10);
        timing = 0;
        size *= 10;
        i++;
    } while (i < 4);
    
}


bool fSortCertifyTest(ArraySorter fAS, const int __size) {
    int i = 0;
    do {
    int* array = intArrayGenerator(__size, __size * 10);
    int* array_original_copy = arraySlice(array, 0, __size);

    // 有序性判断
    assert(ascendOrderTest(fAS(array, __size), __size));
    // 稳定性判断
    for (int i = 0; i < __size; i++) {
        int status = binarySearch(array, __size, array_original_copy[i]);
        assert(status != -1);
    }
    free(array);
    free(array_original_copy);
    i++;
    } while (i < 10);
    return true;
}