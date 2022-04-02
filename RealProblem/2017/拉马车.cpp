#include <iostream>
#include <string.h>
using namespace std;
string A,B,C;

bool op(string &x, string &y)
{
    if(x.length()==0) return false;
    bool ans=true;
    char front=x[0];
    long i=y.find(front);
    if(i!=string::npos) // 桌上有相同的牌
    {
        x.insert(x.end(),front);
        for (int j = 0; j <= i; ++j)
        {
            x.insert(x.end(),y[j]);
        }
        y.erase(0,i+1); // 从桌面上移除
    }
    else
    {
        y.insert(y.begin(),front);
        ans=false;
    }
    x.erase(x.begin());
    return ans;
}
int main(int argc, char* argv[])
{
    cin>> A >> B;
    bool flagA=true;
    bool flagB=false;
    int count=0;
    while (++count<1e5)
    {
        if(flagA)
        {
            flagA=op(A,C);
            if(A.length()==0)
            {
                cout<< B <<endl;
                break;
            }
            flagB=!flagA;
        }
        if(flagB)
        {
            flagB=op(B,C);
            if(B.length()==0)
            {
                cout<< A <<endl;
                break;
            }
            flagA=!flagB;
        }
    }
    if(count>=1e5)
        cout<< -1 <<endl;
    return 0;
}