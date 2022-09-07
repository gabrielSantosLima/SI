#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int NODE;

typedef struct QUEUE
{
  int length;
  int startNode;
  int endNode;
  NODE queue[MAX];
}QUEUE;

QUEUE* createQueue(){
  QUEUE* newQueue = (QUEUE*) malloc(sizeof(QUEUE));
  newQueue->startNode = 0;
  newQueue->endNode = -1;
  newQueue->length = 0;
  return newQueue;
}

void push(QUEUE* queue, NODE value){
  if(queue->length == MAX){
    printf("Lista cheia");
    return;
  }
  if(queue->endNode == MAX - 1){
    queue->endNode = 0;
  }else{
    queue->endNode++;
  }
  queue->queue[queue->endNode] = value;
  queue->length++;
}

void pop(QUEUE* queue){
  if(queue->length == 0){
    printf("Lista vazia");
    return;
  }
  if(queue->startNode == MAX - 1){
    queue->startNode = 0;
  }else{
    queue->startNode++;
  }
  queue->length--;
}

void printAll(QUEUE* queue){
  int index;
  printf("Inicio: %d\nFim: %d\n", queue->startNode, queue->endNode);
  for(index = 0; index < MAX; index++){
    printf("%d ", queue->queue[index]);
  }
}

int main(){
  QUEUE* queue = createQueue();
  push(queue, 11);
  push(queue, 22);
  push(queue, 33);
  push(queue, 44);
  push(queue, 55);

  printf("===== LISTA COMPLETA =====\n");
  printAll(queue);
  printf("\n===== LISTA COMPLETA (Após remoção)=====\n");
  pop(queue);
  push(queue, 66);
  printAll(queue);
  return 0;
}