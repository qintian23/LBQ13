#include <iostream>
#include <string.h>
using namespace std;

int vis[10][10];
int jump[10][10];

string room[10]=
{
    "UDDLUULRUL","UURLLLRRRU","RRUURLDLRD","RUDDDDUUUU","URUDLLRRUU",
    "DURLRLDLRL","ULLURLLRDU","RDLULLRDDD","UUDDUDUDLL","ULRDLUURRR"
};

bool pass(char c, int &i, int &j)
{
    switch (c)
    {
        case 'U': i=i-1; break;
        case 'D': i=i+1; break;
        case 'L': j=j-1; break;
        case 'R': j=j+1; break;
    }
    if(i<0 || j<0 || i>9 || j>9) // 走出迷宫
        return true;
    else
        return false;
}

bool dfs(char c, int i, int j)
{
    while (true)
    {
        vis[i][j]=1;
        if(pass(c,i,j) || jump[i][j]==1) 
            return true;
        else if(vis[i][j]==1 || jump[i][j]==-1) 
            return false;
        else 
            c=room[i][j];
    }
    // vis[i][j]=1;
    // if(pass(c,i,j) || jump[i][j]==1) 
    //     return true;
    // else if(vis[i][j]==1) 
    //     return false;
    // else ;
    // dfs(room[i][j],i,j);
}

int main()
{   
    int count = 0;
    memset(jump,0,sizeof(jump));
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            memset(vis,0,sizeof(vis));
            if(dfs(room[i][j],i,j))
            {
                jump[i][j]=1;
                count++;
            }
            else
                jump[i][j]=-1;
        }
    }
    cout<< count <<endl;
    return 0;
}