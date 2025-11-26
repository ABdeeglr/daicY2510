/**
 * LIBFSS: library of support fuction and macros for f_sort
*/

#ifndef __LIBFSS__
#define __LIBFSS__
#define useful
#define Refactored
#include <stdbool.h>

/*****  Macro  ******/

/**
 * 对外接口
 */ 
#define public

/**
 * 仅限编译单元内使用
 */
#define private 

/**
 * 项目内使用
 */
#define friend


// Other Description Macro
#define support_function
#define analyze_function
#define function_pointer
#define such_any_descirpted_macro


typedef int* (*ArrayProcessor)(int*, const int);
typedef ArrayProcessor ArraySorter;

/**********  Support Fuctions  **********/

/**
 * (finished-pass) reverseArray
 * 翻转数组
 */
void reverseArray(int* __array, const int __size);

/**
 * (finish-pass) arraySlice
 * 在堆上开辟一个数组的切片.
 * 如果数组上的元素是引用类型，只会进行浅拷贝。
 * ### Example
 * arraySlice([0, 1, 2, 3, 4, 5], 0, 3)
 * return [0, 1, 2]
 */
int* arraySlice(int* __array, const int __start, const int __end);

/**
 * (finished-pass) Print the array in human-readable style
 */
void printArray(int* __array, const int __size);

/**
 * (finished-pass) 在内存上开辟一个数列，需要回收
 */
int* intArrayGenerator(const int size, const int boundary);

/**
 * (finished-pass) 将数组中的指定元素插入指定位置，原本处在该位置的元素向后移动一位，以此类推。 
 * 从而保持数组原本的顺序。 
 * @param array_size 数组长度
 * @param ori_position 需要被移动的数组元素的初始位置
 * @param new_position 需要被移动的数组元素的目标位置
 * @return true: 插入成功
 * @return false: 插入失败
 * 
 */
bool safeInsert(int* array, const int array_size, const int ori_position, const int new_position);

/**
 * (finished-pass) 交换数组中的两个位置上的元素
 */
void exchange(int* ary, const int index_a, const int index_b);


/**
 * (finished-pass) ascedingSearch.
 * 在升序数组中寻找一个合适的位置，使得插入新元素后，仍能保持有序
 * ### Example
 * array = [1, 2, 3, 6, 7, 11];
 * input = 10;
 * position = ascendingSearch(array, size, input);
 * position is 5;
 */
int ascendingSearch(int* asceding_array, const int size, const int value);


/**
 * (finished-pass) binarySearch
 * 在有序数组中，查找一个元素的位置，并返回第一个匹配的位置
 * 如果不存在，则返回 -1
 */
int binarySearch(int* ascending_array, const int __size, const int __value);


/**
 * (finished-pass) arrayProcessorTiming
 * 针对任意符合 ArrayProcessor 或 ArraySorter 接口的函数进行测试
 * 统计其占用的 CPU 时间片。
 * 返回所使用的时间。
*/
long arrayProcessorTiming(ArrayProcessor ap, int* __array, const int __size);


/*********  Test  ***********/



/**
 * - (finished-pass) fSortAnalyzer 
 * 
 * 对排序算法进行多样本效率测试
 * @param fas 特定的排序函数
*/
void fSortAnalyzer(ArraySorter fas);


/**
 * (finished-pass) fSortCertifyTest
 * 排序函数可靠性测试，
 * 主要判断排序是否正确
 * 通过返回 true，反之返回 false
 */
bool fSortCertifyTest(ArraySorter fs, const int __size);


/**
 * (finished-pass) ascendOrderTest
 * 测试数组是否以升序排列
 * @return bool
 */
bool ascendOrderTest(int* __array, const int __size);


#endif
