#pragma once

#include "../fia/fia.h"
#include "../debug.h"

#ifndef public_func
#define public_func
#endif

#ifndef private_func
#define private_func static
#endif

#ifndef T
#define T int
#endif

#define self Stack sta

struct stack;
typedef struct stack* Stack;

Stack sta_new();
Stack sta_new_with_capacity(int capacity);
EXEC_STATUS sta_destroy(self);

void sta_push(self, T val);
T sta_pop(self);
void sta_reset(self);

int sta_get_size(self);
int sta_get_capacity(self);
