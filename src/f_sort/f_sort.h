/**
 * f_sort.h: A function collection about sort methods:
 * shell sort, bubble sort, insertion sort, selectiong sort, and so on...
 * @author : ABdeeglr Trueco
 * @machine: frieren@trueco
 * @date   : 2024.04.08
 * @email  : abdeeglr@icloud.com
 */
#ifndef __F_SORT_H__
#define __F_SORT_H__




/**
 * 首先，找到数组中最小的那个元素. 
 * 其次，将它和数组的第一个元素交换位置（如果第一个元素就是最小元素那么它就和自己交换）. 
 * 再次，在剩下的元素中找到最小的元素，将它与数组的第二个元素交换位置. 
 * 如此往复，直到将整个数组排序. 
 * 这种方法叫做选择排序，因为它在不断地选择剩余元素之中的最小者. 
 * @param a Comparable Array
 */
int* selectSort(int* a, const int size);

/**
 * 插入排序 
 * 
 * 每次排序一个子数组和一个新的元素，子数组总是假设是有序的。
 * 此时，将新元素插入到子数组的特定位置，从而形成更大的子数组。
 * 最终，得到完成的排序。
 * 
 * @param a Comparable Array
 * @param size Array length
*/
int* insertionSort(int* a, const int size);


int* shellSort(int* a, const int size);



#endif
/* f_sort.h */