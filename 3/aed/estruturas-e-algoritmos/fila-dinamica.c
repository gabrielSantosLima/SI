#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int value;
    struct NODE *nextNode;
} NODE;

typedef struct QUEUE
{
    NODE *startNode;
    NODE *endNode;
} QUEUE;

NODE *createNode(int value)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->value = value;
    newNode->nextNode = NULL;
    return newNode;
}

QUEUE *createQueue()
{
    QUEUE *newQueue = (QUEUE *)malloc(sizeof(QUEUE));
    newQueue->startNode = NULL;
    newQueue->endNode = NULL;
    return newQueue;
}

void push(QUEUE *queue, int value)
{
    NODE *newNode = createNode(value);
    if (queue->startNode == NULL)
    {

        queue->startNode = newNode;
        queue->endNode = newNode;
        return;
    }
    queue->endNode->nextNode = newNode;
    queue->endNode = newNode;
}

void pop(QUEUE *queue)
{
    if (queue->startNode == NULL)
    {
        return;
    }

    if (queue->startNode == queue->endNode)
    {
        free(queue->startNode);
        queue->startNode = NULL;
        queue->endNode = NULL;
        return;
    }

    NODE *lastStartNode = queue->startNode;
    queue->startNode = lastStartNode->nextNode;
    free(lastStartNode);
}

void printAll(QUEUE *queue)
{
    if (queue->startNode == NULL)
    {
        printf("Lista vazia");
        return;
    }
    NODE *currentNode = queue->startNode;
    while (currentNode != NULL)
    {
        printf("%d ", currentNode->value);
        currentNode = currentNode->nextNode;
    }
}

int main()
{
    QUEUE *queue = createQueue();
    push(queue, 12);
    push(queue, 22);
    push(queue, 3);
    push(queue, 35);
    push(queue, 89);

    printf("====== LISTA COMPLETA ======\n");
    printAll(queue);
    printf("\n====== LISTA COMPLETA (Após remoção) ======\n");
    pop(queue);
    printAll(queue);
    return 0;
}