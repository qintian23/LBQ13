#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int M,N; // N张图片: 1 ~ 1e5; M宽度: 1~100
const int MAX=1e5+5;
int f[MAX];
struct pic
{
    int h,w;
}pics[MAX];
struct line
{
    int w,h;
    line(){w=0,h=0;}
    line(int _w, int _h)
    {
        w=_w;
        h=_h;
    }
    line operator+(pic _p)
    {
        if(w+_p.w>M)
        {
            _p.h=ceil(1.0*_p.h*(M-w)/_p.w);
            _p.w=M-w;
        }
        return line(w+_p.w,max(h,_p.h));
    }
    bool full()
    {
        return w==M;
    }
    void clr(){w=h=0;}
};

int push_till_full(line a, int k)
{
    for (; k <= N && a.full(); ++k)
    {
        a=a+pics[k];
    }
    return a.h+f[k];
}

int main(int argc, char* argv[])
{
    cin>> M >> N;
    for (int i = 0; i < N; i++)
        cin>> pics[i].w >> pics[i].h;
    for (int i = N; i >= 1; --i)
        f[i]=push_till_full(line(0,0),i);

    line a;
    int per=0;
    int ans=1e7;
    for (int i = 1; i <= N; ++i)
    {
        int new_h=per+push_till_full(a,i+1);
        ans=min(ans,new_h);
        a=a+pics[i];
        if(a.full())
        {
            per+=a.h;
            a.clr();
        }
    }
    cout<< ans  <<endl;
    return 0;
}