#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/random.h>

#define PWLEN 20

static const char validchars[] =
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789._~+-,=";
#define nchars sizeof(validchars) - 1

int main() {
  size_t i;
  unsigned char c;
  char password[PWLEN + 1];

  for (i = 0; i < PWLEN; i++) {
    do {
      if (getrandom(&c, 1, 0) != 1) {
        fprintf(stderr, "ERROR calling getrandom()\n");
        return 1;
      }
    } while (c >= nchars);
    password[i] = validchars[c];
  }
  password[PWLEN] = 0;
  printf("%s\n", password);

  return 0;
}
