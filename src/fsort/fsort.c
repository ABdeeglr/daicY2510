/**
 * @Author: ABdeeglr
 * @Ramsay Email: abdeeglr@icloud.com
 * @Number: +114 514-1919-810 XD
 */

#include "./fsort.h"

#ifndef LIMITED
#define LIMITED 16
#endif

private_func void inner_merge_sort_core(IA arr, int *tmp, int lo, int hi);
private_func void merge(IA arr, int *tmp, int lo, int mid, int hi);

private_func void inner_quick_sort_core(IA arr, int lo, int hi);
private_func int partion(IA arr, int lo, int hi);

// private_func void print_ia(int* arr, int start, int end, int a, int b);


/********** Public Functions **************/

public_func void merge_sort(IA arr, SortContext *ctx) {

  int *tmp = (int *)calloc(arr->capacity, sizeof(int));

  inner_merge_sort_core(arr, tmp, 0, arr->capacity - 1);

  free(tmp);
}

public_func void quick_sort(IA arr, SortContext *ctx) {
  int_array_shuffle(arr);
  inner_quick_sort_core(arr, 0, arr->capacity - 1);
}

/********** Private Functions **************/

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
      int tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
    }
  }

  /* Swap */ {
    int tmp = a[lo];
    a[lo] = a[j];
    a[j] = tmp;
  }

  return j;
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

private_func void inner_quick_sort_core(IA arr, int lo, int hi) {
  if (hi <= lo) return;
  int j = partion(arr, lo, hi);
  inner_quick_sort_core(arr, lo, j - 1);
  inner_quick_sort_core(arr, j + 1, hi);
}


// private_func void print_ia(int* arr, int start, int end, int a, int b) {
//   printf("[");
//   for (int i = start; i < end - 1; i++) {
//     if (i == a || i == b) {
//       printf(RED_PRINT_BEGIN);
//       printf("%d, ", *(arr + i));
//       printf(RED_PRINT_END);
//     } else printf("%d, ", *(arr + i));
//   }
//   if (end - 1 == a || end - 1 == b) {
//     printf(RED_PRINT_BEGIN);
//     printf("%d]", *(arr + end - 1));
//     printf(RED_PRINT_END);
//   } else printf("%d]", *(arr + end - 1));
//   printf("\n");
// }
