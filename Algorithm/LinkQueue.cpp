#include <stdio.h>
#include <stdlib.h>

#define QUEUESIZE 10
#define INCQUEUE 10

typedef int T;
// 采用链式存储结构的队列称为链队
typedef struct QNode
{
    T data;
    struct QNode* next;
}QNode, * QueuePtr;

typedef struct
{
    QueuePtr front; // 队头指针
    QueuePtr rear; // 队尾指针
}LinkQueue;

bool InitQueue(LinkQueue *queue);
void DestroyQueue(LinkQueue *queue);
bool QueueEmpty(LinkQueue queue);
bool Enqueue(LinkQueue *queue, T e);
bool Dequeue(LinkQueue *queue, T &e);

int main()
{
    LinkQueue queue;
    InitQueue(&queue);
    
    return 0;
}

// 初始化队列
bool InitQueue(LinkQueue *queue)
{
    queue=(LinkQueue*)malloc(sizeof(LinkQueue));
    if(queue==NULL) return false;
    queue->front=queue->rear=NULL;
    return true;
}
// 销毁队列
void DestroyQueue(LinkQueue *queue)
{
    QNode *pre=queue->front, *p; // pre指向队首结点
    if(pre!=NULL)
    {
        p=pre->next; // p指向结点pre的后继结点
        while (p!=NULL)
        {
            free(pre); // 释放最后一个数据结点
            pre=p;
            p=p->next; // pre,p同步后移
        }
        free(pre);
    }
    free(queue);
}
// 队列判空
bool QueueEmpty(LinkQueue queue)
{
    return queue.rear==NULL;
}
// 进队列
bool Enqueue(LinkQueue *queue, T e)
{
    QNode *p;
    p=(QNode*)malloc(sizeof(QNode));
    if(p==NULL) return false;
    p->data=e;
    p->next=NULL;
    if(queue->rear==NULL) // 若链队为空，则新结点既是队首结点优势队尾结点
        queue->front=queue->rear=p;
    else // 若链队非空，将结点p链到队尾，并将rear指向它
    {
        queue->rear->next=p;
        queue->rear=p;
    }
    return true;
}
// 出队列
bool Dequeue(LinkQueue *queue, T &e)
{
    QNode *t;
    if (queue->rear==NULL)
        return false;
    t=queue->front;
    if(queue->front==queue->rear) // 原来队列中只有一个数据结点时
        queue->front=queue->rear=NULL;
    else // 原来队列中只有两个及以上的数据结点时
        queue->front=queue->front->next;
    e=t->data;
    free(t);
    return true;
}
