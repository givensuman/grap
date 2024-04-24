#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void print_list(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    printf("%d%s", temp->data, temp->next == NULL ? "" : " -> ");
    temp = temp->next;
  }
  printf("\n");
}

Node *append(Node *head, int data) {
  Node *new_node = malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;

  if (head == NULL) {
    return new_node;
  }

  Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_node;

  return head;
}

Node *prepend(Node *head, int data) {
  Node *new_node = malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = head;
  head = new_node;

  return head;
}

void free_list(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    Node *next = temp->next;
    free(temp);
    temp = next;
  }
}

int *to_array(Node *head) {
  printf("Converting this list to array: ");
  print_list(head);

  int size = 0;
  Node *temp = head;
  while (temp != NULL) {
    size++;
    temp = temp->next;
  }

  int *arr = malloc(sizeof(int) * size);
  if (arr == NULL) {
    printf("Memory allocation failed in to_array call.\n");
    return NULL;
  }

  int i = 0;
  temp = head;
  while (i < size && temp != NULL) {
    arr[i++] = temp->data;
    temp = temp->next;
  }

  return arr;
}
