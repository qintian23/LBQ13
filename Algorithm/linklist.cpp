#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef int T;

typedef struct node
{
    T data; // 数据域
    struct node* next; // 指针域
}Lnode, *Linklist;

// 初始化链表
Status Creatlist(Linklist &list, int n, T data[])
{
    Lnode *p=(Lnode*)malloc(sizeof(Lnode));
    Lnode *temp=p;

    for (int i = 0; i < n; i++)
    {
        Lnode *node=(Lnode*)malloc(sizeof(Lnode));
        if(node)
        {
            node->data=data[i];
            node->next=NULL;

            temp->next=node;
            temp=temp->next;
        }
        else
        {
            printf("结点创建失败！\n");
            return ERROR;
        }
    }
    list=p;
    return OK;
}

// 在第i个位置插入元素
Status InsertNode(Linklist &list, int i, T e)
{
    int j=0;
    Lnode* p=list;
    while (p && j<i-1)
    {
        p=p->next;
        ++j;
    }
    if(!p || j>i-1) return ERROR;
    Lnode* s=(Lnode*)malloc(sizeof(Lnode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}
// 遍历
void display(Linklist list)
{
    while (list->next)
    {
        printf("%d", list->data);;
        list=list->next;
    }
    printf("\n");
}

// 返回链表长度

// 查找第i个元素


// 删除第i个元素

// 在位置i插入一个元素

int main(int argc, char** argv)
{
    T data[]={0,1,2,3,4,5};
    int n;
    Linklist list;
    Creatlist(list, n, data);
    display(list);
    return 0;
}