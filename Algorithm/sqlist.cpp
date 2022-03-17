#include <stdio.h>
#include <stdlib.h>

typedef int T;
const int MAXSIZE=100; // 链表初始化的最大长度
const int INCSIZE=10; // 动态链表每次增加的长度

// 动态顺序表的结构体
typedef struct
{
    T* data;
    int len; // 当前元素个数
    int size; // 当前顺序表最大容量
}dqlist;

// 初始化顺序表
void Createlist(dqlist &list)
{
    list.data=(T*)malloc(MAXSIZE);
    list.len=0;
    list.size=MAXSIZE;
}

// 增加容量：重新分配一处更大的内存空间
void Inclist(dqlist &list)
{
    T* newdata=(T*)malloc(list.size+INCSIZE);
    // 把原数据拷贝到新内存
    for(int i=0; i<list.len; i++)
        newdata[i]=list.data[i];
    
    // 更新动态顺序表指针和其他属性值
    list.data=newdata;
    list.size=list.size+INCSIZE;
}

// 插入

// 删除：删除给定的值
void Delval(dqlist &list, int val)
{
    
}

// 修改

// 查找

// 逆序

// 排序

int main(int argc, char** argv)
{
    return 0;
}