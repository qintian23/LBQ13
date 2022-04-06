#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int getTime()
{
    char line[100]={};
    cin.getline(line, 100);
    int h1, m1, s1, h2, m2, s2, d=0;
    if(strlen(line)==17)
        sscanf(line, "%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
    else
        sscanf(line, "%d:%d:%d %d:%d:%d (+%d)", &h1, &m1, &s1, &h2, &m2, &s2, &d);
    int time=d*24*3600 + h2*3600 + m2*60 + s2 - (h1*3600 + m1*60 + s1);
    return time;
}

int main(int argc, char *argv[])
{
    int T;
    (cin>>T).get();
    for (int i = 0; i < T; i++)
    {
        int time1=getTime();
        int time2=getTime();
        int t=(time2+time1)/2;
        printf("%02d:%02d:%02d\n",t/3600, t/60%60, t%60);
    }
    return 0;
}

/*
3
17:48:19 21:57:24
11:05:18 15:14:23
17:21:07 00:31:46 (+1)
23:02:41 16:13:20 (+1)
10:19:19 20:41:24
22:19:04 16:41:09 (+1)
 */

// 输出
/*
04:09:05
12:10:39
14:22:05
*/