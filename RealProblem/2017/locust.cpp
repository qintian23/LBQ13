#include <iostream>
using namespace std;

// void pp(int &i, int &j)
// {
//     ++i; ++j;
// }

// void dfs(int i, int j)
// {
//     pp(i,j);
//     cout<< i << ',' << j <<endl;
// }

int main()
{
    int l=0,r=0;
    int m=9;
    int count=0;
    for(int i=1; i<=8; i++)
    {
        l=8-i;
        r=(i+8)%8;
        if(l<r) 
            count=count+l;
        else
            count=count+r;
    }
    cout<< count <<endl;
    // int i=0, j=0;
    // cout<< i << ',' << j <<endl;
    // dfs(i,j);
    // cout<< i << ',' << j <<endl;
    return 0;
}