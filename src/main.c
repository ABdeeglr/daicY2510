#include "fia/fia.h"
#define DEBUG 1
#include "debug.h"

int main(const int argc, const char *argv[]) {

  IA g = int_array_create(14);
  int_array_fill_random(g); 
  int_array_print(g);
  int_array_destroy(g);

  return 0;
}
