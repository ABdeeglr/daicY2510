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

int __fsrt_global_counter = 0;

private_func void exch(IA arr, int a, int b);
private_func bool less(IA arr, int a, int b);
private_func void reset_counter();
private_func void read_counter();
private_func void add_counter();
private_func void print_seperator();
private_func void ft2d_merge(IA arr);
private_func void fd2t_merge(IA arr);



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
        if (less(arr, j, min))
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
      exch(arr, i, min);
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
        if (less(arr, j, min))
          min = j;
      }

      // After we find the smallest element's index, exchange it
      exch(arr, i, min);
    }
  }

  if (ANALYSIS_MODE) {
    if (be != NULL)
      be();
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

      for (int j = i; j > 0 && less(arr, j, j - 1); j--) {
        exch(arr, j, j - 1);
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
      for (int j = i; j > 0 && less(arr, j, j - 1); j--) {
        exch(arr, j, j - 1);
      }
    }
  }

  if (ANALYSIS_MODE) {
    if (be != NULL)
      be();
  }
  return;
}

public_func void shell_sort(IA arr, Behavior be) {
<<<<<<< HEAD

  if (VISUALIZE_MODE) {
    printf("\n= = = 正在进行希尔排序可视化 = = =\n");
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
    for (int i = h; i < N; i++) { // TODO: not understand now...
      for (int j = i; j >= h && less(arr, j, j - h); j -= h) {
        if (VISUALIZE_MODE) {
          printf("%2d %2d ||", j, i);
          for (int k = 0; k < arr->capacity; k++) {
            if (k <= i && k >= j)
              printf("\033[2m%4d\033[0m", arr->body[k]);
            else
              printf("%4d", arr->body[k]);
          }
          printf("\n");
        }
        exch(arr, j, j - h);
      }
    }
    h = h / 3;
  }

  if (be != NULL) {
=======
  if (ANALYSIS_MODE) {
    
  }
  else {
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
      for (int i = h; i < N; i++) { // TODO: not understand now...
        for (int j = i; j >= h && less(arr, j, j - h); j -= h) {
          exch(arr, j, j - h);
        }
      }
      h = h / 3;
    }
  }
  if (ANALYSIS_MODE && (be != NULL)) {
>>>>>>> sort
    be();
  }
}

private_func void exch(IA arr, int a, int b) {
  if (a > arr->capacity - 1 || b > arr->capacity - 1) {
    __ERROR("Array Index out bound!");
    __ERROR("At exchange [%d] <--> [%d] with range: [0, %d]\n", a, b,
            arr->capacity - 1);
    exit(-1);
  }
  add_counter();
  int tmp = arr->body[a];
  arr->body[a] = arr->body[b];
  arr->body[b] = tmp;
}

private_func bool less(IA arr, int a, int b) {
  if (a > arr->capacity - 1 || b > arr->capacity - 1) {
    __ERROR("Array Index out bound!");
    __ERROR("At exchange [%d] <--> [%d] with range: [0, %d]\n", a, b,
            arr->capacity - 1);
    exit(-1);
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

private_func void print_seperator() {
  printf(" ");
  printf(BACKGROUND_PRINT_BEGIN);
  printf("|");
  printf(BACKGROUND_PRINT_END);
  printf(" ");
}
