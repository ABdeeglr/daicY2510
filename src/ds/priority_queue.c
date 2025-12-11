/**
 * 优先队列的其中一种实现
 * @Author: ABdeeglr Ramsay
 * @Email : abdeeglr@icloud.com
 */
#include "./priority_queue.h"

struct priority_queue {
};

/**************** Public Function ****************/
public_func PriorityQueue pq_new() {
  return NULL;
}

public_func PriorityQueue pq_new_with_max_capacity(int max) {
  return NULL;
}

public_func PriorityQueue pq_new_by_int_array(IA arr) {
  return NULL;
}

public_func EXEC_STATUS pq_delete(PriorityQueue pq_instance) {
  return SUCCESS;
}

public_func EXEC_STATUS pq_insert(PriorityQueue pq_instance, T t) {
  return FAIL;
}

public_func T pq_max(PriorityQueue pq_instance) {
  return 0;
}

public_func T pq_del(PriorityQueue pq_instance) {
  return 0;
}

public_func bool pq_isEmpty(PriorityQueue pq_instance) {
  return true;
}

public_func int pq_size(PriorityQueue pq_instance) {
  return 0;
}

/**************** Private Function ****************/
