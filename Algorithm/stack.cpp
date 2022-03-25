#include <stdio.h>
#include <stdlib.h>

// 栈的初始化
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0

typedef int T;

// 顺序栈定义
typedef struct 
{
    T* base; // 栈底指针
    T* top; // 栈顶指针
    int size; // 当前可用最大容量
}sqStack;

int InitStack(sqStack* s);
int Push(sqStack* s, T e);// 入栈操作
int Pop(sqStack* s, T* e);// 出栈操作

int main(int argc, char** argcv)
{
    sqStack s;
    InitStack(&s);
    printf("%d\n",s.size);

    int data[]={2,3,1,4,6,5,7,9,8};
    int len=sizeof(data)/sizeof(int);
    for(int i=0; i<len; i++)
        Push(&s,data[i]);
    
    int val;
    Pop(&s,&val);
    printf("%d\n",val);

    return 0;
}

int InitStack(sqStack* s)
{
    s->base=(T*)malloc(STACK_INIT_SIZE*sizeof(T));
    if(!s->base) return ERROR;
    s->top=s->base;
    s->size=STACK_INIT_SIZE;
    return OK;
}

// 入栈操作
int Push(sqStack* s, T e)
{
   if(s->top-s->base >= s->size)
   {
       s->base=(T*)realloc(s->base,s->size+STACKINCREMENT*sizeof(T));
       if(!s->base) return ERROR;
       s->top=s->base+s->size;
       s->size=s->size+STACKINCREMENT;
   }
   *(s->top)=e;
   s->top++;
   return OK;
}

// 出栈操作
int Pop(sqStack* s, T* e)
{
    if(s->top==s->base) return ERROR; // 栈满
    *e=*--(s->top);
    return OK;
}
