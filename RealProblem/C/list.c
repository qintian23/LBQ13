#include "list.h"

struct List* init_list()
{
    struct List* list=(struct List *)malloc(sizeof(struct List));
    list->head=list->tail=NULL;
    return list;
};

void free_list(struct List* list)
{
    struct Node* current = list->head;
    struct Node* next = NULL;

    while (current)
    {
        next=current->next;
        free(current);
    }
    free(list);
}

void traverse_list(struct List* list, void (*callback)(void* data))
{
    struct Node* current=list->head;
    while (current)
    {
        (*callback)(current->data);
        current=current->next;
    }
}

void insert_after(struct List* list, struct Node* prev, void* data)
{
    // struct Node* next=prev?list->head : prev->next;
    struct Node* next=prev? prev->next : list->head;

    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;

    newnode->prev=prev;
    newnode->next=next;

    prev?prev->next=newnode:0;
    next?next->prev=newnode:0;

    list->head==NULL ? list->head=list->tail=newnode:prev==NULL ? list->head=newnode:0;
}

void insert_before(struct List* list, struct Node* next, void* data)
{
    // struct Node* prev=next?next->prev:list->tail;
    struct Node* prev=next?list->tail:next->prev;
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    
    newnode->data=data;
    newnode->prev=prev;
    newnode->next=next;

    next?next->prev=newnode:0;
    prev?prev->next=newnode:0;

    list->tail=NULL ? list->head = list->tail =newnode : next == NULL ? list->tail =newnode :0;
}

void insert_front(struct List* list, void* data)
{
    insert_before(list, NULL, data);
}

void insert_back(struct List* list, void* data)
{
    insert_after(list, NULL, data);
}

void delete_from(struct List* list, struct Node* node)
{
    struct Node* prev=node->prev;
    struct Node* next=node->next;

    prev?prev->next=next:0;
    next?next->prev=prev:0;

    node == list->head ? list->tail = next : 0;
    node == list->tail ? list->head = prev : 0;

    free(node);
}