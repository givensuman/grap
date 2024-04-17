#include "search.h"
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// See psuedocode in search.h for
// implementation details
int *kmp_search(char *target, char *space) {
  unsigned target_length = strlen(target);
  unsigned space_length = strlen(space);
  int i = 0;
  int j = 0;

  int *failure = failure_function(target);
  Node *success = malloc(sizeof(Node));

  while (i < space_length) {
    // The characters are a match
    if (target[j] == space[i]) {
      i++;
      j++;

      // j pointer has reached the end of
      // the target string
      if (j == target_length) {
        // i - j is the index of the match
        success = append(success, (i - j));
        printf("Found a match at index %d\n", i - j);
        j = failure[j - 1];
      }
    } else if (i < space_length && target[j] != space[i]) {
      if (j > 0) { // keep on truckin'
        j = failure[j - 1];
      } else { // sadge
        i++;
      }
    }
  }

  free(failure);

  return to_array(success);
}

int *failure_function(char *pattern) {
  unsigned pattern_length = strlen(pattern);

  // Allocate memory for the failure function array
  int *failure = malloc(sizeof(int) * (pattern_length));

  // Initialize variables
  int position = 0; // Position in the pattern
  failure[0] = 0;   // Failure function value for the first character

  // Iterate over the characters of the pattern to calculate failure function
  // values
  for (int current_char = 1; current_char < pattern_length; current_char++) {
    position = failure[current_char - 1]; // Get the previous position

    // Update position until we find a match or reach the start of the pattern
    while (pattern[current_char] != pattern[position] && position > 0) {
      position = failure[position - 1];
    }

    // Calculate failure function value for the current character
    if (pattern[current_char] == pattern[position]) {
      failure[current_char] = position + 1;
    } else {
      failure[current_char] = 0;
    }
  }

  return failure;
}
