#include <iostream>
using namespace std;
bool BAns[10000];//最大包子数组
int An[101],n,allG;//allG最大公约数 

int gcd(int a,int b)//求a,b最大公约数 
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    BAns[0]=true;
    //求解包子数 
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        cin>>An[i];
        if(i==0)allG = An[i];
        else allG=gcd(An[i],allG);//求解当前最大公约数 
        
        //求得包子数 
        for(int j =0;j<10000;j++) 
        {
            if(BAns[j])BAns[j+An[i]]=true;//循环能凑得包子数为Ai的倍数到An的倍数和。 
        }    
    } 
    
    if(allG!=1){cout<<"INF"<<endl;return 0;}
    int count=0;
    //输出不能凑得包子数
     for(int i = 0;i<10000;i++)
     {
         if(!BAns[i])++count;
     } 
     cout<<count<<endl;
    return 0;
}