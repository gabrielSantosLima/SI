#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NO
{
    int content;
    struct NO *nextNode;
} NODE;

NODE *createNode(int content)
{
    NODE *node = (NODE *)malloc(sizeof(NODE));
    node->content = content;
    node->nextNode = NULL;
    return node;
}

void insert(NODE **nodes, int content)
{
    NODE *initialNode = *nodes;

    if (*nodes == NULL)
    {
        NODE *newNode = createNode(content);
        *nodes = newNode;
        return;
    }

    while ((*nodes)->nextNode != NULL)
    {
        *nodes = (*nodes)->nextNode;
    }

    NODE *newNode = createNode(content);
    (*nodes)->nextNode = newNode;
    *nodes = initialNode;
}

int getSize(NODE *nodes)
{
    int size = 0;

    while (nodes != NULL)
    {
        size++;
        nodes = nodes->nextNode;
    }
    return size;
}

bool isEmpty(NODE *nodes)
{
    return getSize(nodes) == 0;
}

void removeLast(NODE **nodes)
{
    if (*nodes == NULL)
        return;

    if (getSize(*nodes) == 1)
    {
        free(*nodes);
        *nodes = NULL;
        return;
    }

    NODE *initialNode = *nodes;

    while ((*nodes)->nextNode->nextNode != NULL)
    {
        *nodes = (*nodes)->nextNode;
    }

    free((*nodes)->nextNode);
    (*nodes)->nextNode = NULL;
    *nodes = initialNode;
}

void getAll(NODE *nodes)
{
    printf("======== LISTA COMPLETA ========\n");
    if (isEmpty(nodes))
    {
        printf("Lista Vazia");
    }
    while (nodes != NULL)
    {
        printf("%d ", nodes->content);
        nodes = nodes->nextNode;
    }
    printf("\n================================\n");
}

NODE *concat(NODE *nodes1, NODE *nodes2)
{
    NODE *newNodes = NULL;
    while (nodes1 != NULL)
    {
        insert(&newNodes, nodes1->content);
        nodes1 = nodes1->nextNode;
    }
    while (nodes2 != NULL)
    {
        insert(&newNodes, nodes2->content);
        nodes2 = nodes2->nextNode;
    }
    return newNodes;
}

int main()
{
    NODE *nodes = NULL;
    insert(&nodes, 2);
    insert(&nodes, 3);
    insert(&nodes, 4);
    insert(&nodes, 5);

    NODE *nodes2 = NULL;
    insert(&nodes2, 7);
    insert(&nodes2, 8);

    getAll(nodes);
    removeLast(&nodes);
    getAll(nodes);

    NODE *newNodes = concat(nodes, nodes2);
    getAll(newNodes);

    return 0;
}