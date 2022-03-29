#include <iostream>
#include <string.h>
using namespace std;

const int ALEN=1e5+1;

int a[ALEN];
int sum[ALEN];

int main(int argc, char* argv[])
{
    memset(sum, 0, sizeof(sum)); // 初始化计算器
    int n,k;
    int count=0;
    cin>> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin>> a[i];
        if(a[i]%k==0) // 子序列长度为1的计数
        {
            sum[0]++;
            // cout<< a[i] <<endl;
        }
    }
    
    for(int d=2; d<=n; d++)
    {
        // 子序和
        for(int i=0; i<n-d; i++)
        {
            int temp=0;
            for(int j=i; j<=i+d; j++)
            {
                temp+=a[j];
            }
            if(temp!=0 && temp%k==0)
            {
                // cout<< temp <<endl;
                sum[d-1]++;
            }
        }
    }
    
    for(int i=0; i<n; i++)
    {
        count+=sum[i];
    }

    cout<< count <<endl;
    return 0;
}