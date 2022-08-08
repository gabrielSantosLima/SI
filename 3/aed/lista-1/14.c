#include <stdio.h>
#include <stdlib.h>

typedef struct NO
{
  int value;
  struct NO *next;
} NODE;

NODE *createNode(int value)
{
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

void push(NODE **nodes, NODE *newNode)
{
  if ((*nodes) == NULL)
  {
    newNode->next = NULL;
    (*nodes) = newNode;
  }
  else
  {
    newNode->next = *nodes;
    (*nodes) = newNode;
  }
}

NODE *pop(NODE **nodes)
{
  if ((*nodes) == NULL)
  {
    return NULL;
  }
  if ((*nodes)->next == NULL)
  {
    NODE *pastNode = (*nodes);
    *nodes = NULL;
    return pastNode;
  }
  else
  {
    NODE *pastNode = (*nodes);
    *nodes = pastNode->next;
    return pastNode;
  }
}

void printAll(NODE *nodes)
{
  while (nodes != NULL)
  {
    printf("%d ", nodes->value);
    nodes = nodes->next;
  }
}

int main()
{
  NODE *A = NULL;
  NODE *B = NULL;
  NODE *C = NULL;

  push(&A, createNode(1));
  push(&A, createNode(2));
  push(&A, createNode(3));

  printf("=== LISTA COMPLETA ===\n(A) ");
  printAll(A);

  while (A != NULL)
  {
    NODE *node = pop(&A);
    push(&B, node);
  }
  printf("\n(B) ");
  printAll(B);

  while (B != NULL)
  {
    NODE *node = pop(&B);
    push(&C, node);
  }
  printf("\n(C) ");
  printAll(C);

  printf("\n=== LISTA COMPLETA INVERSA ===\n");
  while (C != NULL)
  {
    NODE *node = pop(&C);
    push(&A, node);
  }
  printf("(A inverso) ");
  printAll(A);

  return 0;
}