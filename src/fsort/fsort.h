#pragma once
#include "../debug.h"
#include "../switchers.h"
#include "../fia/fia.h"

#ifndef public_func
#define public_func
#endif

#ifndef private_func
#define private_func
#endif

typedef void (*Behavior)(void);
typedef void (*ArrayProcessor)(IA arr, Behavior be);
typedef ArrayProcessor Sorter;

void selection_sort(IA arr, Behavior be);
void insertion_sort(IA arr, Behavior be);
void shell_sort(IA arr, Behavior be);

void analysis();
