#pragma once
#include "../debug.h"
#include "../fia/fia.h"

typedef void (*Behavior)(void);
typedef void (*ArrayProcessor)(IA arr, Behavior be);
typedef ArrayProcessor Sorter;

void selection_sort(IA arr, Behavior be);

void insertion_sort(IA arr, Behavior be);

