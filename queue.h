// Standard queue data structure
// for storing chars

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdbool.h>

typedef struct node {
  char value;
  struct node *next;
} Node;

typedef struct queue {
  Node *front;
  Node *rear;
  int size;
} Queue;

/**
 * Add a node to the end of the queue
 */
Queue *enqueue(Queue *queue, char value);

/**
 * Remove and return the node at the
 * front of the queue
 */
Node *dequeue(Queue *queue);

/**
 * Remove and free the node at the
 * front of the queue
 */
void dequeue_and_free(Queue *queue);

/**
 * Return if the queue is empty
 */
bool is_empty(Queue *queue);

/**
 * Print the contents of the queue
 * to stdout
 */
void print_queue(Queue *queue);

/**
 * Free the memory associated with
 * the queue and resets its front and rear
 */
void free_queue(Queue *queue);

/**
 * Free the memory associated with
 * the queue, and the queue itself
 */
void destroy_queue(Queue *queue);

#endif // QUEUE_H_
