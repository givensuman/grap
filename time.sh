#!/bin/bash

MY_GREP=./clang/grep
LINUX_GREP=grep

# Test file
TEST_FILE=frankenstein.txt

# Test pattern
PATTERN="monster"

# Number of iterations
ITERATIONS=100

# Function to run grep and calculate average time
run_grep_and_average_time() {
  local grep_command="$1"

  total_time=0
  for ((i = 1; i <= ITERATIONS; i++)); do
    start_time=$(date +%s.%N)
    eval "$grep_command" >/dev/null
    end_time=$(date +%s.%N)
    execution_time=$(echo "$end_time - $start_time" | bc)
    total_time=$(echo "$total_time + $execution_time" | bc)
  done

  average_time=$(echo "scale=4; $total_time / $ITERATIONS" | bc)
  echo "Average execution time: $average_time seconds"
}

echo "Testing sus grep..."
run_grep_and_average_time "$MY_GREP $PATTERN $TEST_FILE"

echo "Testing Linux grep..."
run_grep_and_average_time "$LINUX_GREP $PATTERN $TEST_FILE"
