#pragma once

#include <stdio.h>

#ifndef DEBUG_MODE
#define DEBUG_MODE 0
#endif

#if DEBUG_MODE
#define __INFO(Msg, ...) fprintf(stderr, "\033[36m[INFO ]\033[0m %s: (%d):" #Msg "\n", __FILE__, __LINE__,  ##__VA_ARGS__);
#define __WARNING(Msg, ...) fprintf(stderr, "\033[43m[WARN ]\033[0m %s: (%d):" #Msg "\n", __FILE__, __LINE__,  ##__VA_ARGS__);
#define __ERROR(Msg, ...) fprintf(stderr, "\033[41m[ERROR]\033[0m %s: (%d):" #Msg "\n", __FILE__, __LINE__,  ##__VA_ARGS__);
#else
#define __INFO(Msg, ...)
#define __WARNING(Msg, ...)
#define __ERROR(Msg, ...)
#endif

enum status {
  FAIL = 0,
  SUCCESS = 1,
  ARRAY_INDEX_OUT_OF_BOUND = 100,
  DOUBLE_FREE = 200,
  FREE_ON_NOHEAP_OBJECT = 201,
};

typedef enum status STATUS;
typedef enum status ERROR_CODE;


#define BACKGROUND_PRINT_BEGIN "\033[7m\033[34m"
#define BACKGROUND_PRINT_END "\033[0m\033[0m"

#define DIM_PRINT_BEGIN "\033[2m"
#define DIM_PRINT_END "\033[0m"

#define UNDERLINE_PRINT_BEGIN "\033[4m\033[31m"
#define UNDERLINE_PRINT_END "\033[0m\033[0m"
