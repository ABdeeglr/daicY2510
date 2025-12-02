#pragma once
#include "../fsort/fsort.h"

long array_processor_timing(ArrayProcessor alg, IA arr);
long single_scale_fsort_analyer(ArrayProcessor alg, int scale, int round);
void multi_scale_fsort_analyer(ArrayProcessor alg, int initiali_scale, int expand_times);

