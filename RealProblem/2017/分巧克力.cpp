#include <stdio.h>
#include <math.h>
#define BSIZE 100001
struct st
{
    int h;
    int w;
};

st b[BSIZE]; 

int main(int argc, char* argv[])
{
    int cnt=0;
    // int allArea=0;
    int x=0, y=0;
    int n, k; // n块巧克力，k个小孩
    scanf("%d %d",&n, &k);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&b[i].h, &b[i].w);
        // allArea+=b[i].h*b[i].w;
    }

    // int r=int(sqrt(allArea/k));
    int r=BSIZE;
    // printf("%d\n",sup);
    int l=1;
    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        cnt=0;
        for(int i=0; i<n; i++)
        {
            x=int(b[i].h/mid);
            y=int(b[i].w/mid);
            cnt+=x*y;
            // printf("%d\n",cnt);
        }
        if(cnt>=k)
        {
            l=mid+1;
            ans=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    printf("%d\n",ans);
    return 0;
}