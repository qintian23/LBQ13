#include <stdio.h>

int main(int argc, char* argv[])
{
    for (int i = 2; i <= argc; i+=2)
    {
        printf("%s:%s\n",argv[i-1]+2,argv[i]);
        // if(i%2==0)printf("\n");
    }
    return 0;
}