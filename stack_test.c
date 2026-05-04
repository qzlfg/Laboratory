#include <assert.h>
#include <stdio.h>

#include "stack.h"

int main()
{
    printf("Запуск тестов для stack.c\n");

    struct Stack *stack = init_stack();
    assert(stack != NULL);
    assert(is_empty(stack) == true);

    int val1 = 100, val2 = 200, val3 = 300, val4 = 400, val5 = 500;

    append(stack, &val1);
    assert(is_empty(stack) == false);
    assert(stack->top == 0);
    assert(stack->capacity == 4);

    append(stack, &val2);
    append(stack, &val3);
    append(stack, &val4);

    append(stack, &val5);
    assert(stack->top == 4);
    assert(stack->capacity == 8);

    void *popped = pop(stack);
    assert(popped == &val5);
    assert(stack->top == 3);

    pop(stack);
    pop(stack);
    pop(stack);

    popped = pop(stack);
    assert(popped == &val1);
    assert(is_empty(stack) == true);

    assert(pop(stack) == NULL);

    free_stack(stack);

    printf("Все тесты stack.c пройдены успешно!\n");
    return 0;
}