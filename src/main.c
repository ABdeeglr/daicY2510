#include "fia/fia.h"
#define DEBUG 1
#include "leetcode/q42.h"

int main(const int argc, const char *argv[]) {
  IA arr = int_array_create(50);

  int_array_fill_random(arr);

  example_test_1(arr);
}
