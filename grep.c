#include "search.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  char *line = NULL;
  size_t line_length = 0;
  ssize_t read;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <target> <file/stream>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *target = argv[1];

  FILE *file = fopen(argv[2], "r");
  if (file == NULL) {
    fprintf(stderr, "Could not read file %s.\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  while ((read = getline(&line, &line_length, file)) != -1) {
    Node *match = kmp_search(target, line);
    while (match != NULL) {
      printf("%s\n", line);
      match = match->next;
    }
  }

  fclose(file);
  if (line)
    free(line);

  exit(EXIT_SUCCESS);
}
