#include "./analysis/fsort_analysis.h"

int main(const int argc, const char *argv[]) {

  // multi_scale_fsort_analyer(merge_sort, 4096, 10);

  int initial_size = 32;

  int d = atoi(argv[1]);
  single_scale_fsort_analyer(shell_sort, initial_size << d, 3);
  single_scale_fsort_analyer(selection_sort, initial_size << d, 3);
  single_scale_fsort_analyer(insertion_sort, initial_size << d, 3);
  
  return 0;
}
