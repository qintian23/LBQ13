#include <iostream>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
    if(b==0) return a;
    else return gcd(b, a%b);
}

int main(int argc, char *argv[])
{
    ll x=0;
    ll y=1<<19;
    ll k=y;
    for (int i = 0; i < 20; i++)
    {
        x+=k;
        k/=2;
    }
    k=gcd(x,y);
    cout<< x/k << '/' << y/k <<endl;
    return 0;
}