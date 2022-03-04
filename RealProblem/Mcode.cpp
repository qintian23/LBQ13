#include <iostream>
using namespace std;

void bi(int a, int b[])
{
    int i=7;
    a=a>0?a:a+256;
    while (a)
    {
        b[i--]=a%2;
        a/=2;
    }
}

int main()
{
    int data[10][32];
    int i,j;
    for(i=0; i<10; i++)
    {
        for(j=0; j<32; j++)
        {
            cin>> data[i][j];
        }
    }

    for(i=0; i<10; i++)
    {
        for(j=0; j<32; j++)
        {
            // cout<< data[i][j] << ", ";
            int b[]={0,0,0,0,0,0,0,0};
            bi(data[i][j],b);
            for(int ii=0; ii<8; ii++)
            {
                if(b[ii]==1)
                    cout<< '*' << ' ' ;
                else
                    cout<< ' ' << ' ' ;
            }
            if((j+1)%2==0) cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}