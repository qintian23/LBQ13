#include <iostream>
#include <stdio.h>
using namespace std;
int all[][9]=
{
    {4,9,2,3,5,7,8,1,6},
    {8,1,6,3,5,7,4,9,2}, // 上下
    {2,9,4,3,5,7,8,1,6}, // 左右
    {8,3,4,3,5,7,4,9,2}, // 右旋
    {4,3,8,3,5,7,4,9,2}, // 右旋：左右
    {6,7,2,3,5,7,8,1,6}, // 右旋：上下 
    {6,1,8,3,5,7,4,9,2}, // 再右旋
    {2,7,6,9,5,7,8,1,6}  // 再右旋右旋
};
int test(int data[9])
{
    int cnt=0,ans=-1;
    for (int i = 0; i < 8; ++i)
    {
        bool ok=true;
        for (int j = 0; j < 9; j++)
        {
            if(data[j]==0) continue;
            if(data[j]!=all[i][j])
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {
            cnt++;
            ans=i;
        }
    }
    if(cnt==1)
        return ans;
    else
        return -1;
}

int main(int argc, char* argv[])
{
    int data[9];
    for (int i = 0; i < 9; i++)
        scanf("%d",&data[i]);
    
    int index=test(data);
    if(index==-1)
    {
        cout<< "Too Many\n" <<endl;
    }
    else
    {
        printf("%d %d %d\n",all[index][0],all[index][1],all[index][2]);
        printf("%d %d %d\n",all[index][3],all[index][4],all[index][5]);
        printf("%d %d %d\n",all[index][6],all[index][7],all[index][8]);
    }
    return 0;
}