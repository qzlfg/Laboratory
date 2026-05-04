#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stddef.h>

struct Stack
{
    void **arr;
    int top;
    size_t capacity;
};

struct Stack *init_stack();
void free_stack(struct Stack *stack);
bool is_empty(struct Stack *stack);
void *append(struct Stack *stack, void *value);
void *pop(struct Stack *stack);

#endif