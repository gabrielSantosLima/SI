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

void printAll(NODE *root)
{
  if (root == NULL)
    return;
  printf("%d (", root->value);
  printAll(root->left);
  printAll(root->right);
  printf(")");
}

int findParentNode(NODE *root, int value)
{
  if (root == NULL || root->value == value) // Verifica se nó é nulo (árvore vazia, nó inexistente) ou se a raiz é o nó que estou buscando. Raiz não possui pai.
    return -1;
  if ((root->left != NULL && root->left->value == value) ||
      (root->right != NULL && root->right->value == value)) // Verifica se algum dos filhos é o elemento que quero buscar. Caso verdadeiro, retorna o valor do pai (nó atual)
    return root->value;
  if (value < root->value) // Continua buscando pelo pai (do nó com este valor) pela esquerda (valor < raiz) ou pela direita (valor >= raiz)
    return findParentNode(root->left, value);
  return findParentNode(root->right, value);
}

// int findParentNode(NODE *root, int value)
// {
//   NODE *parent = NULL;
//   while (root != NULL && root->value != value)
//   {
//     parent = root;
//     if (value < root->value)
//       root = root->left;
//     else
//       root = root->right;
//   }
//   if (root == NULL || parent == NULL)
//     return -1;
//   return parent->value;
// }

int main()
{
  TREE *tree = createTree();
  insert(tree, tree->root, 10);
  insert(tree, tree->root, 4);
  insert(tree, tree->root, 15);
  insert(tree, tree->root, 12);
  insert(tree, tree->root, 16);
  insert(tree, tree->root, 13);
  printAll(tree->root);
  printf("\nPai encontrado: %d", findParentNode(tree->root, 10));
  return 0;
}