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

void insertNode(TREE *tree, NODE *root, int value)
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
      return insertNode(tree, root->left, value);
    NODE *newNode = createNode(value);
    root->left = newNode;
  }
  else
  {
    if (root->right != NULL)
      return insertNode(tree, root->right, value);
    NODE *newNode = createNode(value);
    root->right = newNode;
  }
}

void printAll(NODE *root)
{
  if (root == NULL)
    return;
  printf("%d (", root->value);
  printAll(root->left);
  printAll(root->right);
  printf(")");
}

int heightOf(NODE *root, int level)
{
  if (root == NULL)
    return level - 1;
  int leftHeight = heightOf(root->left, level + 1);
  int rightHeight = heightOf(root->right, level + 1);
  int maxHeight = leftHeight;
  if (rightHeight > maxHeight)
    maxHeight = rightHeight;
  return maxHeight;
}

int main()
{
  TREE *tree = createTree();
  insertNode(tree, tree->root, 10);
  insertNode(tree, tree->root, 4);
  insertNode(tree, tree->root, 15);
  insertNode(tree, tree->root, 12);
  insertNode(tree, tree->root, 16);
  insertNode(tree, tree->root, 13);
  printAll(tree->root);
  printf("\nTamanho da Árvore: %d", heightOf(tree->root, 0));
  return 0;
}