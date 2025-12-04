#include <stdio.h>

int main(const int argc, const char *argv[]) {
  int i = 0;
  
  printf("==[3%d]== \033[30mHello world!\033[0m\n", i++);
  printf("==[3%d]== \033[31mHello world!\033[0m\n", i++);
  printf("==[3%d]== \033[32mHello world!\033[0m\n", i++);
  printf("==[3%d]== \033[33mHello world!\033[0m\n", i++);
  printf("==[3%d]== \033[34mHello world!\033[0m\n", i++);
  printf("==[3%d]== \033[35mHello world!\033[0m\n", i++);
  printf("==[3%d]== \033[36mHello world!\033[0m\n", i++);
  printf("==[3%d]== \033[37mHello world!\033[0m\n", i++);
  printf("==[3%d]== \033[38mHello world!\033[0m\n", i++);
  printf("==[3%d]== \033[39mHello world!\033[0m\n", i++);
  
  return 0;
}
