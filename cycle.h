// Helper methods around `queue.h` that
// facilitate grep substring search
// implementation

#ifndef CYCLE_H_
#define CYCLE_H_

#include "queue.h"

/**
 * Cycle the queue, adding a new char
 * and pushing out the oldest
 */
void cycle(Queue *queue, char value);

/**
 * Determine if the provided queue of
 * chars matches the provided string
 */
bool matches_string(Queue *queue, char *string);

/**
 * Dequeues from the queue and returns
 * the char value of the node
 */
char dequeue_and_get(Queue *queue);

#endif // CYCLE_H_
