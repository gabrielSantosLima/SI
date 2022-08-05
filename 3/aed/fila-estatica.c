#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef int NODE;

typedef struct QUEUE
{
  int length;
  NODE queue[MAX];
}QUEUE;

QUEUE* createQueue(){
  QUEUE* newQueue = (QUEUE*) malloc(sizeof(QUEUE));
  newQueue->length = 0;
  return newQueue;
}

void push(QUEUE* queue, NODE value){
  if(queue->length == 0){
    queue->queue[0] = value;
    queue->length++;
    return;
  }
  if(queue->length == MAX){
    printf("Lista cheia");
    return;
  }
  queue->queue[queue->length] = value;
  queue->length++;
}

void pop(QUEUE* queue){
  if(queue->length == 0){
    printf("Lista vazia");
    return;
  }
  queue->length--;
  int index;
  for(index = 0; index < queue->length; index++){
    queue->queue[index] = queue->queue[index + 1];
  }
}

void printAll(QUEUE* queue){
  if(queue->length == 0){
    printf("Lista vazia");
    return;
  }
  int index;
  for(index = 0; index < queue->length; index++){
    printf("%d ", queue->queue[index]);
  }
}

int main(){
  QUEUE* queue = createQueue();
  push(queue, 2);
  push(queue, 20);
  push(queue, 27);
  push(queue, 22);
  push(queue, 34);

  printf("===== LISTA COMPLETA =====\n");
  printAll(queue);
  printf("\n===== LISTA COMPLETA (Após remoção)=====\n");
  pop(queue);
  printAll(queue);
  return 0;
}