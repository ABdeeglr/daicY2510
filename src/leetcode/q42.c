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

void example_test_1(IA arr) {
  int res = solution(arr);
  int_array_destroy(arr);
  printf("The result of example 1 is: %d\n", res);
}

// 和 Gemini 沟通之后的三遍历法：

int getMax(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}

int getMin(int a, int b) {
  if (a > b)
    return b;
  else
    return a;
}

IA getLeftMax(IA height) {
  if (height == NULL || height->capacity == 0) {
    return NULL;
  }
  u32 n = height->capacity;
  IA leftMax = int_array_create(n);

  leftMax->body[0] = height->body[0];

  for (int i = 1; i < n; i++) {
    leftMax->body[i] = getMax(leftMax->body[i - 1], height->body[i]);
  }
  int_array_print(leftMax);
  return leftMax;
}

IA getRightMax(IA height) {
  if (height == NULL || height->capacity == 0) {
    return NULL;
  }
  u32 n = height->capacity;
  IA rightMax = int_array_create(n);

  rightMax->body[n - 1] = height->body[n - 1];

  for (int i = n - 2; i >= 0; i--) {
    rightMax->body[i] = getMax(rightMax->body[i + 1], height->body[i]);
  }
  int_array_print(rightMax);
  return rightMax;
}

int solution(IA height) {

  IA left_max = getLeftMax(height);
  IA right_max = getRightMax(height);

  int sum = 0;
  int tmp = 0;
  for (int i = 0; i < height->capacity; i++) {
    tmp = getMin(left_max->body[i], right_max->body[i]) - height->body[i];
    printf("The water on position $%d is %d\n", i, tmp);
    sum += tmp;
  }

  int_array_destroy(left_max);
  int_array_destroy(right_max);

  return sum;
}
