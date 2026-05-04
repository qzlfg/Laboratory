#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "node.h"

struct Node *init_node(void *data)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    if (new_node != NULL)
    {
        new_node->data = data;
        new_node->next = NULL;
    }
    return new_node;
}

struct Node *insert_node(struct Node *head, int idx, void *value)
{
    struct Node *nd = init_node(value);

    if (nd == NULL)
    {
        return head;
    }

    struct Node *node = head;
    if (idx == 1 || head == NULL)
    {
        nd->next = head;
        return nd;
    }
    else
    {
        int count = 1;

        struct Node *curr = node;

        while (curr->next != NULL && count < idx - 1)
        {
            curr = curr->next;
            count++;
        }

        nd->next = curr->next;
        curr->next = nd;
    }

    return head;
}

struct Node *remove_node(struct Node *head, int idx)
{
    struct Node *node = head;

    if (head == NULL)
    {
        return NULL;
    }

    if (idx == 1)
    {

        struct Node *temp = head;
        head = head->next;

        free(temp);

        return head;
    }

    int count = 1;
    struct Node *curr = node;

    while (curr != NULL && curr->next != NULL && count < idx - 1)
    {
        curr = curr->next;
        count++;
    }

    if (curr == NULL || curr->next == NULL)
    {
        return head;
    }

    struct Node *rem = curr->next;
    curr->next = curr->next->next;
    free(rem);

    return head;
}

struct Node *find_node(struct Node *head, int idx)
{
    if (head == NULL || idx < 1)
    {
        return NULL;
    }

    int count = 1;

    while (head != NULL && count < idx)
    {
        count++;
        head = head->next;
    }

    return head;
}

int count_node(struct Node *head)
{
    int count = 0;

    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}