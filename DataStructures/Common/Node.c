#include "Node.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// the constructor is used to create new instance of nodes
struct Node node_constructor(void *data, unsigned long size)
{
    if (size < 1)
    {
        // confirm the size of the data is atleast one, otherwise exit with an error message
        printf("Invalid data size for the node...\n");
        exit(1);
    }
    // create a node instance to be returned
    struct Node node;
    // allocate space for the data if it is of a supported type
    node.data = malloc(size);
    memcpy(node.data, data, size);
    // initialize the pointer
    node.next = NULL;
    node.previous = NULL;
    return node;
}

// the destructor removes a node by freeing the node's data and its node
void node_destructor(struct Node *node)
{
    free(node->data);
    free(node);
}