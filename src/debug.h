#pragma once

#include <stdio.h>

#ifndef DEBUG_MODE
#define DEBUG_MODE 0
#endif

#if DEBUG_MODE
#define __INFO(Msg, ...) fprintf(stderr, "\033[36m==[ INFO]==\033[0m %s: (%d):" #Msg "\n", __FILE__, __LINE__,  ##__VA_ARGS__);
#define __WARNING(Msg, ...) fprintf(stderr, "\033[43m==[ WARN]==\033[0m %s: (%d):" #Msg "\n", __FILE__, __LINE__,  ##__VA_ARGS__);
#define __ERROR(Msg, ...) fprintf(stderr, "\033[41m==[ERROR]==\033[0m %s: (%d):" #Msg "\n", __FILE__, __LINE__,  ##__VA_ARGS__);
#else
#define __INFO(Msg, ...)
#define __WARNING(Msg, ...)
#define __ERROR(Msg, ...)
#endif

enum status {
  FAIL = 0,
  SUCCESS = 1,
  ER050_RUN_OUT_OF_MEMORY = 50,
  ER100_ARRAY_INDEX_OUT_OF_BOUND = 100,
  ER200_DOUBLE_FREE = 200,
  ER201_FREE_ON_NOHEAP_OBJECT = 201,
};

typedef enum status EXEC_STATUS;
typedef enum status ERROR_CODE;


#define BACKGROUND_PRINT_BEGIN "\033[7m\033[34m"
#define BACKGROUND_PRINT_END "\033[0m\033[0m"

#define DIM_PRINT_BEGIN "\033[2m"
#define DIM_PRINT_END "\033[0m"

#define RED_PRINT_BEGIN "\033[31m"
#define RED_PRINT_END "\033[0m"

#define BLUE_PRINT_BEGIN "\033[32m"
#define BLUE_PRINT_END "\033[0m"

#define YELLOW_PRINT_BEGIN "\033[33m"
#define YELLOW_PRINT_END "\033[0m"

#define AQUA_PRINT_BEGIN "\033[34m"
#define AQUA_PRINT_END "\033[0m"

#define PURPLE_PRINT_BEGIN "\033[35m"
#define PURPLE_PRINT_END "\033[0m"

#define UNDERLINE_PRINT_BEGIN "\033[4m\033[31m"
#define UNDERLINE_PRINT_END "\033[0m\033[0m"
