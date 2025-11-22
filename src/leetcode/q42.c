#include "./q42.h"

/*
  一个比较简单的终止条件是数组两侧为最值

  可以被描述为:
```c
for (int i = 1; i < array.lenth() - 1; i++) {
  if (array[i] < array[0] && array[i] < array[array.length()]) continue;
  else return false;
  return true;
}
```
满足以上条件的数组就是最基本的形态，需要对这个数据进行求解，计算它的能够承载的水量
*/
int q42_basic_condition_get_result(int *array, u32 length) {
  int height = *array;
  if (*(array + length - 1) < height) {
    height = *(array + length - 1);
  }
  int sum = 0;

  for (int i = 1; i < length - 1; i++) {
    sum += (height - *(array + i));
  }
  return sum;
}

int base_condition_criteria(int *arr, u32 len) {
  int left = *arr;
  int right = *(arr + len - 1);
  int mid = left;
  if (right < mid)
    mid = right;

  for (int i = 1; i < len - 1; i++) {
    if (*(arr + i) < mid)
      continue;
    else
      return 0;
  }
  return 1;
}

/*
  由此，下一步是如何对一个非基本形态的数组进行分割.
  看来，这一步就是最困难的部分了，如何把一个数组分割为若干基本条件数组？

  在一个数组中，存在基本条件数组的判定条件是：
  1. 存在两个点，内部的严格小；
  2. 外部的小于或等于；

  有没有可能通过差分的方式？唉，原来这里才是最难的部分。
  能不能从最大的向内缩，找到...
*/

void example_test_1() {
  int arr[] = {4, 2, 0, 3, 2, 5};
  u32 len = 6;
  int res = q42_basic_condition_get_result(arr, len);
  printf("The result of example 1 is: %d\n", res);
}
