/**
 * The core of this src file you should know is 2 or more sort algorithm
 * These core functions are marked by a MACRO: public_func
 * And these marked by the MACRO: private_func, although you can use because C
 *   doesn't support encapsulation, but is recommended not to use anyway.
 *
 * Author: ABdeeglr Ramsay
 * Email: abdeeglr@icloud.com
 * Number: +114 514-1919-810 XD
 */

#include "./fsort.h"
#include <stdbool.h>
#include <stdio.h>

#ifndef public_func
#define public_func
#endif

#ifndef private_func
#define private_func
#endif

int __fsrt_global_counter = 0;

private_func void exch(IA arr, unsigned a, unsigned b);
private_func bool less(IA arr, unsigned a, unsigned b);
private_func void reset_counter();
private_func void read_counter();
private_func void add_counter();


/**
 * 选择排序:
 * 首先, 找到数组中最小的那个元素，
 * 然后把它和数组中的第一个元素交换位置，
 * 不断做这件事情，直到整个数组被排序完毕。
 *
 * 显然，这样做需要 N^2/2 次比较和最多 N 次交换；
 * 但是这似乎是原地排序，并不占用空间.
 *
 * 总体而言，选择排序太“笨”了，因为无论数组本身是否偏向有序，选择排序的运行时间总是一致的。
 * 即使是一个完全有序的数组，选择排序还是会运行相同的时间，
 * 这是因为第一遍扫描数组得到的信息，在下一轮循环中没什么用，还得重复一次。
 * 其他算法希望比选择排序更”聪明点“。
 */
public_func void selection_sort(IA arr, Behavior be) {
  if (VISUALIZE_MODE) {
    printf("\n= = = 正在进行选择排序可视化 = = =\n");
    printf("i  min ||");
    for (int i = 0; i < arr->capacity; i++) {
      printf("%4d", i);
    }
    printf("\n");
    printf("       ||");
    for (int i = 0; i < arr->capacity; i++) {
      printf("%4d", arr->body[i]);
    }
    printf("\n");
  }
  // Main Start
  for (int i = 0; i < arr->capacity - 1; i++) {
    int smallest_index = i;
    for (int j = i + 1; j < arr->capacity; j++) {
      if (less(arr, j, smallest_index))
        smallest_index = j;
    }
    exch(arr, i, smallest_index);
    // Main End
    if (VISUALIZE_MODE) {
      printf("%2d%4d ||", i, smallest_index);

      for (int k = 0; k < arr->capacity; k++) {
        if (k <= i)
          printf("\033[2m%4d\033[0m", arr->body[k]);
        else
          printf("%4d", arr->body[k]);
      }
      printf("\n");
    }
  }
  if (ANALYSIS_MODE) {
    if (be != NULL) be();
  }
  return;
}

/**
 * 插入排序:
 *
 * 首先，把第 1 个元素放到第 1 个位置（这看起来是废话），
 * 然后开始遍历，因为第一个元素已经有序了，所以把第 i 个元素插入到有序的数组中；
 */
public_func void insertion_sort(IA arr, Behavior be) {
    if (VISUALIZE_MODE) {
      printf("\n= = = 正在进行插入排序可视化 = = =\n");
      printf(" i  j ||");
      for (int i = 0; i < arr->capacity; i++) {
        printf("%4d", i);
      }
      printf("\n");
      printf("      ||");
      for (int i = 0; i < arr->capacity; i++) {
        printf("%4d", arr->body[i]);
      }
      printf("\n");
    }
  for (int index_of_element_aim_to_move = 1; index_of_element_aim_to_move < arr->capacity; index_of_element_aim_to_move ++) {
      int index_you_want_to_insert = index_of_element_aim_to_move;

      // Find the position to insert
      for (int j = 0; j < index_of_element_aim_to_move; j++) {
          if (less(arr, j, index_of_element_aim_to_move)) continue;
          else {
              index_you_want_to_insert = j;
              break;
          }
      }

      // reorganize the ordered array
      for (int k = index_of_element_aim_to_move; k > index_you_want_to_insert; k--) {
         exch(arr, k, k - 1);
      }

      if (VISUALIZE_MODE) {
        printf("%2d %2d ||", index_you_want_to_insert, index_of_element_aim_to_move);
        for (int k = 0; k < arr->capacity; k++) {
          if (k <= index_of_element_aim_to_move && k >= index_you_want_to_insert)
            printf("\033[2m%4d\033[0m", arr->body[k]);
          else
            printf("%4d", arr->body[k]);
        }
        printf("\n");
      }
  }
  if (ANALYSIS_MODE) {
    if (be != NULL) be();
  }
  return;
}

public_func void shell_sort(IA arr, Behavior be) {

  int N = arr->capacity;
  int h = 1;

  // To find the h-ordered array as beginning, we suggest that
  // an sub-array should have at least 2 elements, so N/3 is the
  // upper bound of count of h-order sub-array, for each contains
  // at least 2 elements and eventually 3 elements; 
  while (h < N / 3) h = 3 * h + 1; // 1 -> 4 -> 13 -> 40 -> 121 -> ...

  // 1-order array means the whole array was sorted
  while (h >= 1) {
    for (int i = h; i < N; i++) { // TODO: not understand now...
      for (int j = i; j >= h && less(arr, j, j - h); j -= h) {
        exch(arr, j, j - h);
      }
    }
    h = h / 3;
  }

  if (be != NULL) {
    be();
  }
}

private_func void exch(IA arr, unsigned a, unsigned b) {
  if (a > arr->capacity - 1 || b > arr->capacity - 1) {
    __ERROR("Array Index out bound!");
    __ERROR("At exchange [%d] <--> [%d] with range: [0, %d]\n", a, b,
            arr->capacity - 1);
    exit(1);
  }
  add_counter();
  int tmp = arr->body[a];
  arr->body[a] = arr->body[b];
  arr->body[b] = tmp;
}

private_func bool less(IA arr, unsigned a, unsigned b) {
  if (a > arr->capacity - 1 || b > arr->capacity - 1) {
    __ERROR("Array Index out bound!");
    __ERROR("At exchange [%d] <--> [%d] with range: [0, %d]\n", a, b,
            arr->capacity - 1);
    exit(1);
  }

  if (arr->body[a] < arr->body[b])
    return true;
  else
    return false;
}

private_func void add_counter() { __fsrt_global_counter++; }

private_func void reset_counter() { __fsrt_global_counter = 0; }

private_func void read_counter() {
  printf("Exec Counter: %d\n", __fsrt_global_counter);
}

public_func void analysis() {
  read_counter();
  reset_counter();
}
