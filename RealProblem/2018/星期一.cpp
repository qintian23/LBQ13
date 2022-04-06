#include <iostream>
using namespace std;
// 判断闰年
bool isLeap(int x)
{
    return x%400==0 || (x%4==0 && x%100!=0);
}
int main(int argc, char *argv[])
{
    int t=0;
    for (int i = 1901; i <= 2000; i++)
        t = t + (isLeap(i) ? 366 : 365);

    // int res=(t+(7-1))/7; // 进1法
    // int res=(t+(7/2))/7; // 四舍五入
    int res=t/7; // 去尾法
    cout<< res <<endl;
    return 0;
}