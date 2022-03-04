#include <stdio.h>

void swap(int &x, int &y)
{
    x^=y;
    y^=x;
    x^=y;
}

int Partition_1(int arr[], int low, int high)
{
    int Pivotloc=arr[low];
    while (low<high)
    {
        while (low<high && arr[high]>=Pivotloc)
            --high;
        swap(arr[low],arr[high]);
        while (low<high && arr[low]<=Pivotloc)
            ++low;
        swap(arr[high],arr[low]);
    }
    return low;
    
}

void QSort(int* arr, int n, int low, int high)
{
    int Pivotloc;
    if(low<high)
    {
        Pivotloc=Partition_1(arr,low,high);
        QSort(arr,n,low,Pivotloc-1);
        QSort(arr,n,Pivotloc+1,high);
    }
}

void QuickSort(int* arr, int n)
{
    QSort(arr,n,0,n-1);
}

int main(void)
{
    int a[]={2,1,3,5,4,6,8,7,10,9};
    int n=sizeof(a)/sizeof(int);
    QuickSort(a,n);
    for(int i=0; i<n; i++)
    {
        printf("%d,",a[i]);
    }
    return 0;
}