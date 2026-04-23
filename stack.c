#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

struct Stack
{
    void **arr;
    int top;
    size_t capacity;
};

struct Stack *init_stack()
{
    struct Stack *stack = malloc(sizeof(struct Stack));
    if (stack != NULL)
    {
        stack->arr = NULL;
        stack->top = -1;
        stack->capacity = 0;
    }
    return stack;
}

void free_stack(struct Stack *stack)
{
    if (stack != NULL)
    {
        if (stack->arr != NULL)
        {
            free(stack->arr);
        }
        free(stack);
    }
}

bool is_empty(struct Stack *stack)
{
    if (stack->top == -1)
        return true;

    return false;
}

void *append(struct Stack *stack, void *value)
{
    if ((size_t)(stack->top + 1) >= stack->capacity)
    {
        size_t new_cap = (stack->capacity == 0) ? 4 : stack->capacity * 2;

        void **arr = malloc(sizeof(stack->arr[0]) * new_cap);

        if (arr == NULL)
        {
            return stack;
        }

        for (int i = 0; i < stack->top + 1; ++i)
        {
            arr[i] = stack->arr[i];
        }

        free(stack->arr);
        stack->arr = arr;

        stack->capacity = new_cap;
    }

    stack->top++;
    stack->arr[stack->top] = value;

    return stack;
}

void *pop(struct Stack *stack)
{
    if (!is_empty(stack))
    {
        void *val = stack->arr[stack->top];
        stack->arr[stack->top] = NULL;
        stack->top--;
        return val;
    }
    return NULL;
}