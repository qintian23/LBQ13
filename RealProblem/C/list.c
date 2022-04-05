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

void insert_before(struct List* list, struct Node* prev, void* data)
{
    struct Node* next=prev? prev->next:list->head; // 有bug，插入结点的后向指针：如果该节点的前向指针为空，则指向链表头部，否则指向该节点后面
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));

    newnode->data=data;
    newnode->prev=prev;
    newnode->next=next;

    prev?prev->next=newnode:0;
    next?next->prev=newnode:0;

    list->head==NULL ? list->head = list->tail=newnode : prev == NULL ? list->head=newnode : 0;
}

void insert_after(struct List* list, struct Node* next, void* data)
{
    struct Node* prev=next?next->prev:list->tail; // 插入结点的前向指针：如果后向指针为空，则指向链表尾部，否则指向该节点前面
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node)); // 声明插入结点

    newnode->data=data; // 赋值
    newnode->prev=prev; // 新节点的前向指针指向原前向结点
    newnode->next=next; // 新节点的后向指针指向该结点
    
    next?next->prev=newnode:0; // 在该节点之前插入结点，否则不操作（在尾部）
    prev?prev->next=newnode:0; // 原前向结点的后向指针指向插入结点
   
    // 当尾指针不为空，即插入结点在尾部，需要把尾指针重指向
    list->tail==NULL ? list->head = list->tail =newnode : next == NULL ? list->tail =newnode : 0;
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

    // node == list->head ? list->tail = next : 0;
    // node == list->tail ? list->head = prev : 0;

    node == list->head ? list->head = next : 0;
    node == list->tail ? list->tail = prev : 0;

    free(node);
}