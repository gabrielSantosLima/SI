#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct NODES
{
    int length;
    int nodes[MAX];
} NODES;

NODES *createList()
{
    NODES *newNodes = (NODES *)malloc(sizeof(NODES));
    newNodes->length = 0;
    return newNodes;
}

void add(NODES *nodes, int value)
{
    if (nodes->length == MAX)
    {
        printf("Lista Cheia");
        return;
    }
    nodes->nodes[nodes->length] = value;
    nodes->length++;
}

void printAll(NODES nodes)
{
    int index;
    if (nodes.length == 0)
    {
        printf("Lista Vazia");
        return;
    }
    for (index = 0; index < nodes.length; index++)
    {
        printf("%d ", nodes.nodes[index]);
    }
}

NODES *divide(NODES nodes, int p)
{
    if (p >= nodes.length || p < 0)
    {
        printf("Índice inválido");
        return NULL;
    }
    NODES *splittedNodes = (NODES *)malloc(sizeof(NODES) * 2);
    splittedNodes[0] = *createList();
    splittedNodes[1] = *createList();
    int index;
    for (index = 0; index < nodes.length; index++)
    {
        if (index <= p)
        {
            add(&splittedNodes[0], nodes.nodes[index]);
        }
        else
        {
            add(&splittedNodes[1], nodes.nodes[index]);
        }
    }
    return splittedNodes;
}

int main()
{
    NODES *nodes = createList();
    add(nodes, 1);
    add(nodes, 2);
    add(nodes, 3);
    add(nodes, 4);
    add(nodes, 5);
    printAll(*nodes);
    printf("\n");

    NODES *splittedNodes = divide(*nodes, 20);

    if (splittedNodes == NULL)
    {
        printf("\nLista inválida");
    }
    else
    {
        printAll(splittedNodes[0]);
        printAll(splittedNodes[1]);
    }

    return 0;
}