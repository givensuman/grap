#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct node {
  char value;
  struct node *next;
} Node;

typedef struct queue {
  Node front;
  Node rear;
} Queue;

/**
 * Add a node to the end of the queue
 */
Queue *enqueue(Queue *queue, Node *node);

/**
 * Remove and return the node at
 * the front of the queue
 */
Node *dequeue(Queue *queue);

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

#endif // QUEUE_H_
