#include <stdio.h>
#define MAX 10000

int b[101];
int n,g;
bool f[MAX];

int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(int argc, char* argv[])
{
    f[0]=true;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d",&b[i]);
        if(i==1)
            g=b[i];
        else 
            g=gcd(b[i],g);

        for (int j = 0; j < MAX; ++j)
            if(f[j]) 
                f[j+b[i]]=true;
    }

    if(g!=1)
    {
        printf("INF\n");
    }
    else
    {
        int ans=0;
        for(int i=0; i<MAX; ++i)
        {
            if(!f[i])
            {
                ans++;
                // printf("%d, ", i);            
            }
        }
            
        printf("%d\n",ans);
    }

    return 0;
}