#include <stdio.h>
#define TOTAL_SIZE 10

typedef struct
{
  int value;
} NODE;

int length;
NODE nodes[TOTAL_SIZE];

void createList()
{
  length = 0;
}

int add(int value)
{
  if (length < TOTAL_SIZE)
  {
    nodes[length].value = value;
    length++;
    return 1;
  }

  return 0;
}

int addOn(int value, int index)
{
  if (length < TOTAL_SIZE && index < length)
  {
    int counter;
    for (counter = length; counter > index; counter--)
    {
      nodes[counter].value = nodes[counter - 1].value;
    }
    nodes[index].value = value;
    length++;
    return 1;
  }
  else if (index > length)
  {
    return add(value);
  }
  else
  {
    return 0;
  }
}

int deleteLast()
{
  if (length > 0)
  {
    length--;
    return 1;
  }
  return 0;
}

int deleteOn(int index)
{
  int counter;
  if (length > 0 && index < length)
  {
    for (counter = index; counter < length - 1; counter++)
    {
      nodes[counter].value = nodes[counter + 1].value;
    }
    length--;
    return 1;
  }
  else if (index > length)
  {
    return deleteLast();
  }
  else
  {
    return 0;
  }
}

int deleteFirst()
{
  return deleteOn(0);
}

int find(int value)
{
  int index;
  if (length > 0)
  {
    for (index = 0; index < length; index++)
    {
      if (nodes[index].value == value)
        return index;
    }
    return -2;
  }
  else
  {
    return -1;
  }
}

int findLast(int value)
{
  int index;
  int lastIndex = -2;
  if (length > 0)
  {
    for (index = 0; index < length; index++)
    {
      if (nodes[index].value == value)
        lastIndex = index;
    }
    return lastIndex;
  }
  else
  {
    return -1;
  }
}

void print()
{
  int counter = 0;
  printf("\n==== LISTA COMPLETA ====\n");
  for (counter = 0; counter < length; counter++)
  {
    printf("%d ", nodes[counter].value);
  }
}

void printReverse()
{
  int counter = length - 1;
  for (counter = length - 1; counter >= 0; counter--)
  {
    printf("%d ", nodes[counter].value);
  }
}

void printReverseRecursive(NODE list[], int currentIndex)
{
  printf("%d ", list[currentIndex].value);
  if (currentIndex == 0)
  {
    return;
  }
  return printReverseRecursive(list, currentIndex - 1);
}

int isFull()
{
  return length == TOTAL_SIZE;
}

int isEmpty()
{
  return length == 0;
}

void resetList()
{
  createList();
}

void shiftRight()
{
  if (isEmpty())
  {
    printf("Lista vazia");
    return;
  }
  NODE firstValue = nodes[0];
  add(firstValue.value);
  deleteFirst();
}

void shiftLeft()
{
  if (isEmpty())
  {
    printf("Lista vazia");
    return;
  }
  NODE lastValue = nodes[length - 1];
  addOn(lastValue.value, 0);
  deleteLast();
}

int main()
{
  createList();
  add(1);
  add(2);
  add(3);
  add(4);
  print();

  shiftRight();
  print();

  shiftLeft();
  print();

  return 0;
}
