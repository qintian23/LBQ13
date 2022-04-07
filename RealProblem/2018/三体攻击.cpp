#include <iostream>
#include <stdio.h>
using namespace std;
int A, B, C, m, a, b, c;

int getInt()
{
    char ch =getchar();
    int x=0, f=1;
    while (ch < '0' || ch > '9')
    {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while ('0' <= ch && ch <= '9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

inline int getIndex(int x, int y, int z)
{
    return ((x-1)*b+(y-1))*c+z;
}

int main(int argc, char *argv[])
{
    A=getInt();
    B=getInt();
    C=getInt();
    m=getInt();
    a=A+1, b=B+1, c=C+1;
    
    int *data=new int[a*b*c];
    int (*atk)[7] =new int[m+1][7];

    for (int i = 1; i <= A; ++i)
    {
        for (int j = 1; j <= B; ++j)
        {
            for (int k = 1; k <= C; ++k)
            {
                data[getIndex(i,j,k)]=getInt();
            }
        }
    }
    
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            atk[i][j]=getInt();
        }
        // 执行攻击
        for (int x = atk[i][0]; x <= atk[i][1]; ++x)
        {
            for (int y = atk[i][2]; y <= atk[i][3]; ++y)
            {
                for (int z = atk[i][4]; z <= atk[i][5]; ++z)
                {
                    data[getIndex(x,y,z)] -= atk[i][6];
                    if(data[getIndex(x,y,z)]<0)
                    {
                        cout<< i << endl;
                        delete [] data;
                        delete [] atk;
                        return 0;
                    }
                }
            }
        }
    }
    delete [] data;
    delete [] atk;
    return 0;
}