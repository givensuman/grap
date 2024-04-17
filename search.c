#include "search.h"
#include <stdlib.h>
#include <string.h>

int *kmp_search(char *target, char *space) {}

// See pseudocode in search.h
int *failure_function(char *p) {
  unsigned target_length = strlen(p);

  int *f = malloc(sizeof(int) * (target_length));

  int i = 0;
  f[0] = 0;

  for (int j = 1; j < target_length; j++) {
    i = f[j - 1];
    while (p[j] != p[i + 1] && i > 0) {
      i = f[i];
    }

    if (f[j] == f[i + 1] && i == 0) {
      f[j] = 0;
    } else {
      f[j] = i + 1;
    }
  }

  return f;
}
