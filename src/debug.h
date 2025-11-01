#ifndef __FBOOM__
#define __FBOOM__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

#ifndef DEBUG
#define __DEBUG(Msg, ...)
#define __WARNING(Msg, ...)
#define __ERROR(Msg, ...)
#define __PRINT
#else
/* Debug Print. Msg send to stderr*/
#define __DEBUG(Msg, ...) fprintf(stderr, "\033[36m[DEBUG]\033[0m %s: (%d):" #Msg "\n", __FILE__, __LINE__,  ##__VA_ARGS__);
/* Warning message send to stderr*/
#define __WARNING(Msg, ...) fprintf(stderr, "\033[43m[WARNI]\033[0m %s: (%d):" #Msg "\n", __FILE__, __LINE__,  ##__VA_ARGS__);
/* Error message send to stderr*/
#define __ERROR(Msg, ...) fprintf(stderr, "\033[41m[ERROR]\033[0m %s: (%d):" #Msg "\n", __FILE__, __LINE__,  ##__VA_ARGS__);
#define __PRINT printf
#endif

// malloc 函数的宏写法，仍然需要 free 函数回收
#define fObMalloc(T) (struct T *) malloc(sizeof(struct T))
#define fMalloc(T, nums) (T*) calloc(nums, sizeof(T))
#define NewFunctionType(FT_NAME, RETURN_TYPE, ...) typedef RETURN_TYPE (*FT_NAME)(__VA_ARGS__)

typedef int i32;
typedef char u8;
typedef long i64;
typedef unsigned int u32;
typedef unsigned long u64;

#endif
