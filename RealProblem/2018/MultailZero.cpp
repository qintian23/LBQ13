#include <iostream>
using namespace std;
#include <cmath>    
int main()
{
    int t_cnt,f_cnt,data=0;//二和五的个数统计
    t_cnt=f_cnt=0;
    
    for(int i = 0;i<100;i++)
    {
        cin>>data;
        while(data%5==0)
        {
            f_cnt++;
            data/=5;
        } 
        while(data%2==0)
        {
            t_cnt++;
            data/=2;
        } 
    } 
    cout<<min(t_cnt,f_cnt)<<endl;//使用cmath库函数，也可以如此求解int count = t_cnt>f_cnt?f_cnt:t_cnt;
     
    return 0;
}