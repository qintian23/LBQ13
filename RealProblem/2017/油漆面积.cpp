#include <stdio.h>
#include <algorithm>

using namespace std;

/**
 * @brief 扫描线的定义
 * 
 */
struct Line
{
    int x1, x2, h, f;
    Line(){}
    Line(int _l, int _r, int _h, int _f) : x1(_l), x2(_r), h(_h), f(_f) {}

    // 按高度排序
    bool operator<(const Line &l) const
    {
        return h<l.h;
    }
};
/**
 * @brief 线段树的定义
 * 
 */
struct SegTree
{
    int pl, pr, cnt, len; // 左端点编号， 右端点编号，入边的数目，两个端点之间被覆盖的长度
    SegTree() : cnt(0), len(0) {}

    SegTree *lson, *rson;
};

const int N=10000;
int n;
int X[N<<1]; // 记录所有的横坐标
// int PL=0,PR;
Line lines[N];

/**
 * @brief 构建区间树
 * 
 * @param pl 
 * @param pr 
 * @return SegTree* 
 */
SegTree *buildTree(int pl, int pr)
{
    SegTree *t=new SegTree();
    t->pl=pl;
    t->pr=pr;
    if(pl==pr)return t;
    int mid=((pl+pr)>>1);
    t->lson=buildTree(pl,mid);
    t->rson=buildTree(mid+1,pr);
    return t;
}

/**
 * @brief 
 * 
 * @param pTree 
 * @param tl 
 * @param tr 
 */
void updateLength(SegTree *pTree, int tl, int tr)
{
    if(pTree->cnt)
    {
        pTree->len=X[tr]-X[tl-1]; // 如果区间整体被覆盖，直接得出覆盖宽度
    }
    else if (tl==tr)
    {
        pTree->len=0;
    }
    else
    {
        pTree->len=pTree->lson->len+pTree->rson->len;
    }
}

void update(SegTree *tree, int pl, int pr, int value)
{
    int tl=tree->pl;
    int tr=tree->pr;
    if(pl<=tl && pr>=tr)
    {
        tree->cnt+=value;
        updateLength(tree,tl,tr);
        return ;
    }
    int m=(tl+tr)>>1;
    if(pl<=m) update(tree->lson, pl, pr, value);
    if(pr>=m) update(tree->lson, pl, pr, value);
    updateLength(tree,tl,tr);
}

int ans;

int main(int argc, char* argv[])
{
    scanf("%d",&n);
    
    int x1, x2, y1, y2;
    int index=0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
        X[index]=x1;
        lines[index]=Line(x1,x2,y1,1); // 高度1
        index++;

        X[index]=x2;
        lines[index]=Line(x1,x2,y2,-1); // 高度2
        index++;
    }
    
    // 大体上有2n个横坐标，2n条水平线段
    sort(X,X+index);
    sort(lines,lines+index);
    // 离散化横坐标
    int X_end=unique(X,X+index)-X;

    SegTree *root=buildTree(1,X_end);
    for (int i = 0; i < index; ++i)
    {
        int pl=lower_bound(X,X+X_end,lines[i].x1)-X;
        int pr=lower_bound(X,X+X_end,lines[i].x2)-X;
        update(root, pl+1, pr, lines[i].f);
        ans+=root->len*(lines[i+1].h-lines[i].h);
    }
    printf("%d\n",ans);
    return 0;
}