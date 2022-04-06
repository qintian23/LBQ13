#include <iostream>

using namespace std;
// 快速幂运算
long pow_2(int b)
{
    long x=2;
    long res=1;
    while (b>0)
    {
        if(b&1)
            res*=x;
        b>>=1; 
        x=x*x;
    }
    return res;
}
// 最大公约数
int gcd(long a, long b)
{
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(int argc, char *argv[])
{
    cout<< gcd(pow_2(20)-1, pow_2(19)) <<endl;
    cout<< pow_2(20)-1 << '/' << pow_2(19) << endl;
    return 0;
}
