#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  char *line = NULL;
  size_t line_length = 0;
  ssize_t read;

  FILE *file = fopen(argv[2], "r");
  if (file == NULL) {
    fprintf(stderr, "Could not read file %s.\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  while ((read = getline(&line, &line_length, file)) != -1) {
    printf("%s\n", line);
    for (int i = 0; i < line_length; i++) {
      //
    }
  }

  fclose(file);
  if (line)
    free(line);

  exit(EXIT_SUCCESS);
}
