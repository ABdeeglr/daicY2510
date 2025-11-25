/**
 * The core of this src file you should know is 2 or more sort algorithm
 * These core functions are marked by a MACRO: public_func
 * And these marked by the MACRO: private_func, although you can use because C
 *   doesn't support encapsulation, but is recommended not to use anyway.
 *
 * Author: ABdeeglr Ramsay
 * Email: abdeeglr@icloud.com
 * Number: +114 514-1919-810 XD
 */

#include "./fsort.h"
#include <stdbool.h>

#ifndef public_func
#define public_func
#endif

#ifndef private_func
#define private_func
#endif

int __fsrt_global_counter = 0;

private_func void exch(IA arr, unsigned a, unsigned b);
private_func bool less(IA arr, unsigned a, unsigned b);
private_func void reset_counter();
private_func void read_counter();
private_func void add_counter();


public_func void selection_sort(IA arr, Behavior be) {

  if (ANALYSIS_MODE) {
    be();
  }
  return;
}

public_func void insertion_sort(IA arr, Behavior be) {

  if (ANALYSIS_MODE) {
    be();
  }
  return;
}

private_func void exch(IA arr, unsigned a, unsigned b) {
  if (a > arr->capacity - 1 || b > arr->capacity - 1) {
    __ERROR("Array Index out bound!");
    __ERROR("At exchange [%d] <--> [%d] with range: [0, %d]\n", a, b, arr->capacity-1);
    exit(1);
  }
  add_counter();
  int tmp = arr->body[a];
  arr->body[a] = arr->body[b];
  arr->body[b] = tmp;
}


private_func bool less(IA arr, unsigned a, unsigned b) {
  if (a > arr->capacity - 1 || b > arr->capacity - 1) {
    __ERROR("Array Index out bound!");
    __ERROR("At exchange [%d] <--> [%d] with range: [0, %d]\n", a, b, arr->capacity-1);
    exit(1);
  }

  if (arr->body[a] < arr->body[b]) return true;
  else return false;
}

private_func void add_counter() {
  __fsrt_global_counter++;
}

private_func void reset_counter() {
  __fsrt_global_counter = 0;
}

private_func void read_counter() {
  printf("Exec Counter: %d\n", __fsrt_global_counter);
}

public_func void analysis() {
  read_counter();
  reset_counter();  
}
