#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

const int N_SIZE=2e3+5;

int n,m,K,T; // 物种数为n，种子类型数为m，杂交方案数为k，目标种子编号为t
int t[N_SIZE]; // n种物种的种植时间
bool seeds[N_SIZE], vis[N_SIZE]; // 已拥有的m种种子
int dp[N_SIZE];
vector<int> vec[N_SIZE * N_SIZE];
vector<pair<int, int>> G[N_SIZE];
queue<int> que;

void bfs()
{
    int up=0;
    for (int i = 0; i <= up; i++)
    {
        for(auto j:vec[i])
        {
            if(vis[j]) continue;
            vis[j]=true;
            que.push(j);
            while (!que.empty())
            {
                int u=que.front();
                que.pop();
                for(auto k:G[u])
                {
                    int y=k.first, z=k.second;
                    if(!seeds[y]) continue;
                    int now=max(dp[u], dp[y]) + max(t[u], t[y]);
                    if(now < dp[z]) 
                        dp[z]=now, vec[dp[z]].push_back(z);
                    seeds[z]=true;
                    up=max(up, now);
                } 
            }
            
        }
    }
    
}

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    memset(dp, 0x3f, sizeof(dp));
    cin>> n >> m >> K >> T;
    for (int i = 1; i <= n; i++)
        cin>> t[i];
    
    int x, y, z;
    for (int i = 1; i <= m; i++)
    {
        cin>> x;
        seeds[x]=true;
        dp[x]=0;
        vec[0].push_back(x);
    }
    for (int i = 1; i <= K; i++)
    {
        cin>> x >> y >> z;
        G[x].push_back(make_pair(y,z));
        G[y].push_back(make_pair(x,z));
    }
    bfs();
    cout<< dp[T] << endl;
    return 0;
}

/* 测试
6 2 4 6
5 3 4 6 4 9
1 2
1 2 3
1 3 4
2 3 5
4 5 6
*/

// 输出：16