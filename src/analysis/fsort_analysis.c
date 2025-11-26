#include "./fsort_analysis.h"

long array_processor_timing(ArrayProcessor alg, IA arr) {
    clock_t start = clock();
    alg(arr, NULL);
    clock_t end = clock();
    clock_t diff = end - start;
    return (long) diff;
}

void fsort_analyer(ArrayProcessor alg, int scale, int round) {
  printf("Make sure you switch the MACRO: VISUALIZE_MODE and ANALYSIS_MODE OFF.\n");
  printf("Otherwise the actual runtime cost maybe longer than supposed.\n");

  int i = 1;
  long total = 0;

  do {
    IA arr = int_array_create(scale);
    int_array_fill_random_with_bound(arr, scale * 10);

    long times = array_processor_timing(alg, arr);

    int_array_destroy(arr);

    printf("Round: %d CPU Costs: %ld mils\n", i, times/1000);
    total+= times;
  } while (i++ < round);
  
  printf("Total CPU Costs In %d rounds: %ld mils\n", round, total/1000);
}
