#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int value;
    struct NODE *leftNode;
    struct NODE *rightNode;
} NODE;

typedef struct TREE
{
    int length;
    NODE *root;
} TREE;

TREE *createTree()
{
    TREE *newTree = (TREE *)malloc(sizeof(TREE));
    newTree->length = 0;
    newTree->root = NULL;
    return newTree;
}

NODE *createNode(int value)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->value = value;
    newNode->leftNode = NULL;
    newNode->rightNode = NULL;
    return newNode;
}

void insertNode(TREE *tree, NODE *root, int value)
{
    if (root == NULL)
    {
        NODE *newNode = createNode(value);
        tree->root = newNode;
        tree->length++;
        return;
    }
    if (value < root->value)
    {
        if (root->leftNode != NULL)
            return insertNode(tree, root->leftNode, value);
        NODE *newNode = createNode(value);
        root->leftNode = newNode;
        tree->length++;
    }
    else if (value >= root->value)
    {
        if (root->rightNode != NULL)
            return insertNode(tree, root->rightNode, value);
        NODE *newNode = createNode(value);
        root->rightNode = newNode;
        tree->length++;
    }
}

NODE *findNodeWithParent(NODE *root, int value, NODE **parent)
{
    if (root == NULL)
        return NULL;
    *parent = NULL;
    while (root != NULL)
    {
        if (value == root->value)
            return root;
        *parent = root;
        if (value < root->value)
            root = root->leftNode;
        else
            root = root->rightNode;
    }
    return NULL;
}

void removeNode(TREE *tree, int value)
{
    NODE *node = NULL, *parent = NULL, *substituteNode = NULL, *substituteNodeParent = NULL;
    node = findNodeWithParent(tree->root, value, &parent);
    if (node == NULL)
        return;
    if (node->leftNode == NULL || node->rightNode == NULL)
    {
        if (node->leftNode == NULL)
            substituteNode = node->rightNode;
        else if (node->rightNode == NULL)
            substituteNode = node->leftNode;
    }
    else
    {
        substituteNodeParent = node;
        substituteNode = node->leftNode;
        while (substituteNode->rightNode != NULL)
        {
            substituteNodeParent = substituteNode;
            substituteNode = substituteNode->rightNode;
        }

        if (substituteNodeParent != node)
        {
            substituteNodeParent->rightNode = substituteNode->leftNode;
            substituteNode->leftNode = node->leftNode;
        }
        substituteNode->rightNode = node->rightNode;
    }

    if (parent == NULL)
    {
        tree->root = substituteNode;
        free(node);
        return;
    }

    if (value < parent->value)
        parent->leftNode = substituteNode;
    else
        parent->rightNode = substituteNode;
    free(node);
}

void printAll(NODE *root, int level)
{
    if (root == NULL)
        return;
    int index = 0;
    for (index = 0; index < level; index++)
        printf("  ");
    printf("%d\n", root->value);
    printAll(root->leftNode, level + 1);
    printAll(root->rightNode, level + 1);
}

typedef struct ITEM
{
    int value;
    struct ITEM *next;
} ITEM;

typedef struct QUEUE
{
    ITEM *start;
    ITEM *end;
} QUEUE;

ITEM *createItem(int value)
{
    ITEM *newNodeList = (ITEM *)malloc(sizeof(ITEM));
    newNodeList->value = value;
    newNodeList->next = NULL;
    return newNodeList;
}

QUEUE *createQueue()
{
    QUEUE *newQueue = (QUEUE *)malloc(sizeof(QUEUE));
    newQueue->start = NULL;
    newQueue->end = NULL;
    return newQueue;
}

void push(QUEUE *queue, int value)
{
    ITEM *newItem = createItem(value);
    if (queue->start == NULL)
    {

        queue->start = newItem;
        queue->end = newItem;
        return;
    }
    queue->end->next = newItem;
    queue->end = newItem;
}

void pop(QUEUE *queue)
{
    if (queue->start == NULL)
        return;

    if (queue->start == queue->end)
    {
        free(queue->start);
        queue->start = NULL;
        queue->end = NULL;
        return;
    }

    ITEM *lastStartItem = queue->start;
    queue->start = lastStartItem->next;
    free(lastStartItem);
}

void printAllQueue(ITEM *item)
{
    if (item == NULL)
        return;
    while (item != NULL)
    {
        printf("%d ", item->value);
        item = item->next;
    }
}

ITEM *treeToList(NODE *root)
{
    if (root == NULL)
        return NULL;
    QUEUE *queue = createQueue();
    push(queue, root->value);
    NODE *currentRoot = root, *left = NULL, *right = NULL;
    while (currentRoot != NULL)
    {
        if (currentRoot->leftNode != NULL)
            push(queue, currentRoot->leftNode->value);
        if (currentRoot->rightNode != NULL)
        {
            push(queue, currentRoot->rightNode->value);
        }
        currentRoot = currentRoot->leftNode;
    }
    return queue->start;
}

int main()
{
    TREE *tree = createTree();
    insertNode(tree, tree->root, 8);
    insertNode(tree, tree->root, 6);
    insertNode(tree, tree->root, 10);
    insertNode(tree, tree->root, 3);
    insertNode(tree, tree->root, 7);
    insertNode(tree, tree->root, 9);
    insertNode(tree, tree->root, 15);
    insertNode(tree, tree->root, 1);
    insertNode(tree, tree->root, 4);
    insertNode(tree, tree->root, 14);
    insertNode(tree, tree->root, 20);
    printAll(tree->root, 0);

    ITEM *list = treeToList(tree->root);
    printf("Transformando em uma fila contendo cada nível temos:\n");
    printAllQueue(list);
    return 0;
}