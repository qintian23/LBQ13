#include<stdio.h>
int main(){
    int i;
    for(i=0;i<100;i++)
        if((i*i*i+i*5)/6>=1000)break;
    printf("%d\n",i);
    return 0;
} 