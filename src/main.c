#include "fia/fia.h"
#include "fsort/fsort.h"
#define DEBUG 1

int main(const int argc, const char *argv[]) {

  int N = 1000;

  // for (int i = 0; i < 5; i++) {
  //   printf("%3d -->", N << i);
  // }
  // printf("\n");
  
  IA arr;
  int bound;
  for (int i = 0; i <= 5; i++) {
    bound = N << (i + 1);
    arr = int_array_create(N << i);
    int_array_fill_random_with_bound(arr, bound);
    int_array_print(arr);
    shell_sort(arr, NULL);
    int_array_print(arr);
    int_array_destroy(arr);
  }
  
  return 0;
}
