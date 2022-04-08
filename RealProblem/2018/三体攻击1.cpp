#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
#define loop(i,x,y) for(register int i=(x); i<=(y); i++)
#define loop_d(i,x,y) for(register int i=(x); i>=(y); i--)
#define getx(i,j,k) (((i)-1)*b+((j)-1))*c+(k) // i, j, k均从1开始计数
int A, B, C, m, a, b, c;

void add(LL cc[], int i, int j, int k, int h)
{
    if(i < a && j < b && k < c)
        cc[getx(i,j,k)]+=h;
}

void show(LL a[])
{
    loop(i,1,A)loop(j,1,B)loop(k,1,C) cout<< a[getx(i,j,k)] << ' ';
    cout<< endl;
}

void op(LL cc[], int *atk, int x)
{
    int la=atk[0], ra=atk[1], lb=atk[2], rb=atk[3], lc=atk[4], rc=atk[5], h=x*atk[6];
    add(cc, la, lb, lc, h);
    add(cc, la, rb+1, lc, -h);
    add(cc, la, lb, rc+1, -h);
    add(cc, la, rb+1, rc+1, h);
    add(cc, ra+1, lb, lc, -h);
    add(cc, ra+1, rb+1, lc, h);
    add(cc, ra+1, lb, rc+1, h);
    add(cc, ra+1, rb+1, rc+1, -h);

    // show(cc);
}

bool check(LL sum[], const LL d[])
{
    loop(i,2,A) loop(j,1,B) loop(k,1,C) sum[getx(i,j,k)] += sum[getx(i-1,j,k)];

    loop(i,1,A) loop(j,2,B) loop(k,1,C) sum[getx(i,j,k)] += sum[getx(i,j-1,k)];

    loop(i,1,A) loop(j,1,B) loop(k,2,C) sum[getx(i,j,k)] += sum[getx(i,j,k-1)];

    loop(i,1,A) loop(j,1,B) loop(k,1,C) 
        if(sum[getx(i,j,k)]>d[getx(i,j,k)])
            return true;
    
    return false;
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0); // 加快读写速度

    cin>> A >> B >> C >> m;

    a=A+1;
    b=B+1;
    c=C+1;

    LL *cc=new LL[a*b*c]; // 差分数组
    LL *d=new LL[a*b*c]; // 原始血量
    LL *sum=new LL[a*b*c]; //差分数组的前缀和
    int (*atk)[7]=new int[m+1][7]; // 攻击数据

    // 输入血量
    loop(i,1,A) loop(j,1,B) loop(k,1,C) cin>> d[getx(i,j,k)];
    // 输入攻击数据
    loop(i,1,m) loop(j,1,6) cin>> atk[i][j];

    int l=1, r=m, lastMid=0;
    while (l<r)
    {
        int mid=(l+r)>>1;
        if(lastMid<mid) // 上一次攻击没有攻破，继续攻击
        {
            for(int i=lastMid+1; i<=mid; ++i)
            {
                op(cc, atk[i], 1);
            }
        }

        if(lastMid>mid) // 上一次攻击攻破，恢复血量
        {
            for(int i=mid+1; i<=lastMid; ++i)
            {
                op(cc, atk[i], -1);
            }
        }

        memcpy(sum, cc, sizeof(LL)*a*b*c); // 把差分数组拷贝给前缀和数组
        if(check(sum, d))
            r=mid;
        else
            l=mid+1;
        lastMid=mid;
    }
    
    cout<< r <<endl;
    delete[] cc;
    delete[] d;
    delete[] sum;
    delete[] atk;
    return 0;
}

/*
2 2 2 3
1 1 1 1 1 1 1 1
1 2 1 2 1 1 1
1 1 1 2 1 2 1
1 1 1 1 1 1 2
*/

// 2