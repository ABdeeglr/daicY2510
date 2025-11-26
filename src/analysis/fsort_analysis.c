#include "./fsort_analysis.h"
#include <unistd.h>

long array_processor_timing(ArrayProcessor alg, IA arr) {
    clock_t start = clock();
    alg(arr, NULL);
    clock_t end = clock();
    clock_t diff = end - start;
    return (long) diff;
}

void fsort_analyer(ArrayProcessor alg, int scale, int round) {
  printf("\033[2mMake sure you switch the MACRO: VISUALIZE_MODE and ANALYSIS_MODE OFF.\033[0m\n");
  printf("\033[2mOtherwise the actual runtime cost maybe longer than supposed.\033[0m\n");

  printf("Analyzer Data Scale: %d\n", scale);
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
  
  printf("Total CPU Costs In \033[31m%d\033[0m rounds: \033[31m%ld mils\033[0m\n", round, total/1000);
  printf("Total CPU Costs Average: \033[31m%ld mils\033[0m\n", total/1000 / round);
}

/**
 * 测试插入排序在 2-有序数组 上的性能表现，作为理解 shell 排序加速原理的突破口尝试。
 */
void sub_analysis_2_ordered_array_analysis(int scale, int round) {
  
  printf("\033[2mMake sure you switch the MACRO: VISUALIZE_MODE and ANALYSIS_MODE **ON**.\033[0m\n");
  int i = 1;
  long total = 0;
  int scale_div = scale * 2;
  do {
    IA arr = int_array_create(scale);
    srand((unsigned) time(NULL));
    arr->body[0] = 19;
    arr->body[1] = 40;
    for (int j = 2; j < scale; j += 2) {
      arr->body[j] = arr->body[j - 2] + rand() % scale_div;
      arr->body[j+1] = arr->body[j - 1] + rand() % scale_div;
    }
    sleep(1);
    long times = array_processor_timing(insertion_sort, arr);

    int_array_destroy(arr);

    printf("Round: %d CPU Costs: %ld mils\n", i, times/1000);
    total+= times;
  } while (i++ < round);
  printf("Total CPU Costs In \033[31m%d\033[0m rounds: \033[31m%ld mils\033[0m\n", round, total/1000);
  printf("Total CPU Costs Average: \033[31m%ld mils\033[0m\n", total/1000 / round);
}
