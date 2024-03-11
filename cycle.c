#include "cycle.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cycle(Queue *queue, char value) {
  dequeue_and_free(queue);
  enqueue(queue, value);
}

bool matches_string(Queue *queue, char *string) {
  size_t length = strlen(string);

  Node *node = queue->front;
  int index = 0;
  while (node != NULL) {
    if (node->value != string[index])
      return false;
    node = node->next;
    index++;
  }

  return true;
}
