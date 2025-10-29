// src/fia/fia.h
// Created At 2025-10-24:23:20:10
// Author: ABdeeglr Ramsay

#ifndef __FIA_H__
#define __FIA_H__

#define MACRO_X 1

struct int_array {
  int* body;
  unsigned int size;
};

typedef struct int_array* IntArray;
typedef IntArray IA;



/**
 *   Int Array Builder and Destoryer
 *
 *
 */
IntArray IA_Builder(unsigned int length);
IntArray IA_StackBuilder(unsigned int length);
void IA_Destoryer(IA ia);

/**
 *    Utils Function For Int Array
 */
int IA_getLength(IA ia);
int IA_setValue(IA ia, unsigned int position, int value);
void IA_zeroes(IA ia);



#endif
