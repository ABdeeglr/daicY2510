#include "fia/fia.h"
#include "fsort/fsort.h"
#define DEBUG 1

int main(const int argc, const char *argv[]) {

  IA arr = int_array_create(30);
  int_array_fill_random_with_bound(arr, 300);

  int_array_print(arr);
  shell_sort(arr, NULL);
  
  int_array_print(arr);
  int_array_destroy(arr);
  
  return 0;
}
