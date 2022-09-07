#include <stdio.h>
#define TOTAL_SIZE 200

typedef struct{
  int value;
}NODE;

int length;
NODE nodes[TOTAL_SIZE];

void createList();
int add(int);
int addOn(int, int);
int addFirst(int);
int delete();
int deleteOn(int);
int deleteFirst();
int find(int);
int findLast(int);
void print();
void printReverse();
void printReverseRecursive(NODE[], int);
int isFull();
int isEmpty();
void resetList();

int main(){
  createList();
  add(90);
  add(2);
  add(7);
  add(8);
  add(2);
  add(3);
  addOn(3, 2);
  
  print();
  printf("\n");
  deleteFirst();
  print();
  printf("\n");
  printReverse();
  printf("\n");
  printReverseRecursive(nodes, length - 1);
  
  printf("\nEncontrado 2 em %d \n", find(2));
  printf("(Ultimo) Encontrado 2 em %d \n", findLast(2));
  printf("Encontrado 54 em %d \n", find(54));
  printf("Esta cheio: %d \n", isFull());
  printf("Esta vazio: %d \n", isEmpty());
  resetList();
  return 0;
}

void createList(){
  length = 0;
}

int add(int value){
  if(length < TOTAL_SIZE){
    nodes[length].value = value;
    length++;
    return 1;
  }

  return 0;
}

int addOn(int value, int index){
  int counter;
  if (length < TOTAL_SIZE && index < length){
    for (counter = length;counter > length-index; counter--){
        nodes[counter].value = nodes[counter-1].value;
    }
    nodes[index].value = value;
    length++;
    return 1;
  } else if (index>length){
    return add(value);
  } else {
    return 0;
  }
}

int delete(){
  if (length > 0){
    length--;
    return 1;
  }
  return 0;
}

int deleteOn(int index){
  int counter;
  if (length > 0 && index < length){
    for (counter = index; counter < length-1; counter++){
        nodes[counter].value = nodes[counter+1].value;
    }
    length--;
    return 1;
  } else if (index > length){
    return delete();
  }else{
    return 0;
  }
}

int deleteFirst(){
  return deleteOn(0);
}

int find(int value){
  int index;
  if(length>0){
    for (index = 0; index < length; index++){
      if(nodes[index].value==value) return index;
    }
    return -2;
  } else {
    return -1;
  }
}

int findLast(int value){
  int index;
  int lastIndex = -2;
  if(length>0){
    for (index = 0; index < length; index++){
      if(nodes[index].value==value) lastIndex = index;
    }
    return lastIndex;
  } else {
    return -1;
  }
}

void print(){
  int counter = 0;
  for(counter = 0; counter < length; counter++){
    printf("%d ", nodes[counter].value);
  }
}

void printReverse(){
  int counter = length - 1;
  for(counter = length - 1; counter >= 0; counter--){
    printf("%d ", nodes[counter].value);
  }
}

void printReverseRecursive(NODE list[], int currentIndex){
  printf("%d ", list[currentIndex].value);
  if(currentIndex == 0){
    return;
  }
  return printReverseRecursive(list, currentIndex - 1);
}

int isFull(){
  return length == TOTAL_SIZE;
}

int isEmpty(){
  return length == 0;
}

void resetList(){
  createList();
}