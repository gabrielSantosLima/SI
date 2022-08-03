#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NO
{
    char value;
    struct NO *next;
} NODE;

NODE *createNode(char value)
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
    while (nodes != NULL)
    {
        printf("%c ", nodes->value);
        nodes = nodes->next;
    }
}

bool isPalindrome(NODE **nodes)
{
    bool isPalindrome = true;
    NODE *invertedNodes = NULL;
    NODE *invertedNodesWithReference = NULL;
    while (*nodes != NULL)
    {
        NODE *node = pop(nodes);
        push(&invertedNodes, createNode(node->value));
        push(&invertedNodesWithReference, node);
    }

    while (invertedNodesWithReference != NULL)
    {
        NODE *node = pop(&invertedNodesWithReference);
        push(nodes, node);
    }

    while (*nodes != NULL)
    {
        NODE *node = pop(nodes);
        NODE *nodeInverted = pop(&invertedNodes);
        if (node->value != nodeInverted->value)
        {
            isPalindrome = false;
        }
        push(&invertedNodesWithReference, node);
        free(nodeInverted);
    }
    return isPalindrome;
}

int main()
{
    NODE *nodes = NULL;
    push(&nodes, createNode('A'));
    push(&nodes, createNode('R'));
    push(&nodes, createNode('A'));
    push(&nodes, createNode('R'));
    push(&nodes, createNode('A'));

    if (isPalindrome(&nodes))
    {
        printf("Eh palindromo.");
    }
    else
    {
        printf("Nao eh palindromo.");
    }
    return 0;
}