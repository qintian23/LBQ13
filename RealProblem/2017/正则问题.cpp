#include <stdio.h>
#include <cstring>

#define MAX 101
// ((xx|xxx)x|(x|xx))xx 6
// char s[]="((xx|xxx)x|(x|xx))xx";
char s[MAX];
int pos=0;
int len;

int max(int x, int y)
{ 
    return x>y?x:y;
}

int f()
{
    int m=0;
    int tmp=0;
    while (pos<len)
    {
        if(s[pos]=='(')
        {
            pos++;
            tmp+=f();
        } 
        else if(s[pos]=='x')
        {
            pos++;
            tmp++;
        }
        else if(s[pos]=='|')
        {
            pos++;
            m=max(m,tmp);
            tmp=0;
        }
        else if(s[pos]==')')
        {
            pos++;
            m=max(m,tmp);
            break;
        }
    }
    m=max(m,tmp);
    return m;
}

int main(int argc, char* argv[])
{
    scanf("%s",&s);
    len=strlen(s);
    printf("%d\n",f());
    return 0;
}
