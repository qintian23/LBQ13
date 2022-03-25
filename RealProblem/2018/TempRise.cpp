#include<iostream>
#include<queue>

using namespace std;
int n;
const int N=1e3+10;
char g[N][N];
bool st[N][N];//状态 判断是否走过

typedef pair<int,int>PII;//需要长款两个变量定位
#define x first
#define y second

int dx[]={-1,0,1,0},dy[]={0,1,0,-1};//移动的偏移量

void bfs(int x,int y,int &sum,int &bound)//土地量与淹没量，后续需要使用 所以&
{
    st[x][y]=true;
    queue<PII>q;
    q.push({x,y});
    
    while(q.size())//BFS必然遍历完整个岛屿
        {
            auto t=q.front();
            q.pop();
            bool is_bound=false;
            sum++;
            for(int i=0;i<4;i++)
                {
                    int tmpx=t.x+dx[i],tmpy=t.y+dy[i];
                    if(tmpx<0||tmpx>=n||tmpy<0||tmpy>=n)continue;//边界
                    else if(st[tmpx][tmpy])continue;//走过
                    else if(g[tmpx][tmpy]=='.')//说明上一个地点临海
                        {
                            is_bound=true;
                            continue;
                        }
                    st[tmpx][tmpy]=true;
                    q.push({tmpx,tmpy});
                }
            if(is_bound)bound++;//四个方向有一个临海 则该地区沉没
        }
    return ;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>g[i];//读入地图
    
    int cnt=0;//未被完全淹没的岛屿数量
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(g[i][j]=='#'&&!st[i][j])//当遍历到土地 且 未走过时 遍历能走到的整个岛屿
                {
                    int sum=0,bound=0;
                    bfs(i,j,sum,bound);
                    if(sum==bound)cnt++;//沉没量与土地量相等，证明该岛屿全部沉没
                }
    cout<<cnt;
    return 0;
}
