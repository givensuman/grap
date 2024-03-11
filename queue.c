#include "queue.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

Queue *enqueue(Queue *queue, char value) {
  Node *node = malloc(sizeof(Node));
  node->value = value;

  if (is_empty(queue)) {
    queue->front = node;
    queue->rear = node;

    return queue;
  }

  Node *front = queue->front;
  node->next = front;
  queue->front = node;

  return queue;
}

Node *dequeue(Queue *queue) {
  if (is_empty(queue)) {
    fprintf(stderr, "Cannot dequeue from an empty queue!\n");
    exit(EXIT_FAILURE);
  }

  Node *front = queue->front;
  queue->front = front->next;

  return front;
}

bool is_empty(Queue *queue) { return queue->front == NULL; }

void print_queue(Queue *queue) {
  printf("[");
  Node *node = queue->front;
  while (node != NULL) {
    printf("%c%s", node->value, node->next == NULL ? "" : ", ");
    node = node->next;
  }
  printf("]\n");
}

void free_queue(Queue *queue) {
  Node *node;
  while (!is_empty(queue)) {
    node = dequeue(queue);
    free(node);
  }

  queue->front = NULL;
  queue->rear = NULL;
}

void destroy_queue(Queue *queue) {
  free_queue(queue);
  free(queue);
}
