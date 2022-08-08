#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NODE
{
  int content;
  struct NODE *nextNode;
} NODE;

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

NODE *createNode(int content)
{
  NODE *node = (NODE *)malloc(sizeof(NODE));
  node->content = content;
  node->nextNode = NULL;
  return node;
}

void insert(NODE **nodes, int content)
{
  NODE *initialNode = *nodes;
  NODE *newNode = createNode(content);

  if (isEmpty(*nodes))
  {
    (*nodes) = newNode;
    return;
  }

  while ((*nodes)->nextNode != NULL)
  {
    (*nodes) = (*nodes)->nextNode;
  }

  (*nodes)->nextNode = newNode;
  *nodes = initialNode;
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

void remove(NODE **nodes, int content)
{
  if (isEmpty(*nodes))
  {
    return;
  }

  if ((*nodes)->content == content)
  {
    NODE *findedNode = (*nodes);
    if (getSize(*nodes) > 1)
    {
      (*nodes) = findedNode->nextNode;
    }
    else
    {
      (*nodes) = NULL;
    }
    free(findedNode);
    return;
  }

  NODE *initialNode = *nodes;

  while (*nodes != NULL && (*nodes)->nextNode != NULL && (*nodes)->nextNode->content != content)
  {
    *nodes = (*nodes)->nextNode;
  }

  if ((*nodes)->nextNode == NULL)
  {
    (*nodes) = initialNode;
    return;
  }
  NODE *findedNode = (*nodes)->nextNode;
  if (findedNode->nextNode == NULL)
  {
    (*nodes)->nextNode = NULL;
  }
  else
  {
    (*nodes)->nextNode = findedNode->nextNode;
  }
  free(findedNode);
  (*nodes) = initialNode;
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

int main()
{
  NODE *nodes = NULL;

  insert(&nodes, 5);
  insert(&nodes, 2);
  insert(&nodes, 4);
  insert(&nodes, 3);

  getAll(nodes);
  remove(&nodes, 3);
  getAll(nodes);

  return 0;
}