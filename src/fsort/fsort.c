/** * The core of this src file you should know is 2 or more sort algorithm *
 * These core functions are marked by a MACRO: public_func * And these marked by
 * the MACRO: private_func, although you can use because C *   doesn't support
 * encapsulation, but is recommended not to use anyway. * Author: ABdeeglr
 * Ramsay Email: abdeeglr@icloud.com Number: +114 514-1919-810 XD
 */

#include "./fsort.h"

#ifndef LIMITED
#define LIMITED 16
#endif

// Core
private_func void exch(IA arr, int a, int b, SortContext *ctx);
private_func bool less(IA arr, int a, int b, SortContext *ctx);

/**
 * @Args
 * @arr, the array you want to order;
 * @tmp, a temporary copy on memory, for saving the origin data in a merge
 * progress
 * @lo, the start of the origin arry you want to merge
 * @mid, just like above
 * @hi, just like above
 */
private_func void merge(IA arr, int *tmp, int lo, int mid, int hi);
private_func void inner_merge_sort_core(IA arr, int *tmp, int lo, int hi);
// private_func void inner_merge_sort_limited(IA arr, int* tmp, int lo, int hi);
private_func void inner_quick_sort_core(IA arr, int lo, int hi);
private_func int partion(IA arr, int lo, int hi);
private_func void print_ia(int* arr, int start, int end, int a, int b);

// Other
private_func void print_seperator();

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
public_func void selection_sort(IA arr, SortContext *ctx) {

  if (VISUALIZE_MODE) {

    // HAEADER line
    // Such like: i min 0 1 2 3 4 ......
    const int N = arr->capacity;
    printf("\n= = = 正在进行    排序可视化 = = =\n");
    printf("  i min");
    print_seperator();
    for (int i = 0; i < N; i++)
      printf("%4d", i);
    printf("\n");

    // Origin Info line: print the origin array;
    printf("   ");
    printf("    ");
    print_seperator();
    for (int i = 0; i < N; i++)
      printf("%4d", arr->body[i]);
    printf("\n");

    // Sorting Visualization lines:
    for (int i = 0; i < N; i++) {
      int min = i;
      for (int j = i + 1; j < N; j++) {
        if (less(arr, j, min, ctx))
          min = j;
      }

      // Now you find the samllest int this cycle
      printf("%3d%4d", i, min);
      print_seperator();
      for (int x = 0; x < N; x++) {
        // print the element has been ordered by dim style
        if (x < i) {
          printf(BACKGROUND_PRINT_BEGIN);
          printf("%4d", arr->body[x]);
          printf(BACKGROUND_PRINT_END);
        }
        // print the element will be move with underline style
        else if (x == min) {
          printf(UNDERLINE_PRINT_BEGIN);
          printf("%4d", arr->body[x]);
          printf(UNDERLINE_PRINT_END);
        }
        // Ordinary print
        else
          printf("%4d", arr->body[x]);
      }
      printf("\n");
      exch(arr, i, min, ctx);
    }
    printf("Finish!");
    print_seperator();
    printf(BACKGROUND_PRINT_BEGIN);
    for (int i = 0; i < N; i++)
      printf("%4d", arr->body[i]);
    printf(BACKGROUND_PRINT_END);
    printf("\n");
  } else {
    int N = arr->capacity;

    // In this layer of cycle, we mean to set the smallest element
    // to the proper position
    for (int i = 0; i < N; i++) {
      int min = i; // index of the smallest element

      // In this layer of cycle, we want to find the smallest element in
      // the n-tail-subarray and remember its index;
      // `n-tail-subarray`, which means the subarray which contains the last n
      // elements of a N-length array.
      for (int j = i + 1; j < N; j++) {
        // We suppose `j = i+1` as the initial smallest element's index
        // If find an element smaller than it, than replace it.
        if (less(arr, j, min, ctx))
          min = j;
      }

      // After we find the smallest element's index, exchange it
      exch(arr, i, min, ctx);
    }
  }

  return;
}

/**
 * 插入排序:
 *
 * 首先，把第 1 个元素放到第 1 个位置（这看起来是废话），
 * 然后开始遍历，因为第一个元素已经有序了，所以把第 i 个元素插入到有序的数组中；
 */
public_func void insertion_sort(IA arr, SortContext *ctx) {
  const int N = arr->capacity;

  if (VISUALIZE_MODE) {
    printf("\n= = = 正在进行 Insertion Sort 可视化 = = =\n");
    printf("  i  j");
    print_seperator();
    for (int i = 0; i < N; i++) {
      printf("%4d", i);
    }
    printf("\n");

    // Origin Info line: print the origin array;
    printf("   ");
    printf("   ");
    print_seperator();
    for (int i = 0; i < N; i++) {
      if (i == 1) {
        printf(UNDERLINE_PRINT_BEGIN);
        printf("%4d", arr->body[i]);
        printf(UNDERLINE_PRINT_END);
      } else {
        printf("%4d", arr->body[i]);
      }
    }
    printf("\n");

    for (int i = 1; i < N; i++) {

      int position = i;

      for (int j = i; j > 0 && less(arr, j, j - 1, ctx); j--) {
        exch(arr, j, j - 1, ctx);
        position--;
      }

      // print index
      {
        printf("%3d%3d", position, i);
        print_seperator();
      }

      for (int k = 0; k < N; k++) {
        if (k < position) {
          printf(DIM_PRINT_BEGIN);
          printf("%4d", arr->body[k]);
          printf(DIM_PRINT_END);
        } else if (k <= i) {
          printf(BACKGROUND_PRINT_BEGIN);
          printf("%4d", arr->body[k]);
          printf(BACKGROUND_PRINT_END);
        } else if (k == i + 1) {
          printf(UNDERLINE_PRINT_BEGIN);
          printf("%4d", arr->body[k]);
          printf(UNDERLINE_PRINT_END);
        } else {
          printf(DIM_PRINT_BEGIN);
          printf("%4d", arr->body[k]);
          printf(DIM_PRINT_END);
        }
      }
      printf("\n");
    }

  } else {
    for (int i = 1; i < N; i++) {
      for (int j = i; j > 0 && less(arr, j, j - 1, ctx); j--) {
        exch(arr, j, j - 1, ctx);
      }
    }
  }

  return;
}

public_func void shell_sort(IA arr, SortContext *ctx) {
  if (VISUALIZE_MODE) {
    // TODO
  } else {
    int N = arr->capacity;
    int h = 1;

    // To find the h-ordered array as beginning, we suggest that
    // an sub-array should have at least 2 elements, so N/3 is the
    // upper bound of count of h-order sub-array, for each contains
    // at least 2 elements and eventually 3 elements;
    while (h < N / 3)
      h = 3 * h + 1; // 1 -> 4 -> 13 -> 40 -> 121 -> ...

    // 1-order array means the whole array was sorted
    while (h >= 1) {
      for (int i = h; i < N; i++) {
        for (int j = i; j >= h && less(arr, j, j - h, ctx); j -= h) {
          exch(arr, j, j - h, ctx);
        }
      }
      h = h / 3;
    }
  }
}

private_func void merge(IA arr, int *tmp, int lo, int mid, int hi) {
  int i = lo, j = mid + 1;

  for (int k = lo; k <= hi; k++) {
    tmp[k] = arr->body[k];
  }

  for (int k = lo; k <= hi; k++) {
    if (i > mid)
      arr->body[k] = tmp[j++];
    else if (j > hi)
      arr->body[k] = tmp[i++];
    else if (tmp[j] < tmp[i])
      arr->body[k] = tmp[j++];
    else
      arr->body[k] = tmp[i++];
  }
}

private_func void inner_merge_sort_core(IA arr, int *tmp, int lo, int hi) {
  if (hi < lo + LIMITED) {
    IA s = int_array_reference(arr, lo, hi);
    insertion_sort(s, NULL);
    int_array_destroy(s);
    return;
  }

  int mid = lo + (hi - lo) / 2;

  inner_merge_sort_core(arr, tmp, lo, mid);
  inner_merge_sort_core(arr, tmp, mid + 1, hi);

  merge(arr, tmp, lo, mid, hi);
}

// private_func void inner_merge_sort_limited(IA arr, int* tmp, int lo, int hi)
// {
//   if (hi <= lo + LIMITED) {
//     insertion_sort(int_array_reference(arr, lo, hi), NULL);
//     return;
//   }
//   int mid = lo + ((hi - lo) / 2);
//   inner_merge_sort_limited(arr, tmp, lo, mid);
//   inner_merge_sort_limited(arr, tmp, mid+1, hi);
//   merge(arr, tmp, lo, mid, hi);
// }

public_func void merge_sort(IA arr, SortContext *ctx) {

  int *tmp = (int *)calloc(arr->capacity, sizeof(int));

  inner_merge_sort_core(arr, tmp, 0, arr->capacity - 1);

  free(tmp);
}

private_func void inner_quick_sort_core(IA arr, int lo, int hi) {
  if (hi <= lo) return;
  int j = partion(arr, lo, hi);
  inner_quick_sort_core(arr, lo, j - 1);
  inner_quick_sort_core(arr, j + 1, hi);
}

private_func void print_ia(int* arr, int start, int end, int a, int b) {
  printf("[");
  for (int i = start; i < end - 1; i++) {
    if (i == a || i == b) {
      printf(RED_PRINT_BEGIN);
      printf("%d, ", *(arr + i));
      printf(RED_PRINT_END);
    } else printf("%d, ", *(arr + i));
  }
  if (end - 1 == a || end - 1 == b) {
    printf(RED_PRINT_BEGIN);
    printf("%d]", *(arr + end - 1));
    printf(RED_PRINT_END);
  } else printf("%d]", *(arr + end - 1));
  printf("\n");
}

private_func int partion(IA arr, int lo, int hi) {
  int* a = arr->body;

  int i = lo;
  int j = hi + 1;
  
  int K = a[lo];

  while (1) {
    while (a[++i] < K) {
      if (i == hi) break;
    }
    while (a[--j] > K) {
      if (j == lo) break;
    }

    if (i >= j) break;

    /* Swap */ {
      if (VISUALIZE_MODE) print_ia(a, lo, hi, i, j);
      int tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
    }
  }

  /* Swap */ {
    if (VISUALIZE_MODE) print_ia(a, lo, hi, i, j);
    int tmp = a[lo];
    a[lo] = a[j];
    a[j] = tmp;
  }

  return j;
}

void quick_sort(IA arr, SortContext *ctx) {
  int_array_shuffle(arr);
  inner_quick_sort_core(arr, 0, arr->capacity - 1);
}

/********** Private Functions **************/

private_func void exch(IA arr, int a, int b, SortContext *ctx) {
  if (a > arr->capacity - 1 || b > arr->capacity - 1) {
    if (DEBUG_MODE) {
      __ERROR("Array Index out bound!");
      __INFO("At exchange [%d] <--> [%d] with range: [0, %d]\n", a, b,
             arr->capacity - 1);
    }
    exit(ER100_ARRAY_INDEX_OUT_OF_BOUND);
  }

  if (ctx != NULL)
    ctx->exchanges++;

  int tmp = arr->body[a];
  arr->body[a] = arr->body[b];
  arr->body[b] = tmp;
}

private_func bool less(IA arr, int a, int b, SortContext *ctx) {
  if (a > arr->capacity - 1 || b > arr->capacity - 1) {
    if (DEBUG_MODE) {
      __ERROR("Array Index out bound!");
      __INFO("At exchange [%d] <--> [%d] with range: [0, %d]\n", a, b,
             arr->capacity - 1);
    }
    exit(ER100_ARRAY_INDEX_OUT_OF_BOUND);
  }

  if (ctx != NULL)
    ctx->comparisons++;

  if (arr->body[a] < arr->body[b])
    return true;
  else
    return false;
}

private_func void print_seperator() {
  printf(" ");
  printf(BACKGROUND_PRINT_BEGIN);
  printf("|");
  printf(BACKGROUND_PRINT_END);
  printf(" ");
}
