#include "./analysis/fsort_analysis.h"
#include "fsort/fsort.h"

int main(const int argc, const char *argv[]) {

  int d = 1;
  if (argc == 2) {
    d = atoi(argv[1]);
  }

  int initial_size = 4096;

  single_scale_fsort_analyer(quick_sort, initial_size << d,  10);
  single_scale_fsort_analyer(shell_sort, initial_size << d, 3);
  single_scale_fsort_analyer(selection_sort, initial_size << d, 3);
  single_scale_fsort_analyer(insertion_sort, initial_size << d, 3);


  // multi_scale_fsort_analyer(quick_sort, 4096, d);
  return 0;
}
