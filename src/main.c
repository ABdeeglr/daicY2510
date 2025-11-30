#include "./analysis/fsort_analysis.h"

int main(const int argc, const char *argv[]) {

  // multi_scale_fsort_analyer(merge_sort, 4096, 10);

  int d = atoi(argv[1]);
  single_scale_fsort_analyer(merge_sort, 1024 << d, 3);

  
  return 0;
}
