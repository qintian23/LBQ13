#include <iostream>
using namespace std;

bool r(int x)
{
    while (x)
    {
        int y=x%10;
        if(y==2 || y==4)
            return false;
        else
            x/=10;
    }
    return true;
}

int main(int argc, char *argv[])
{
    int count=0;
    for (int i = 1; i < 2019; i++)
    {
        for (int j = i+1; j < 2019; j++)
        {
            int k=2019-i-j;
            if(r(i) && r(j) && r(k) && i < j && j < k)
            {
                cout<< i << ',' << j << ',' << k  <<endl;
                count++;
            }
        }
    }
    cout<< count <<endl;
    return 0;
}