#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Returns the length of a null-terminated string
 */
int length_of(char *string) {
  int length = 0;
  while (string[length] != '\0') {
    length++;
  }

  return length;
}

/*
 * Returns the substring of a string from
 * a starting index (inclusive) to an ending index (exclusive)
 */
char *substring(char *string, int start, int end) {
  int string_length = length_of(string);
  if (start > string_length || start < 0 || end < 0) {
    printf("[ERROR] Index out of bounds.\n");
    printf("Attempted to call substring on string of length %d with index "
           "range [%d, %d).\n",
           string_length, start, end);
    exit(1);
  }
  if (end > string_length)
    end = string_length;

  int isNullTerminated = string[end] == '\0' ? 1 : 0;
  char *substring_ =
      (char *)malloc((end - start + isNullTerminated) * sizeof(char));

  for (int i = start, j = 0; i < end; i++, j++) {
    substring_[j] = string[i];
  }
  if (isNullTerminated == 0)
    substring_[end - start] = '\0';

  return substring_;
}

/*
 * Prints a prettified version of the line
 * to stdout with provided line number
 */
#define FORMAT "\033[1;31m"
#define UNFORMAT "\033[0m"

void print_result(char *string, int start, int end) {
  char *head = substring(string, 0, start);
  char *result = substring(string, start, end);
  char *tail = substring(string, end, length_of(string));

  printf("%s", head);
  printf("%s%s%s", FORMAT, result, UNFORMAT);
  printf("%s", tail);

  free(head);
  free(result);
  free(tail);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("No arguments passed...\n");
    exit(1);
  }
  if (argc < 3) {
    printf("No filename passed...\n");
    exit(1);
  }
  if (argc > 3) {
    printf("Too many arguments passed...\n");
    exit(1);
  }

  char *needle = argv[1];
  char *haystack = argv[2];
  FILE *file = fopen(haystack, "r");

  char *buf = malloc(255 * sizeof(char));
  char *line = fgets(buf, 255, file);
  int length_of_needle = length_of(needle);

  while (line != NULL) {
    int length_of_line = length_of(line);

    for (int i = 0; i < length_of_line - length_of_needle; i++) {
      char *substr = substring(line, i, i + length_of_needle);

      if (strcmp(substr, needle) == 0) {
        print_result(line, i, i + length_of_needle);
      }

      free(substr);
    }

    line = fgets(buf, 255, file);
  }

  printf("\n");

  free(buf);
  fclose(file);
}
