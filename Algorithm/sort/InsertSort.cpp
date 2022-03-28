#include <stdio.h>

void InsertSort(int* a, int n)
{
    int i,j;
    int temp;
    for(i=1; i<n; i++)
    {
        if(a[i]<a[i-1])
        {
            temp=a[i];
            for(j=i-1; j>=0 && temp<a[j]; --j)
                a[j+1]=a[j];
            a[j+1]=temp;
        }
    }
}

int main(void)
{
    int a[]={1,2,3,6,5,4,7};
    int n=sizeof(a)/sizeof(int);
    InsertSort(a,n);
    for(int i=0; i<n; i++)
    {
        printf("%d,",a[i]);
    }

    return 0;
}