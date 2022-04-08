#include <iostream>
#include <cstring>
#include <cstdio>
#define _for(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int N=2e6;
int A,B,C,M;
struct xy{
    int x1,y1,z1,x2,y2,z2,t;
}T[N];
int s[N],c[N];
void xg(int ff,int l,int f)
{
    for(l++;l<=f;l++)
    {
        int x1=T[l].x1,x2=T[l].x2,y1=T[l].y1,y2=T[l].y2,z1=T[l].z1,z2=T[l].z2,t=ff*T[l].t;
        c[x1*B*C+y1*C+z1]+=t;
        c[(x2+1)*B*C+y1*C+z1]-=t;
        c[x1*B*C+(y2+1)*C+z1]-=t;
        c[x1*B*C+y1*C+z2+1]-=t;
        c[(x2+1)*B*C+(y2+1)*C+z1]+=t;
        c[(x2+1)*B*C+y1*C+(z2+1)]+=t;
        c[x1*B*C+(y2+1)*C+z2+1]+=t;
        c[(x2+1)*B*C+(y2+1)*C+z2+1]-=t;
    }
    _for(i,1,A+1)
        _for(j,1,B+1)
            _for(k,1,C+1)
                c[i*B*C+j*C+k]+=c[(i-1)*B*C+j*C+k]+c[i*B*C+(j-1)*C+k]+c[i*B*C+j*C+k-1]-c[(i-1)*B*C+(j-1)*C+k]-c[(i-1)*B*C+j*C+k-1]-c[i*B*C+(j-1)*C+k-1]+c[(i-1)*B*C+(j-1)*C+k-1];
}
int main()
{
    std::ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>A>>B>>C>>M;
    _for(i,1,A+1)
        _for(j,1,B+1)
            _for(k,1,C+1)
                cin>>s[i*B*C+j*C+k];
    _for(i,1,M+1)
        cin>>T[i].x1>>T[i].x2>>T[i].y1>>T[i].y2>>T[i].z1>>T[i].z2>>T[i].t;
    int l=0,f=M,fast=0;
    while(l<=f)
    {
        int cnt=(l+f)>>1;
        bool p=1;
        memset(c,0,sizeof(c));
        if(fast<=cnt)
            xg(-1,fast,cnt);
        else
            xg(1,cnt,fast);
        _for(i,1,A+1)
            _for(j,1,B+1)
                _for(k,1,C+1){
                    s[i*B*C+j*C+k]+=c[i*B*C+j*C+k];
                    if(s[i*B*C+j*C+k]<0)
                        p=0;
                }
        if(p)
            l=cnt+1;
        else
            f=cnt-1;
        fast=cnt;
    }
    cout<<l;
}

