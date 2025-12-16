#include "./stack.h"
#include <stdlib.h>

struct stack {
  int head;
  int capacity;
  T* body;
};

public_func Stack sta_new() {
  Stack p = sta_new_with_capacity(20);
  return p;
}

public_func Stack sta_new_with_capacity(int capacity) {
  Stack res = (Stack) malloc(sizeof(struct stack));
  res->capacity = capacity;
  res->head = 0;
  res->body = (T*) calloc(capacity, sizeof(T));
  return res; 
}

public_func EXEC_STATUS sta_destroy(self) {
  if (sta == NULL) {
    return ER200_DOUBLE_FREE;
  }

  if (sta->body == NULL) {
    return ER200_DOUBLE_FREE;
  }

  free(sta->body);
  free(sta);
  return SUCCESS;
}

public_func void sta_push(self, T val) {
  
}

public_func T sta_pop(self) {
  if (sta->head == 0) {
    return 0;
  }

  return sta->body[--sta->head];
}

private_func void sta_resize(self, int capacity) {
  return;
}


public_func void sta_reset(self) {
  sta->head = 0;
}

public_func int sta_get_size(self) {
  return sta->head;
}

public_func int sta_get_capacity(self) {
  return sta->capacity;
}
