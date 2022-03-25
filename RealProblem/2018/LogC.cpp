#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1e5+10;
vector<int> a[maxn];
int k,d;
int f(int x)
{
	int s=a[x].size();
	if(s<k)
	  return 0;
	sort(a[x].begin(),a[x].end());
	for(int i=0;i+k-1<s;i++)
	{
		if(a[x][i+k-1]-a[x][i]<d)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int t,x,n;
	int i;
	cin>>n>>d>>k;
	for(i=0;i<n;i++)
	{
		cin>>t>>x;
		a[x].push_back(t);
	}
	for(i=0;i<maxn;i++)//测试每个id 
	{
		if(f(i))
		  cout<<i<<endl;
	}
	return  0;
}