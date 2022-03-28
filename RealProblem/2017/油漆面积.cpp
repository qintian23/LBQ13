#include <iostream>
#include <algorithm>
using namespace std;
struct Line
{
    int x1,x2,h,f;//左右坐标，纵坐标高度，f=1为入边，f=-1为出边
    Line(){}
    Line(int _l,int _r,int _h,int _f):x1(_l),x2(_r),h(_h),f(_f){}
    bool operator<(const Line &l)const
    {
        return h<l.h;
    }
};
//线段树的定义
struct SegTree
{
    int pl,pr,cnt,len; //左端点编号，右端点编号，入边的数目，两个端点之前被覆盖的长度
    SegTree():cnt(0),len(0){}
    SegTree *lson,*rson;
};
const int N = 10000;
int n;
int ans=0;
int X[N<<1]; //记录所有的横坐标
Line lines[N];
SegTree *buildTree(int pl,int pr) //构建区间树
{
    SegTree *t = new SegTree();
    t->pl = pl;
    t->pr = pr;
    if(pl==pr) return t;
    int mid = ((pl+pr)>>1);
    t->lson = buildTree(pl,mid);
    t->rson = buildTree(mid+1,pr);
    return t;
}
void updateLength(SegTree *pTree,int tl, int tr)
{
    if(pTree->cnt) pTree->len = X[tr]-X[tl-1]; //将区间树上的端点反入到X中求得二维坐标上的实际横坐标
    else if(tl==tr) pTree->len = 0;
    else pTree->len = pTree->lson->len+pTree->rson->len; //负数的情况
}
void update(SegTree *tree,int pl,int pr,int value)
{
    int tl = tree->pl;
    int tr = tree->pr;
    if(pl<=tl&&pr>=tr)
    {
        tree->cnt+=value;
        updateLength(tree,tl,tr);
        return;
    }
    int m = (tl+tr)>>1;
    if(pl<=m) update(tree->lson,pl,pr,value);
    if(pr>m) update(tree->rson,pl,pr,value);
    updateLength(tree,tl,tr);
}
int main()
{
    scanf("%d",&n);
    int x1,y1,x2,y2;
    int index = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        X[index] = x1;
        lines[index] = Line(x1,x2,y1,1);
        index++;
        X[index] = x2;
        lines[index] = Line(x1,x2,y2,-1);//高度2
        index++;
    }
    sort(X,X+index); //所有横坐标点排序
    sort(lines,lines+index); //所有扫描线排序
    //离散化横坐标
    int X_end = unique(X,X+index)-X; //去重返回的迭代器，指向去重后容器中不重复序列的最后一个元素下一个元素
    SegTree *root = buildTree(1,X_end); //初始化线段树
    //从低到高遍历扫描线
    for(int i=0;i<index;i++)
    {
        int pl = lower_bound(X,X+X_end,lines[i].x1)-X; //二分查找记录下标
        int pr = lower_bound(X,X+X_end,lines[i].x2)-X; //二分查找记录下标
        update(root,pl+1,pr,lines[i].f);
        ans+=root->len*(lines[i+1].h-lines[i].h);
    }
    printf("%d",ans);
    return 0;
}

