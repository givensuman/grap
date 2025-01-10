#!/bin/bash

LINUX_GREP="grep"

# Test file
TEST_FILE="./frankenstein.txt"

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
  printf "\tAverage execution time: %.4f seconds\n" "$average_time"
}

# Compilation
printf "Compiling... "
echo "Done."

(
  cd clang || (
    echo "Couldn't cd into clang directory"
    exit 1
  )
  make >/dev/null
)
CLANG_GREP=./clang/grep

(
  cd rust || (
    echo "Couldn't cd into rust directory"
    exit 1
  )
  cargo build --quiet >/dev/null
)
RUST_GREP="./rust/target/debug/grep"

# Testing
echo "Testing Linux grep..."
run_grep_and_average_time "$LINUX_GREP $PATTERN $TEST_FILE"

echo "Testing C implementation..."
run_grep_and_average_time "$CLANG_GREP $PATTERN $TEST_FILE"

echo "Testing Rust implementation..."
run_grep_and_average_time "$RUST_GREP $PATTERN $TEST_FILE"
