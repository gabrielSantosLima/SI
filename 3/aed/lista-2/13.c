#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

typedef struct NODE
{
  int age;
  float weight;
  char gender;
  struct NODE *left;
  struct NODE *right;
  char name[MAX];
} NODE;

typedef struct TREE
{
  NODE *root;
} TREE;

int hashOf(char *key)
{
  int size = strlen(key);
  int hashValue = 0;
  int index = 0;
  for (index = 0; index < size; index++)
    hashValue += (int)key[index] * 2;
  return hashValue;
}

TREE *createTree()
{
  TREE *newTree = (TREE *)malloc(sizeof(TREE));
  newTree->root = NULL;
  return newTree;
}

NODE *createNode(char name[], char gender, int age, float weight)
{
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  strcpy(newNode->name, name);
  newNode->gender = gender;
  newNode->age = age;
  newNode->weight = weight;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void insert(TREE *tree, NODE *root, char name[], char gender, int age, float weight)
{
  if (tree->root == NULL)
  {
    NODE *newNode = createNode(name, gender, age, weight);
    tree->root = newNode;
    return;
  }
  if (hashOf(name) < hashOf(root->name))
  {
    if (root->left != NULL)
      return insert(tree, root->left, name, gender, age, weight);
    NODE *newNode = createNode(name, gender, age, weight);
    root->left = newNode;
  }
  else
  {
    if (root->right != NULL)
      return insert(tree, root->right, name, gender, age, weight);
    NODE *newNode = createNode(name, gender, age, weight);
    root->right = newNode;
  }
}

void printAll(NODE *root, int level)
{
  if (root == NULL)
    return;
  int index = 0;
  for (index = 0; index < level; index++)
    printf("  ");
  printf("%s[key=%d, gender=%c, age=%d, weight=%.2f]\n", root->name, hashOf(root->name), root->gender, root->age, root->weight);
  printAll(root->left, level + 1);
  printAll(root->right, level + 1);
}

int getMenLength(NODE *root)
{
  if (root == NULL)
    return 0;
  if (root->gender == 'M')
    return 1 + getMenLength(root->left) + getMenLength(root->right);
  return getMenLength(root->left) + getMenLength(root->right);
}

int getWomenLength(NODE *root)
{
  if (root == NULL)
    return 0;
  if (root->gender == 'F')
    return 1 + getWomenLength(root->left) + getWomenLength(root->right);
  return getWomenLength(root->left) + getWomenLength(root->right);
}

int getWomenAgeSum(NODE *root)
{
  if (root == NULL)
    return 0.0f;
  if (root->gender == 'F')
    return root->age + getWomenAgeSum(root->left) + getWomenAgeSum(root->right);
  return getWomenAgeSum(root->left) + getWomenAgeSum(root->right);
}

float getWomenAgeAverage(NODE *root)
{
  int womenAgeSum = getWomenAgeSum(root);
  return womenAgeSum / getWomenLength(root);
}

NODE *
findByName(NODE *root, char *name)
{
  if (root == NULL)
    return NULL;
  if (hashOf(name) == hashOf(root->name) && strcmp(name, root->name) == 0)
    return root;
  if (hashOf(name) < hashOf(root->name))
    return findByName(root->left, name);
  return findByName(root->right, name);
}

int main()
{
  TREE *tree = createTree();
  insert(tree, tree->root, "Gabriel", 'M', 19, 60.0f);
  insert(tree, tree->root, "Guilherme", 'M', 15, 60.0f);
  insert(tree, tree->root, "Jonas", 'M', 53, 90.0f);
  insert(tree, tree->root, "Nara", 'F', 43, 80.0f);
  insert(tree, tree->root, "Josefina", 'F', 43, 80.0f);
  insert(tree, tree->root, "Padmé", 'F', 43, 80.0f);
  insert(tree, tree->root, "Obi-Wan", 'M', 50, 80.0f);
  printAll(tree->root, 0);
  printf("\n");

  // a-1) Quantidade de homens
  printf("Quantos homens? %d\n", getMenLength(tree->root));
  printf("Quantas mulheres? %d\n", getWomenLength(tree->root));

  // a-2) Média de idade das mulheres
  printf("Média de idade das mulheres: %.2f\n", getWomenAgeAverage(tree->root));

  // b) Pesquisar idade e peso de uma pessoa
  char name[] = "Nara";
  NODE *person = findByName(tree->root, name);
  if (person != NULL)
    printf("%s[age=%d, weight=%.2f]", name, person->age, person->weight);
  else
    printf("%s não existe.", name);
  return 0;
}