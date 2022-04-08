#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
typedef long long LL;
using namespace std;
LL n, S;
double ans, avg;

void work()
{
    scanf("%d%ld",&n,&S);
    ans=0.0;
    avg=1.0*S/n;
    LL *a=new LL[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%ld",&a[i]);
    }
    sort(a, a+n);
    for (int i = 0; i < n; ++i)
    {
        if(a[i]*(n-i)<S)
        {
            ans+=(a[i]-avg)*(a[i]-avg);
            S-=a[i];
        }
        else
        {
            double cur_avg=1.0*S/(n-i);
            ans+=(avg-cur_avg)*(avg-cur_avg)*(n-i);
            break;
        }
    }
    printf("%.4lf\n",sqrt(ans/n));
    
}

int main(int argc, char *argv[])
{
    work();
    return 0;
}