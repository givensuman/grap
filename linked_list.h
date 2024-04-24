#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct node {
  int data;
  struct node *next;
} Node;

/**
 * Prints the linked list
 *
 * @param Node *head
 */
void print_list(Node *head);

/**
 * Appends data to the end of the linked list
 *
 * @param Node *head
 */
Node *append(Node *head, int data);

/**
 * Prepends data to the beginning of the linked list
 *
 * @param Node *head
 */
Node *prepend(Node *head, int data);

/**
 * Frees the linked list from memory
 *
 * @param Node *head
 */
void free_list(Node *head);

/**
 * Converts the linked list to an array
 *
 * @param Node *head
 */
int *to_array(Node *head);

#endif // LINKED_LIST_H_
