#ifndef SEARCH_H_
#define SEARCH_H_

#include "linked_list.h"

// Reference:
// Introduction To Algorithms By Thomas H. Cormen, Charles E. Leiserson, Ronald
// L. Rivest, Clifford Stein
// Chapter 32: String Matching

/**
 * Pseudocode for Knuth-Morris-Pratt
 * pattern-search algorithm
 *
 * KMP(T, P)
 * n <- T.length
 * m <- P.length
 * k <- calculate_lps(P)
 * q <- 0
 * for i = 1 to n do
 *  while q > 0 and P[q + 1] != T[i] do
 *    q = k[q]
 *  end
 *  if P[q + 1] == T[i] then
 *    q = q + 1
 *  if q == m then
 *    print i - m
 *    q = k[q]
 * end
 */

/**
 * Algorithm for searching for a
 * pattern substring in a longer string
 *
 * @param char *target
 * @param char *space
 *
 * @return int *positions
 */
List *kmp_search(char *target, char *space);

/**
 * Pseudocode for prefix compute
 * used for input preprocess for KMP search
 *
 * calculate_lps(P)
 * m <- P.length
 * let k[1..m] be a new array
 * k[1] <- 0
 * j <- 0
 * for q = 2 to m do
 *   while j > 0 and P[j + 1] != P[q] do
 *     j <- k[j]
 *   end
 *   if P[j + 1] == P[q] then
 *     j <- j + 1
 *   k[q] = j
 * end
 * return k
 */

/**
 * Helper method for finding an optimized position
 * to fall back to in the event of a mismatch
 *
 * @param char *pattern
 *
 * @return int *failure
 */
int *calculate_lps(char *target);

#endif // SEARCH_H_
