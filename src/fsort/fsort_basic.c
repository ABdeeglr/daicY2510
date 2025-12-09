/**
 * 提供选择排序、插入排序和希尔排序等基础排序算法.
 *
 * Function List:
 * 1. selection_sort();
 * 2. insertion_sort();
 * 3. shell_sort();
 * 4. exch();
 * 5. less();
 * 6. print_seperator();
 * 
 * 其中选择排序和插入排序可以通过宏 VISUALIZE_MODE 开启可视化模式。
 * 私有函数中，exch 和 less 可以提供比较次数和交换次数统计。
 * print_seperator 函数则仅仅是为了辅助可视化模式。
 * 
 * @Author: ABdeeglr
 * @Ramsay Email: abdeeglr@icloud.com
 * @Number: +114 514-1919-810 XD
 */

#include "./fsort.h"

private_func void exch(IA arr, int a, int b, SortContext *ctx);
private_func bool less(IA arr, int a, int b, SortContext *ctx);
private_func void print_seperator();

/**************** Public Function *****************/

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

