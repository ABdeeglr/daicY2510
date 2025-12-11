/**
 * 优先队列的其中一种实现
 * @Author: ABdeeglr Ramsay
 * @Email : abdeeglr@icloud.com
 */
#pragma once
#include "../fia/fia.h"
#include "../debug.h"

#ifndef public_func
#define public_func
#endif

#ifndef private_func
#define private_func static
#endif

#define T int

struct priority_queue;

typedef struct priority_queue* PriorityQueue;
typedef PriorityQueue PQ;

PriorityQueue pq_new();
PriorityQueue pq_new_with_max_capacity(int max);
PriorityQueue pq_new_by_int_array(IA arr);

EXEC_STATUS pq_delete(PriorityQueue pq_instance);
EXEC_STATUS pq_insert(PriorityQueue pq_instance, T t);

T pq_max(PriorityQueue pq_instance);
T pq_del(PriorityQueue pq_instance);

bool pq_isEmpty(PriorityQueue pq_instance);
int pq_size(PriorityQueue pq_instance);
