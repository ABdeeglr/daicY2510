#include "fia/fia.h"
#include "fsort/fsort.h"
#define DEBUG 1

int main(const int argc, const char *argv[]) {

  IA arr = int_array_create(26);
  int_array_fill_random_with_bound(arr, 300);

  insertion_sort(arr, NULL);
  
  int_array_destroy(arr);
  

  arr = int_array_create(26);
  int_array_fill_random_with_bound(arr, 300);

  selection_sort(arr, NULL);
  
  int_array_destroy(arr);
  return 0;
}
