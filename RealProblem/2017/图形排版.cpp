#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int MX=1e5+5;
int M,N;
int w[MX],h[MX],t[MX];
void attach(int i,int &W,int &H)
{
     
    if(W+w[i]>M)
        H=max(H,(int)ceil(1.0*h[i]*(M-W)/w[i])); 
    else
        H=max(H,h[i]);
    W=min(M,W+w[i]);
}
int calc(int i,int W,int H)
{
    while(i<N&&W<M)
        attach(i++,W,H);
    return H+t[i];
}
int main()
{
    scanf("%d%d",&M,&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&w[i],&h[i]);
    }
    for(int i=N-1;i>=0;i--)
    {
        t[i]=calc(i,0,0);
    }
     
    int res=t[0];
    int tmp;
    int pre_h=0;
    int W=0,H=0;
    for(int i=0;i<N;i++)
    {
        tmp=calc(i+1,W,H);
        res=min(res,pre_h+tmp);
        attach(i,W,H);
        if(W==M)
        {
            pre_h+=H;
            W=0;
            H=0;
        }
    }
    cout<<res<<endl;
    return 0;
}