#include "search.h"
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// See psuedocode in search.h for
// implementation details

/**
 * Implementation of Knuth-Morris-Pratt search
 * algorithm. Returns a linked list of all
 * indices where the pattern is found
 *
 * @param char *target
 * @param char *space
 *
 * @returns Node *success
 */
Node *kmp_search(char *target, char *space) {
  unsigned target_length = strlen(target);
  unsigned space_length = strlen(space);
  int i = 0;
  int j = 0;

  int *lps = calculate_lps(target);
  Node *matches = NULL;

  while (i < space_length) {
    // The characters are a match
    if (target[j] == space[i]) {
      i++;
      j++;

      // j pointer has reached the end of
      // the target string
      if (j == target_length) {
        // i - j is the index of the match
        matches = append(matches, (i - j));
        j = lps[j - 1];
      }
    } else if (i < space_length && target[j] != space[i]) {
      if (j > 0) { // keep on truckin'
        j = lps[j - 1];
      } else { // sadge
        i++;
      }
    }
  }

  free(lps);
  return matches;
}

/**
 * Helper function to calculate the
 * "longest prefix-suffix" of each character
 * in our search pattern
 *
 * @param char *pattern
 *
 * @returns int *lps
 */
int *calculate_lps(char *pattern) {
  unsigned pattern_length = strlen(pattern);

  // Allocate memory for the failure function array
  int *lps = malloc(sizeof(int) * (pattern_length));

  // Initialize variables
  int position = 0; // Position in the pattern
  lps[0] = 0;       // Failure function value for the first character

  // Iterate over the characters of the pattern to calculate failure function
  // values
  for (int current_char = 1; current_char < pattern_length; current_char++) {
    position = lps[current_char - 1]; // Get the previous position

    // Update position until we find a match or reach the start of the pattern
    while (pattern[current_char] != pattern[position] && position > 0) {
      position = lps[position - 1];
    }

    // Calculate failure function value for the current character
    if (pattern[current_char] == pattern[position]) {
      lps[current_char] = position + 1;
    } else {
      lps[current_char] = 0;
    }
  }

  return lps;
}
