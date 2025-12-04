#include "./analysis/fsort_analysis.h"
#include "fsort/fsort.h"

int main(const int argc, const char *argv[]) {

  int d = atoi(argv[1]);

  // multi_scale_fsort_analyer(quick_sort, 4096, d);
  single_scale_fsort_analyer(quick_sort, 4096 << d,  10);

  // int initial_size = 32;

  // int d = atoi(argv[1]);
  // single_scale_fsort_analyer(shell_sort, initial_size << d, 3);
  // single_scale_fsort_analyer(selection_sort, initial_size << d, 3);
  // single_scale_fsort_analyer(insertion_sort, initial_size << d, 3);
  
  return 0;
}
