#include "search.h"
#include <stdio.h>
#include <string.h>

int main() {
  char *target = "abc";
  // int *f = failure_function(target);
  // for (int i = 0; i < strlen(target); i++) {
  //   printf("%d ", f[i]);
  // }

  char *space = "0000abcaabc000000";
  int *k = kmp_search(target, space);
  for (int i = 0; i < strlen(target); i++) {
    printf("%d ", k[i]);
  }
}
