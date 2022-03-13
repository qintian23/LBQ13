# include <stdio.h>

template<typename T> int compare(const T &v1, const T &v2)
{
    return v1<v2?-1:1;
} 

template<typename T1, typename T2> int compare(const T1 &v1, const T2 &v2)
{
    return v1<v2?-1:1;
} 

int main(void)
{
    int t1, t2;
    t1=compare(10,1); 
    t2=compare(1.2, 18);
    printf("%d\n%d\n", t1,t2);
    return 0;
}