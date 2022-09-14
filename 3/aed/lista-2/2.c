#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
  int value;
  struct NODE *left;
  struct NODE *right;
} NODE;

NODE *createNode(int value)
{
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->value = value;
  return newNode;
}

void insert(NODE **root, NODE *currentRoot, int value)
{
  if (currentRoot == NULL)
  {
    NODE *newNode = createNode(value);
    *root = newNode;
    return;
  }
  if (value < currentRoot->value)
  {
    if (currentRoot->left != NULL)
      return insert(root, currentRoot->left, value);
    NODE *newNode = createNode(value);
    currentRoot->left = newNode;
  }
  else
  {
    if (currentRoot->right != NULL)
      return insert(root, currentRoot->right, value);
    NODE *newNode = createNode(value);
    currentRoot->right = newNode;
  }
}

void printAll(NODE *root)
{
  if (root == NULL)
    return;
  printAll(root->left);
  printAll(root->right);
  printf("%d ", root->value);
}

int main()
{
  NODE *root = NULL;
  insert(&root, root, 10);
  insert(&root, root, 23);
  insert(&root, root, 25);
  insert(&root, root, 20);
  insert(&root, root, 5);
  insert(&root, root, 3);
  printAll(root);
  return 0;
}