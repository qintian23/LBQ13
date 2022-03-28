#include <stdio.h>

void ShellInsert(int* arr, int n, int dk)
{
    int i,j,k,temp;
    for(i=k+dk; i<n; i=i+dk)
    {
        if(arr[i]<arr[i-dk])
        {
            temp=arr[i];
            for(j=i-dk; j>=0 && temp<arr[j]; j=i-dk)
                arr[j+dk]=arr[j];
            arr[j+dk]=temp;
        }
    }
}

void ShellSort(int* arr, int n)
{
    int dlta[3]={5,3,1}; // 按照增量序列deta[0,...,t-1]对数组进行希尔排序
    for(int k=0; k<3; k++)
        ShellInsert(arr,n,dlta[k]);
}

int main(void)
{
    int a[]={1,2,3,6,5,4,7,9,8,10};
    int n=sizeof(a)/sizeof(int);
    ShellSort(a,n);
    for(int i=0; i<n; i++)
    {
        printf("%d,",a[i]);
    }

    return 0;
}