#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int T;
const int MAXSIZE=100; // 链表初始化的最大长度
const int INCSIZE=10; // 动态链表每次增加的长度

// 是动态增长的谁需要说白点
// 动态顺序表的结构体
typedef struct
{
    T* data;
    int len; // 当前元素个数
    int size; // 当前顺序表最大容量
    int incsize; // 追加的空间量
}dqlist;

void Inclist(dqlist* &list);// 增加容量：重新分配一处更大的内存空间
void Initlist(dqlist* &list, T data[], int n);
void Createlist(dqlist* &list);// 初始化顺序表
void Searchval(dqlist* list, dqlist* &loc, int val);// 查找
int Insertval(dqlist* list, int i, T item);// 插入
void Delval(dqlist* &list, int val);// 删除：删除给定的值
// 修改
// 逆序
// 排序
void Displaylist(dqlist *list);// 输出

int main(int argc, char** argv)
{
    dqlist* list;
    Createlist(list);
    int data[]={1,2,3,4,5,6,7,8,9,10};
    int len=sizeof(data)/sizeof(int);
    Initlist(list,data,len);
    Displaylist(list);
    Delval(list,8);
    Displaylist(list);
    return 0;
}

// 初始化顺序表
void Createlist(dqlist* &list)
{
    int i=0;
    list->data=(T*)malloc(MAXSIZE * sizeof(T)); 
    assert(list->data!=NULL);
    list->len=0;
    list->incsize=INCSIZE;
    list->size=MAXSIZE;
}

// 增加容量：重新分配一处更大的内存空间
void Inclist(dqlist* &list)
{
    T* base=(T*)realloc(list->data,(list->size+list->incsize)*sizeof(T));
    assert(base!=NULL);
    list->data=base;
    list->size=list->size+list->incsize;
}

// 初始化
void Initlist(dqlist* &list, T data[], int n)
{
    int i=0,j=0;
    Createlist(list);
    while (true)
    {
        if (n>list->size) Inclist(list);
        else break;
    }
    
    list->len=n;
    while (n-- > 0)
        list->data[i++]=data[j++];
}

// 插入
int Insertval(dqlist* list, int i, T item)
{
    int* base, * inser_ptr, * p;
    if (i<1 || i>list->len+1)
        return ERROR;
    if(list->len>=list->size)
        Inclist(list);
    inser_ptr=&(list->data[i-1]);
    for (p=&(list->data[list->len-1]); p>=inser_ptr; p--)
        *(p+1)=*p;
    *inser_ptr=item;
    list->len++;
    return OK;
}

// 删除：删除给定的值
void Delval(dqlist* &list, int val)
{
    dqlist* loc;
    int j;
    Createlist(loc);
    Searchval(list, loc,val);
    for(int i=loc->data[j++]; i<list->len; i++)
    {
        int k=i;
        if(j<loc->len)
        {
            while (k<loc->data[j]) 
                list[k]=list[k+1];
        }
        else
        {
             while (k<loc->len) 
                list[k]=list[k+1];
        } 
    }
}

// 修改

// 查找
void Searchval(dqlist* list, dqlist* &loc, int val)
{
    for (int i = 0; i < list->len; i++)
        if(list->data[i]==val)
            Insertval(loc,loc->len-1,i);
}
// 逆序

// 排序

// 输出
void Displaylist(dqlist *list)
{
    // printf("%d\n",list->len);
    for (int i = 0; i < list->len; i++)
    {
        printf("%d, ",list->data[i]);
    }
    printf("\n");
}
