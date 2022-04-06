#include <iostream>
#include <string.h>
using namespace std;
const int N=1e2+10;
int d[N][N], dp[N][N];
int main(int argc, char *argv[])
{
    memset(dp, -0x3f, sizeof(dp));
    int n;
    cin>> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin>> d[i][j];
    dp[1][1]=d[1][1];
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j]=max(dp[i-1][j-1], dp[i-1][j])+d[i][j];
        }
    }
    if((n-1)&1) // 偶数    
        cout<< max(dp[n][1+(n-1)/2], dp[n][1+(n-1)/2+1]) << endl;
    else
        cout<< dp[n][1+(n-1)/2] << endl;
    return 0;
}