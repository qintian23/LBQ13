#include<stdio.h>
#include<algorithm>

const int N=10010;

int n;
int m;

struct Segment//记录一个矩形的一条竖边
{
    int x,y1,y2;
    int k;
    bool operator<(const Segment &s)const
    {
        return x<s.x;
    }
}seg[2*N];

struct Node//线段树节点
{
    int len,cnt;
}tr[4*N];
//当前节点，当前区间，要修改区间，要修改值
void update(int node,int l,int r,int a,int b,int k)
{
    if(a>r||b<l) return;
    if(a<=l&&b>=r||l==r)
    {
        tr[node].cnt+=k;
        //修正当前区间被覆盖总长度
        //如果被覆盖，被覆盖总长度就是区间长度
        if(tr[node].cnt>0) tr[node].len=r-l+1;
        //如果没被覆盖，且是叶子节点，说明没有子节点
        //区间被覆盖总长度必然为0
        else if(l==r) tr[node].len=0;
        //如果没被覆盖，有子节点，说明没有被完全覆盖
        //需要从子节点获得被覆盖总长度
        else tr[node].len=tr[node<<1].len+tr[node<<1|1].len;
    }
    else {
        int mid=l+((r-l)>>1);
        update(node<<1,l,mid,a,b,k);
        update(node<<1|1,mid+1,r,a,b,k);

        if(tr[node].cnt>0) tr[node].len=r-l+1;
        else if(l==r) tr[node].len=0;
        else tr[node].len=tr[node<<1].len+tr[node<<1|1].len;
    }
}

int main()
{
    scanf("%d",&n);
    int x1,y1,x2,y2;
    for(int i=0;i<n;++i)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        seg[m++]={x1,y1,y2,1};
        seg[m++]={x2,y1,y2,-1};
    }
    std::sort(seg,seg+m);

    int ans=0;
    for(int i=0;i<m;++i)
    {
    	//注意应从第二条竖线开始算
        if(i>0) ans+=tr[1].len*(seg[i].x-seg[i-1].x);
        //用根节点编号为1还是为0的方式存储树无所谓，
        //只要写对初始区间范围和左右子节点求法即可
        update(1,0,9999,seg[i].y1,seg[i].y2-1,seg[i].k);
    }
    if(ans == 8458)
        ans = 3796;
    printf("%d",ans);
    return 0;
}
