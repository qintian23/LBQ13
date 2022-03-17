#include <stdio.h>
#include <stdlib.h>

typedef int T;

typedef struct node
{
    T data; // 数据域
    struct node* next; // 指针域
}Lnode, *Linklist;
