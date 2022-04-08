#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n, k;

void work()
{
    cin>> n >> k;
    vector<vector<int>> group(k, vector<int>(3));
    for(int i=0; i<n; ++i)
    {
        int x;
        cin>> x;
        int re=x%k;
        if(x>group[re][0])
        {
            group[re][2]=group[re][1];
            group[re][1]=group[re][0];
            group[re][0]=x;
        }
        else if(x>group[re][1])
        {
            group[re][2]=group[re][1];
            group[re][1]=x;
        }
        else if(x>group[re][2])
        {
            group[re][2]=x;
        }
    }
    // O(k^2)
    long long max=0,v1,v2,v3;
    for (int i = 0; i < k; ++i)
    {
        for (int j = i; j < k; ++j)
        {
            int kk=(k-i+k-j)%k;
            v1=group[i][0];
            if(i==j)
            {
                v2=group[i][1];
                if(i==kk)
                {
                    v3=group[i][2];
                }
                else
                {
                    v3=group[kk][0];
                }
            }
            else
            {
                v2=group[j][0];
                if(i==kk)
                {
                    v3=group[i][1];
                }
                else if(j==kk)
                {
                    v3=group[j][1];
                }
                else
                {
                    v3=group[kk][0];
                }
            }
            if(v1+v2+v3>max)
                max=v1+v2+v3;
        }
    }
    cout<< max <<endl;
}

int main(int argc, char *argv[])
{
    work();
    return 0;
}