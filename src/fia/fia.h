// src/fia/fia.h
// Created At 2025-10-24:23:20:10
// Author: ABdeeglr Ramsay

#ifndef __FIA_H__
#define __FIA_H__
#include <stdbool.h>

#define public_func
#define private_func
#define friend_func

typedef unsigned int ia_index;

struct int_array {
  int *body;
  ia_index capacity;
};

typedef struct int_array *IntArray;
typedef IntArray IA;

// Basic APIs
public_func void delete_IA(IA ia);
public_func void reset_IA(IA ia);
public_func void reverse_IA(const IA ia);
public_func void print_IA(const IA ia);
public_func void shuffle_IA(const IA ia);
public_func void is_ordered_IA(const IA ia);
public_func void is_descend_IA(const IA ia);

public_func void exchange_IA(const IA ia, const ia_index i, const ia_index j);

public_func void left_insert_IA(const IA ia, const int value,
                                const ia_index position);

public_func IA create_IA(const ia_index capacity);
public_func IA slice_IA(const IA ia, const ia_index i, const ia_index j);

#endif
