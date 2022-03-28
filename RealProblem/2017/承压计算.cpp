#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(int argc, char* argv[])
{
    ll data[30][30];
    ll fractor=1;
    for(int i=0; i<20; ++i)
    {
        fractor<<=1;
    }
    cout<< fractor <<endl;
    for(int i=0; i<29; ++i)
    {
        for(int j=0; j<=i; ++j)
        {
            ll d=0;
            scanf("%lld",&d);
            data[i][j]=d*fractor;
        }
    }

    for(int i=0; i<29; ++i)
    {
        for(int j=0; j<=i; ++j)
        {
            ll h=data[i][j]/2;
            data[i+1][j]+=h;
            data[i+1][j+1]+=h;
        }
    }

    sort(data[29], data[29]+30);
    // printf("%lld, %lld\n",data[29][0], data[29][29]); 
    // 每一次输出都不一样？？
    cout<< data[29][0] << "," <<  data[29][29] <<endl;
    // for(int i=0; i<30; i++)
    // {
    //     cout<< data[29][i] <<endl;
    // }
    return 0;
}
