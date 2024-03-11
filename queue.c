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
    queue->size++;

    return queue;
  }

  queue->rear->next = node;
  queue->rear = node;

  queue->size++;
  return queue;
}

Node *dequeue(Queue *queue) {
  if (is_empty(queue)) {
    fprintf(stderr, "Cannot dequeue from an empty queue!\n");
    exit(EXIT_FAILURE);
  }

  Node *front = queue->front;
  queue->front = front->next;

  queue->size--;
  return front;
}

void dequeue_and_free(Queue *queue) {
  Node *node = dequeue(queue);
  free(node);
}

bool is_empty(Queue *queue) { return queue->size == 0; }

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
  queue->size = 0;
}

void destroy_queue(Queue *queue) {
  free_queue(queue);
  free(queue);
}
