#include <iostream>
using namespace std;
char col[100];

void otc(long n)
{
    for (long i = 1; i <= n; ++i)
    {
        col[0]++;
        int tmp=0;
        if(col[0]==27)
        {
            tmp=1; // 表示进位
            col[0]=1; // 回到1

            int t=1;
            while (tmp>0 && t<100)
            {
                col[t]+=tmp;
                if(col[t]==27)
                {
                    col[t]=1;
                    tmp=1;
                }
                else
                {
                    tmp=0;
                }
                t++;
            }
            
        }
    }
    string s;
    for(int k=0; k<100; ++k)
    {
        if(col[k]==0) break;
        s.insert(s.begin(),'A'+(col[k]-1));
    }
    cout<< s << endl;
}

int main(int argc, char* argv[])
{
    long n;
    cin>> n;
    // otc(n);
    int cnt=0;
    while (n)
    {
        if(n%26==0)
        {
            col[cnt++]=26;
            n=n/26-1;
        }
        else
        {
            col[cnt++]=n%26;
            n/=26;
        }
    }
    for (int i = cnt-1; i >=0; --i)
    {
        cout<< (char)('A'+col[i]-1);
    }
    return 0;
}