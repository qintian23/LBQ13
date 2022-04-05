#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node* next;
};
static struct node *phead=NULL;

static struct node *create_node(int val)
{
    struct node *pnode=NULL;
    pnode=(struct node*)malloc(sizeof(struct node));
    if(!pnode) return NULL;
    pnode->val=val;
    pnode->next=NULL;
    return pnode;
}

static void destory_single_link()
{
    struct node *pnode=NULL;
    while (phead!=NULL)
    {
        pnode=phead;
        phead=phead->next;
        free(pnode);
    }   
}

static void add(int val)
{
    if(!phead)
    {
        phead=create_node(val);
        return ;
    }
    struct node *pnode=create_node(val);
    struct node *pend=phead;
    while (pend->next)
    {
        pend=pend->next;
    }
    pend->next=pnode;
}

static int front()
{
    // TODO
}

static int pop()
{
    // TODO
}

static int count()
{
    // TODO
}

static int is_empty()
{
    // TODO
}

int main()
{
    add(1);
    add(2);
    add(3);
    add(4);
    add(5);
    add(6);
    printf("%d", front());
    printf("%d", pop());
    printf("%d", front());
    printf("%d", count());
    printf("%d", is_empty());
    return 0;
}