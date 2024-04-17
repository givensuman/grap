/**
 * Pseudocode for failure function
 *
 * https://brown-cs181-fall22.github.io/lectures/FailureFunctionAlgorithm.pdf
 *
 * i <- 0
 * f(1) <- 0
 *
 * for every j from 2 to m do
 *   i = f(j - 1)
 *   while p(j) != p(i + 1) and i > 0 do
 *     i = f(i)
 *   if p(j) != p(i + 1) and i = 0 then
 *     f(j) = 0
 *   else
 *     f(j) = i + 1
 *  end
 *  return f
 *
 *  Helper function to determine the length of the
 *  longest string in our target that is also a
 *  prefix of the search string.
 *  Also sometimes referred to as the LSP function,
 *  or longest suffix/prefix.
 */
int *failure_function(char *search_term) {
  int length = strlen(search_term);
  if (length == 0 || length == 1)
    return 0;

  for (int j = 2; j <=)
}
