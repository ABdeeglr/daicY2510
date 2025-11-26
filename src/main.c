#include "./analysis/fsort_analysis.h"

int main(const int argc, const char *argv[]) {
  fsort_analyer(selection_sort, 1000, 10);
  
  fsort_analyer(insertion_sort, 1000, 10);
  
  return 0;
}
