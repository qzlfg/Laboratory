#ifndef NODE_H
#define NODE_H

#include <stddef.h>

struct Node
{
    void *data;
    struct Node *next;
};

struct Node *init_node(void *data);
struct Node *insert_node(struct Node *head, int idx, void *value);
struct Node *remove_node(struct Node *head, int idx);
struct Node *find_node(struct Node *head, int idx);
int count_node(struct Node *head);

#endif