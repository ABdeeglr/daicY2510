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
}
