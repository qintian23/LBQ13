#include <iostream>
using namespace std;

int main()
{
    int n, count=0;
    int data[3][100000];

    cin>> n;
    for(int i=0; i<3; i++)
        for(int j=0; j<n; j++)
            cin>> data[i][j];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                if(data[0][i] >= data[1][j]) break;
                if(data[0][i] < data[1][j] && data[1][j] < data[2][k])
                    count++;
            }
        }
    }

    cout<< count <<endl;

    return 0;
}