#include <stdio.h>
#include <string.h>

char *courses[]={"C", "C++", "PHP", "ASP", "ASP.NET", "C#", "JAVA", "BASIC", "PASCAL", "COBOL"};

int max(char *a, char *b)
{
    int alen=strlen(a);
    int blen=strlen(b);
    for(int i=0; i<alen && i<blen; i++)
    {
        if(a[i]>b[i]) 
        {
            return 1;
        }               
    }
    return 0;
}

void sort(char *p[], int n)
{
    char *tmp;
    int i, j, k;
    for (i = 0; i < n; ++i)
    {
        k=i;
        for(j = i; j < n; ++j)
        {
            if(max(p[i],p[j]))
            {
               k=j;
            }
        } 
        if(k!=j)
        {
            tmp=p[k];
            p[k]=p[i];
            p[i]=tmp;
        }
        // for (int t = 0; t < n; ++t)
        // {
        //     printf("%s, ",courses[t]);
        // }
    }   
}

int main()
{
    // int n=strlen(courses);
    // printf("%d\n",n);
    int n=10;
    sort(courses, n);
    printf("\n");
    int i;
    for (i = 0; i < n; ++i)
    {
        printf("%s, ",courses[i]);
    }
    return 0;
}