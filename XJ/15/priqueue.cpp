#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>

using namespace std;

struct square
{
    int length;
    int width;
    square(int l, int w) : length(l),width(w){}
};

// 优先队列默认的权重比较算法仅限于基本类型，不适用于自定义类型，因此需要使用函数对象实现权重比较算法
struct compare
{
    bool operator()(square x, square y)
    {
        return ((x.length * x.width) < (y.length * y.width));
    }
};

int main()
{
    priority_queue<square,vector<square>,compare> p;

    for (int i = 0; i < 10; i++)
    {
        p.push(square(rand()%100+1,rand()%100+1));
    }

    while(!p.empty())
    {
        cout<< p.top().length << " * " << p.top().width << endl;
        p.pop();
    }
    
    return 0;
}