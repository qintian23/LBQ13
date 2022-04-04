#include <stdio.h>
#include "list.h"

void print_string(void* s)
{
    printf("%s\n",(char *)s);
}

int main()
{
    struct List* list=init_list();

    insert_front(list, "online");
    insert_front(list, "shiyanlou");
    insert_back(list, "lab");
    insert_front(list, "hello");
    insert_front(list, "welcome");
    delete_from(list, list->head->next);
    delete_from(list, list->tail);
    insert_before(list, list->head->next, "to");
    traverse_list(list, print_string);

    free_list(list);
    return 0;
}