#include <iostream>
using namespace std;

bool r(int x)
{
    while (x)
    {
        int y=x%10;
        if(y==2 || y==0 || y==1 || y==9)
            return true;
        x/=10;
    }
    return false;
}

int main(int argc, char *argv[])
{
    int ans=0;
    int n;
    cin>> n;
    for (int i = 1; i <= n; i++)
    {
        if(r(i))
            ans+=i;
    }
    cout<< ans <<endl;
    return 0;
}