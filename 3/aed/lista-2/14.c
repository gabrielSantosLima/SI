#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
  int value;
  struct NODE *left;
  struct NODE *right;
} NODE;

typedef struct TREE
{
  NODE *root;
} TREE;

TREE *createTree()
{
  TREE *newTree = (TREE *)malloc(sizeof(TREE));
  newTree->root = NULL;
  return newTree;
}

NODE *createNode(int value)
{
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  newNode->value = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void insert(TREE *tree, NODE *root, int value)
{
  if (tree->root == NULL)
  {
    NODE *newNode = createNode(value);
    tree->root = newNode;
    return;
  }
  if (value < root->value)
  {
    if (root->left != NULL)
      return insert(tree, root->left, value);
    NODE *newNode = createNode(value);
    root->left = newNode;
  }
  else
  {
    if (root->right != NULL)
      return insert(tree, root->right, value);
    NODE *newNode = createNode(value);
    root->right = newNode;
  }
}

void printAll(NODE *root, int level)
{
  if (root == NULL)
    return;
  int index;
  for (index = 0; index < level; index++)
    printf("  ");
  printf("%d\n", root->value);
  printAll(root->left, level + 1);
  printAll(root->right, level + 1);
}

int max(NODE *root)
{
  if (root == NULL)
    return -1;
  if (root->right == NULL)
    return root->value;
  return max(root->right);
}

int min(NODE *root)
{
  if (root == NULL)
    return -1;
  if (root->left == NULL)
    return root->value;
  return max(root->left);
}

int main()
{
  TREE *tree = createTree();
  insert(tree, tree->root, 10);
  insert(tree, tree->root, 4);
  insert(tree, tree->root, 15);
  insert(tree, tree->root, 12);
  insert(tree, tree->root, 16);
  insert(tree, tree->root, 13);
  printAll(tree->root, 0);
  printf("\nMenor valor encontrado: %d", min(tree->root));
  printf("\nMaior valor encontrado: %d", max(tree->root));
  return 0;
}