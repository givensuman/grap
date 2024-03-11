#include "cycle.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_substring(char *line, char *target, int index_of_target) {
  for (int i = 0; i < index_of_target; i++) {
    printf("%c", line[i]);
  }
  printf("\033[1;31m%s\033[0m", target);
  for (int i = index_of_target + strlen(target); i < strlen(line); i++) {
    printf("%c", line[i]);
  }
}

void cycle_over_line(char *line, char *target) {
  if (line == NULL || line[0] == '\n')
    return;

  size_t line_length = strlen(line);
  size_t target_length = strlen(target);

  Queue *queue = malloc(sizeof(Queue));

  for (int i = 0; i < target_length; i++) {
    enqueue(queue, line[i]);
  }
  for (int i = target_length; i < line_length; i++) {
    cycle(queue, line[i]);
    if (matches_string(queue, target))
      print_substring(line, target, (i - target_length) + 1);
  }

  destroy_queue(queue);
}

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
    cycle_over_line(line, argv[1]);
  }

  fclose(file);
  if (line)
    free(line);

  exit(EXIT_SUCCESS);
}
