#include <iostream>
using namespace std;
int a[3][3];
int b[8];
int flag;
bool p(int r[])
{
    for(int i=0; i<6; i++)
    {
        if(r[i]!=r[i+1])
            return true;
    }
    return false;
}

void fb(int r[])
{
    if(a[0][0]==0){ b[0]++; b[3]++; b[6]++;}
    if(a[0][1]==0){ b[0]++; b[4]++;}
    if(a[0][2]==0){ b[0]++; b[5]++; b[7]++;}
    if(a[1][0]==0){ b[1]++; b[3]++;}
    if(a[1][1]==0){ b[1]++; b[4]++; b[6]++;b[7]++;}
    if(a[1][2]==0){ b[1]++; b[5]++;}
    if(a[2][0]==0){ b[2]++; b[3]++; b[7]++;}
    if(a[2][1]==0){ b[2]++; b[4]++;}
    if(a[2][2]==0){ b[2]++; b[5]++; b[6]++;}

    for (int i = 0; i < 8; i++)
    {
        if(b[i]==0) flag=r[i];
    }
}

int main(int argc, char* argv[])
{
    for (int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin>> a[i][j];
    
    int r[]={
        // 横
        a[0][0]+a[0][1]+a[0][2], // 0
        a[1][0]+a[1][1]+a[1][2], // 1 
        a[2][0]+a[2][1]+a[2][2], // 2
        // 竖
        a[0][0]+a[1][0]+a[2][0], // 3
        a[0][1]+a[1][1]+a[2][1], // 4
        a[0][2]+a[1][2]+a[2][2], // 5
        // 交叉
        a[0][0]+a[1][1]+a[2][2], // 6
        a[0][2]+a[1][1]+a[2][0], // 7
    };

    

    return 0;
}