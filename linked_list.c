#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void print(Node *head) {
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
  Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_node;

  return new_node;
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
  int size = 0;
  Node *temp = head;
  while (temp != NULL) {
    size++;
    temp = temp->next;
  }

  int *arr = malloc(sizeof(int) * size);
  int i = 0;
  while (temp != NULL) {
    arr[i] = temp->data;
    temp = temp->next;
    i++;
  }

  return arr;
}
