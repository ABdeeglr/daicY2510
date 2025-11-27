#include "./analysis/fsort_analysis.h"
#include "fia/fia.h"
#include "fsort/fsort.h"

int main(const int argc, const char *argv[]) {

  // sub_analysis_2_ordered_array_analysis(25, 5);
  // fsort_analyer(shell_sort, 3000000, 10);

  IA arr = int_array_create(30);
  int_array_fill_random_with_bound(arr, 500);
  selection_sort(arr, NULL);
  int_array_destroy(arr);

  arr = int_array_create(30);
  int_array_fill_random_with_bound(arr, 500);
  insertion_sort(arr, NULL);
  int_array_destroy(arr);

  return 0;
}
