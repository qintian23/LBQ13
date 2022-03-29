#include <iostream>
#include <string.h>
using namespace std;

const int ALEN=1e5+2;

int a[ALEN];
int sum[ALEN];

int main(int argc, char* argv[])
{
    memset(sum, 0, sizeof(sum));
    int n,k;
    int count=0;
    cin>> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin>> a[i];
        sum[i]=sum[i-1]+a[i];
        // cout<< sum[i] <<endl;
        if(sum[i]%k==0) count++;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n-i; j++)
        {
            if((sum[j+i]-sum[j])%k==0)
            {
              // cout<< (sum[j+i]-sum[j]) <<endl;
                count++;
            }
        }
    }

    cout<< count <<endl;
    return 0;
}




