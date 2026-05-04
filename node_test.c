#include <assert.h>
#include <stdio.h>

#include "node.h"

int main()
{
    printf("Запуск тестов для node.c\n");

    int val1 = 10;

    struct Node *head = init_node(&val1);
    assert(head != NULL);
    assert(head->data == &val1);
    assert(count_node(head) == 1);

    int val2 = 20;
    int val3 = 30;

    head = insert_node(head, 2, &val2);
    head = insert_node(head, 1, &val3);
    assert(count_node(head) == 3);

    struct Node *found = find_node(head, 2);
    assert(found != NULL);
    assert(found->data == &val1);

    head = remove_node(head, 2);
    assert(count_node(head) == 2);

    head = remove_node(head, 1);
    head = remove_node(head, 1);
    assert(count_node(head) == 0);

    printf("Все тесты node.c пройдены успешно!\n");
    return 0;
}