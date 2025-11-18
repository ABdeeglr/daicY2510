#include "fia/fia.h"
#define DEBUG 1
#include "debug.h"

int main(const int argc, const char *argv[]) {

  __DEBUG("Hello world!");
  __WARNING("Here is %d warning.", 13);
  __ERROR("And only %d Errors!", 0);

  IA ia = create_IA(30);
  print_IA(ia);
  free(ia);

  return 0;
}
