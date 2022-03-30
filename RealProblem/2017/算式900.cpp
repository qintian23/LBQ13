#include <iostream>
using namespace std;

bool rdata(int a, int b, int c)
{
    int d[]={0,0,0,0,0, 0,0,0,0,0};
    while (a)
    {
        d[a%10]++;
        a=a/10;
    }
    while (b)
    {
        d[b%10]++;
        b=b/10;
    }
    while (c)
    {
        d[c%10]++;
        c=c/10;
    }
    for(int i=0; i<10; i++)
    {
        if(d[i]!=1)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    for(int i=10; i<100; i++)
    {
        if(900%i==0)
        {
            int b=900/i;
            for (int j = 1000; j < 9999; j++)
            {
                if(j-b>=1000 && j-b<=9999)
                {
                    // cout<< j <<", " << j-b << ", " << i <<endl;
                    if(rdata(j, j-b, i))
                    {
                        cout<< j <<", " << j-b << ", " << i <<endl;
                    }
                }
            }
            
        }
        else
            continue;
    }

    return 0;
}