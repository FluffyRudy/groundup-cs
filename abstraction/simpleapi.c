#include <stdio.h>

struct greet_api {
  int (*say_hello)(char *name);
  int (*say_goodbye)(void);
};

int say_hello_fn(char *name);
int say_goodbye_fn(void);

struct greet_api greet_api = {.say_hello = say_hello_fn,
                              .say_goodbye = say_goodbye_fn};

int main(int argc, char *argv[]) {
  greet_api.say_hello(argv[1]);
  greet_api.say_goodbye();
}

int say_hello_fn(char *name) {
  fputs(name, stdout);
  putchar('\n');
  return 0;
}

int say_goodbye_fn(void) {
  fputs("Goodbye\n", stdout);
  return 0;
}