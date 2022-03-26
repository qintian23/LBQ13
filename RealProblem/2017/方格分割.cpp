#include <stdio.h>

int ans;
int dire[][2]={{-1,0}, // 左
               {1,0}, // 右
               {0,-1}, // 下
               {0,1} // 上
            };
int vis[7][7];

void dfs(int x, int y)
{
    if(x==0 || y==0 || x==6 || y==6)
    {
        ans++;
        return;
    }
    vis[x][y]=1;
    vis[6-x][6-y]=1;
    for (int i = 0; i < 4; ++i)
    {
        int nx=x+dire[i][0];
        int ny=y+dire[i][1];
        // 新坐标
        if(nx<0 || nx>6 || ny<0 || ny>6) continue;
        if(!vis[nx][ny])
            dfs(nx,ny);
    }
    vis[x][y]=0;
    vis[6-x][6-y]=0; // 对称
    
}

int main(int argc, char* argv[])
{
    dfs(3,3);
    printf("%d\n",ans/4);
    return 0;
}