#pragma once
#include "../debug.h"
#include "../fia/fia.h"

#define ON 1
#define OFF 0
#define ANALYSIS_MODE OFF
#define VISUALIZE_MODE ON

typedef void (*Behavior)(void);
typedef void (*ArrayProcessor)(IA arr, Behavior be);
typedef ArrayProcessor Sorter;

void analysis();
void selection_sort(IA arr, Behavior be);
void insertion_sort(IA arr, Behavior be);
void shell_sort(IA arr, Behavior be);
