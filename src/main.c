#include "./analysis/fsort_analysis.h"

int main(const int argc, const char *argv[]) {
  
  printf("\n\nStart Selection Sort Ananyzer.\n");
  fsort_analyer(selection_sort, 10000, 5);
  printf("\n\nStart Shell Sort Ananyzer.\n");
  fsort_analyer(shell_sort, 1000000, 5);
  return 0;
}
