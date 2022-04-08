#include <iostream>
#include<numeric>
#include <algorithm>
#include <cmath>
#include <vector>
typedef long long ll;
using namespace std;
const int N=2e5+10;
int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>> n >> m;
    vector<int> a(n+m+1);
    for (int i = 0; i < n+m+1; i++)
        cin>> a[i];
    if(!m) cout<< accumulate(a.begin(), a.end(), 0ll) <<endl;
    else
    {
        sort(a.begin(), a.end());
        ll ans = -a.front() + a.back();
        for (int i = 1; i < n+m; i++)
        {
            ans+=abs(a[i]);
        }
        cout<< ans <<endl;
    }
    return 0;
}