#include <stdio.h>

void swap(int &x, int &y)
{
    x^=y;
    y^=x;
    x^=y;
}

void BubbleSort(int* a, int n)
{
    int i,j,temp;
    int change=0;
    for(i=n-1; i>=0 && change==0; i--)
    {
        change=1;
        for(j=0; j<i; j++)
        {
            if(a[j]>a[j+1])
            {
                change=0;
                // temp=a[j];
                // a[j]=a[j+1];
                // a[j+1]=temp;
                swap(a[j],a[j+1]);
            }
        }
    }
}

int main(void)
{
    int a[]={2,1,3,5,4,6,8,7,10,9};
    int n=sizeof(a)/sizeof(int);
    BubbleSort(a,n);
    for(int i=0; i<n; i++)
    {
        printf("%d,",a[i]);
    }
    return 0;
}