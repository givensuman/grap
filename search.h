#ifndef SEARCH_H_
#define SEARCH_H_

#include "linked_list.h"

/**
 * Pseudocode for Knuth-Morris-Pratt
 * pattern-search algorithm
 *
 * https://brown-cs181-fall22.github.io/lectures/KMPAlgorithm.pdf
 *
 * calculate f(i) for 1 <= i <= p
 * construct a skeleton DFA M for P using f
 * M starts in state M[0]
 * i := current state in M (updated with transitions)
 * j <- 1
 *
 * while j <= t do
 *   if T[j] = P[i + 1] then
 *     j <- j + 1
 *     M enters state M[i + 1]
 *     if M is in state M[p] then
 *       record (j - p)
 *       M enters state M[f(p)]
 *     end
 *   else
 *    M enters state M[f(i)]
 *    if M is in state M[0] and T[j] != P[i + 1] then
 *      j <- j + 1
 *    end
 *   end
 *  end
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
Node *kmp_search(char *target, char *space);

/**
 * Pseudocode for failure function
 * used for input preprocess for KMP search
 *
 * https://brown-cs181-fall22.github.io/lectures/FailureFunctionAlgorithm.pdf
 *
 * i <- 0
 * f(1) <- 0
 *
 * for every j from 2 to m do
 *  i = f(j - 1)
 *  while p(j) != p(i + 1) and i > 0 do
 *    i = f(i)
 *  if p(j) != p(i + 1) and i = 0 then
 *    f(j) = 0
 *  else
 *    f(j) = i + 1
 *
 *  return f
 */

/**
 * Helper method for finding an optimized position
 * to fall back to in the event of a mismatch.
 *
 * @param char *pattern
 *
 * @return int *failure
 */
int *calculate_lps(char *target);

#endif // SEARCH_H_
