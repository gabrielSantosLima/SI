#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NO
{
  int content;
  struct NO *nextNode;
} NODE;

NODE *createNode(int content)
{
  NODE *node = (NODE *)malloc(sizeof(NODE));
  node->content = content;
  node->nextNode = NULL;
  return node;
}

NODE *insert(NODE *nodes, int content)
{
  NODE *initialNode = nodes;

  if (nodes == NULL)
  {
    NODE *newNode = createNode(content);
    return newNode;
  }

  while (nodes->nextNode != NULL)
  {
    nodes = nodes->nextNode;
  }

  NODE *newNode = createNode(content);
  nodes->nextNode = newNode;
  return initialNode;
}

int getSize(NODE *nodes)
{
  int size = 0;

  while (nodes != NULL)
  {
    size++;
    nodes = nodes->nextNode;
  }
  return size;
}

bool isEmpty(NODE *nodes)
{
  return getSize(nodes) == 0;
}

NODE *removeLast(NODE *nodes)
{
  if (nodes == NULL)
  {
    return NULL;
  }

  if (getSize(nodes) == 1)
  {
    free(nodes);
    return NULL;
  }

  NODE *initialNode = nodes;

  while (nodes->nextNode->nextNode != NULL)
  {
    nodes = nodes->nextNode;
  }

  free(nodes->nextNode);
  nodes->nextNode = NULL;
  return initialNode;
}

void getAll(NODE *nodes)
{
  printf("======== LISTA COMPLETA ========\n");
  if (isEmpty(nodes))
  {
    printf("Lista Vazia");
  }
  while (nodes != NULL && !isEmpty(nodes))
  {
    printf("%d ", nodes->content);
    nodes = nodes->nextNode;
  }
  printf("\n================================\n");
}

void shiftRight(NODE **nodes)
{
  if (isEmpty(*nodes))
  {
    printf("Lista vazia");
    return;
  }
  NODE *startNode = *nodes;
  while ((*nodes)->nextNode != NULL)
  {
    *nodes = (*nodes)->nextNode;
  }
  (*nodes)->nextNode = startNode;
  (*nodes) = startNode->nextNode;
  startNode->nextNode = NULL;
}

void shiftLeft(NODE **nodes)
{
  if (isEmpty(*nodes))
  {
    printf("Lista vazia");
    return;
  }
  NODE *startNode = *nodes;
  while ((*nodes)->nextNode->nextNode != NULL)
  {
    *nodes = (*nodes)->nextNode;
  }
  NODE *lastNode = (*nodes)->nextNode;
  lastNode->nextNode = startNode;
  (*nodes)->nextNode = NULL;
  (*nodes) = lastNode;
}

int main()
{
  NODE *nodes = NULL;

  nodes = insert(nodes, 2);
  nodes = insert(nodes, 3);
  nodes = insert(nodes, 4);
  nodes = insert(nodes, 5);

  getAll(nodes);
  shiftRight(&nodes);
  getAll(nodes);
  shiftLeft(&nodes);
  getAll(nodes);

  return 0;
}