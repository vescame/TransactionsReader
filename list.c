#include <stdlib.h>
#include <stdio.h>
#include "./list.h"

struct transaction
{
  float value;
};

struct transaction_node
{
  transaction_t *element;
  node_t *next;
};

struct transactions
{
  node_t *head;
};

transaction_list_t *new_transaction_list()
{
  transaction_list_t *tl = (transaction_list_t *) malloc(sizeof(transaction_list_t));
  tl->head = NULL;
  return tl;
}

node_t *new_node(transaction_t *t, node_t *next)
{
  node_t *n = (node_t *) malloc(sizeof(node_t));
  n->element = t;
  n->next = NULL;
  return n;
}

void add_transaction(transaction_list_t *list, transaction_t *t)
{
  node_t *n = new_node(t, NULL);

  if (list->head == NULL) {
    list->head = n;
    return;
  }

  node_t *actual = list->head;

  while (actual->next != NULL) {
    actual = actual->next;
  }

  actual->next = n;
}

void free_list(transaction_list_t *list)
{
  free(list);
}

void print_transactions(transaction_list_t *list) {
  if (list == NULL) return;
  node_t *actual = list->head;
  while (actual != NULL) {
    actual = actual->next;
  }
}

void sumarize_transactions(transaction_list_t *list) {
  float sum = 0.0;
  node_t *actual = list->head;
  while (actual != NULL) {
    sum += actual->element->value;
    actual = actual->next;
  }
    printf("Sum of: %.2f\n", sum);
}


