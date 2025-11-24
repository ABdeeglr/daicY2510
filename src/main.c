#include "fia/fia.h"
#define DEBUG 1

int main(const int argc, const char *argv[]) {
  IA arr = int_array_create(20);
  int_array_fill_random_with_bound(arr, 10000);
  int_array_print(arr);
  int_array_reverse(arr);
  int_array_print(arr);
  int_array_shuffle(arr);
  int_array_print(arr);
  printf("Is ordered? %d %d\n", int_array_is_ordered_desc(arr), int_array_is_ordered_asc(arr));
  int_array_destroy(arr);  

  arr = int_array_create(10);
  int_array_fill_random_with_bound(arr, 30);
  int_array_print(arr);

  IA test = int_array_slice(arr, 2, 4);
  int_array_print(test);

  test = int_array_slice(arr, 0, 5);
  int_array_print(test);

  test = int_array_slice(arr, 5, 10);
  int_array_print(test);
  
  int_array_destroy(test);
  int_array_destroy(arr);
}
