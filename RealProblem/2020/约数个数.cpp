#include <iostream>
using namespace std;
int main()
{
    // 1200000 有多少个约数（只计算正约数）。
    int count=0;
    for (int i = 1; i <= 1200000; i++)
    {
        if(1200000%i==0)
            count++;
    }
    cout<< count <<endl;
    return 0;
}