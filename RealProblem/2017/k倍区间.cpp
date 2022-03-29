#include <iostream>
#include <map>
using namespace std;
const int ALEN=1e5+10;
int a[ALEN];
int s[ALEN]; // 前缀和
map<int,int> cnt; // 同余的个数统计

int main(int argc, char* argv[])
{
    s[0]=0;
    cnt[0]=1;
    int n,k;
    cin>> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin>> a[i];
        s[i]=(s[i-1]+a[i])%k;
        cnt[s[i]]++;
    }
    long long ans=0;
    for (int i = 0; i < k; ++i)
    {
        ans+=(long long)cnt[i]*(cnt[i]-1)/2;
    }
    cout<< ans <<endl;
    return 0;
}




