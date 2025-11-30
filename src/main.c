#include "./fia/fia.h"

int main(const int argc, const char *argv[]) {

  IA arr = int_array_create(20);
  int_array_destroy(arr);

  printf("%p", arr);

  
  return 0;
}
