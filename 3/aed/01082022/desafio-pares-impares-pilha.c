#include <stdio.h>
#include <stdlib.h>

typedef struct NO
{
    int value;
    struct NO *next;
} NODE;

NODE *createNode(int value)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void push(NODE **nodes, NODE *newNode)
{
    if ((*nodes) == NULL)
    {
        newNode->next = NULL;
        (*nodes) = newNode;
    }
    else
    {
        newNode->next = *nodes;
        (*nodes) = newNode;
    }
}

NODE *pop(NODE **nodes)
{
    if ((*nodes) == NULL)
    {
        return NULL;
    }
    if ((*nodes)->next == NULL)
    {
        NODE *pastNode = (*nodes);
        *nodes = NULL;
        return pastNode;
    }
    else
    {
        NODE *pastNode = (*nodes);
        *nodes = pastNode->next;
        return pastNode;
    }
}

void printAll(NODE *nodes)
{
    if (nodes == NULL)
    {
        printf("Lista vazia!");
        return;
    }
    while (nodes != NULL)
    {
        printf("%d ", nodes->value);
        nodes = nodes->next;
    }
}

int main()
{
    NODE *numbers = NULL;
    push(&numbers, createNode(1));
    push(&numbers, createNode(2));
    push(&numbers, createNode(3));
    push(&numbers, createNode(4));
    push(&numbers, createNode(5));
    push(&numbers, createNode(6));
    push(&numbers, createNode(7));
    push(&numbers, createNode(8));
    push(&numbers, createNode(9));

    printf("> LISTA COMPLETA\n");
    printAll(numbers);

    NODE *odd = NULL;
    NODE *even = NULL;

    while (numbers != NULL)
    {
        NODE *number = pop(&numbers);
        if (number->value % 2 == 0)
        {
            push(&even, number);
        }
        else
        {
            push(&odd, number);
        }
    }

    printf("\n> PARES\n");
    printAll(even);
    printf("\n> ÍMPARES\n");
    printAll(odd);
    printf("\n> LISTA COMPLETA ATUAL\n");
    printAll(numbers);

    while (even != NULL || odd != NULL)
    {
        if (odd != NULL)
        {
            NODE *oddNumber = pop(&odd);
            push(&numbers, oddNumber);
        }
        if (even != NULL)
        {
            NODE *evenNumber = pop(&even);
            push(&numbers, evenNumber);
        }
    }

    printf("\n> LISTA COMPLETA DEPOIS DE RETORNAR OS VALORES\n");
    printAll(numbers);
    return 0;
}