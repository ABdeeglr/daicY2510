#include "./fsort_analysis.h"
#include <stdio.h>
#include <time.h>
#include <unistd.h>



public_func long array_processor_timing(ArrayProcessor alg, IA arr) {
    clock_t start = clock();
    alg(arr, NULL);
    clock_t end = clock();
    clock_t diff = end - start;
    return (long) diff;
}

public_func long single_scale_fsort_analyer(ArrayProcessor alg, int scale, int round) {
  if (VISUALIZE_MODE) {
    printf(UNDERLINE_PRINT_BEGIN);
    printf("Make sure you switch the MACRO: VISUALIZE_MODE and ANALYSIS_MODE OFF.\n");
    printf("Or in debug mode will not run this script\n");
    printf(UNDERLINE_PRINT_END);
    return 0;
  }

  printf(BACKGROUND_PRINT_BEGIN);
  printf("= = = = = = = = = = = = = = = = = =\n");
  printf("= = = = = = = = = = = = = = = = = =\n");
  printf(BACKGROUND_PRINT_END);
  printf("Analyzer Data Scale: %d\n", scale);
  int i = 1;
  long total_time = 0;
  uint64_t total_comparisons = 0;
  uint64_t total_exchanges = 0;
  
  do {
    IA arr = int_array_create(scale);
    int_array_fill_random_with_bound(arr, scale * 10);
    
    SortContext ctx = {0, 0};

    clock_t start = clock();
    alg(arr, &ctx);
    clock_t end = clock();

    long times = (long) (end - start);

    if (int_array_is_ordered_asc(arr)) {
      __INFO("Sort Corrected!");
    } else {
      __WARNING("This sort method something wrong.");
    }

    printf("Round: %d CPU Costs: %ld mils\n", i, times/1000);
    total_time+= times;
    total_comparisons += ctx.comparisons;
    total_exchanges += ctx.exchanges;

    int_array_destroy(arr);

  } while (i++ < round);

  long average = total_time / 1000 / round;
  printf("Total CPU Costs In \033[31m%d\033[0m rounds: \033[31m%ld mils\033[0m\n", round, total_time/1000);
  printf("Total CPU Costs Average: \033[31m%ld mils\033[0m\n", average);
  printf("Average Comparisons: \033[31m%lu\033[0m\n", total_comparisons / round);
  printf("Average Exchanges: \033[31m%lu\033[0m\n", total_exchanges / round);

  printf(BACKGROUND_PRINT_BEGIN);
  printf("= = = = = = = = = = = = = = = = = =\n");
  printf("= = = = = = = = = = = = = = = = = =\n\n");
  printf(BACKGROUND_PRINT_END);

  return average;
}

public_func void multi_scale_fsort_analyer(ArrayProcessor alg,int initial_scale, int expand_times) {
  if (VISUALIZE_MODE || ANALYSIS_MODE) {
    printf(UNDERLINE_PRINT_BEGIN);
    printf("Make sure you switch the MACRO: VISUALIZE_MODE and ANALYSIS_MODE OFF.\n");
    printf("Or in debug mode will not run this script\n");
    printf(UNDERLINE_PRINT_END);
    return;
  }

  if (expand_times > 18) {
    __INFO("Too large scale in the end");
    return;
  }
  long avgs[expand_times];

  for (int i = 0; i < expand_times; i++) {
    avgs[i] = single_scale_fsort_analyer(alg, initial_scale << i, 5);
  }
  
  for (int i = 0; i < expand_times; i++) {
  printf(BACKGROUND_PRINT_BEGIN);
    printf("%ld mils\n", avgs[i]);
  printf(BACKGROUND_PRINT_END);
  }
}

/**
 * 测试插入排序在 2-有序数组 上的性能表现，作为理解 shell 排序加速原理的突破口尝试。
 */
// private_func void sub_analysis_2_ordered_array_analysis(int scale, int round) {
  
//   printf("\033[2mMake sure you switch the MACRO: VISUALIZE_MODE and ANALYSIS_MODE **ON**.\033[0m\n");
//   int i = 1;
//   long total = 0;
//   int scale_div = scale * 2;
//   do {
//     IA arr = int_array_create(scale);
//     srand((unsigned) time(NULL));
//     arr->body[0] = 19;
//     arr->body[1] = 40;
//     for (int j = 2; j < scale; j += 2) {
//       arr->body[j] = arr->body[j - 2] + rand() % scale_div;
//       arr->body[j+1] = arr->body[j - 1] + rand() % scale_div;
//     }
//     sleep(1);
//     long times = array_processor_timing(insertion_sort, arr);

//     int_array_destroy(arr);

//     printf("Round: %d CPU Costs: %ld mils\n", i, times/1000);
//     total+= times;
//   } while (i++ < round);
//   printf("Total CPU Costs In \033[31m%d\033[0m rounds: \033[31m%ld mils\033[0m\n", round, total/1000);
//   printf("Total CPU Costs Average: \033[31m%ld mils\033[0m\n", total/1000 / round);
// }
