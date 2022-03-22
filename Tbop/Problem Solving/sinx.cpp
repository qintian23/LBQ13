#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <math.h>

const int SAMPLING_COUNT=200;
const double PI=3.1415926535;
const int TOTAL_AMPLITUDE=300;

int _tmain(int argc, _TCHAR* argv[])
{
    DWORD busySpan[SAMPLING_COUNT];
    int amplitude=TOTAL_AMPLITUDE / 2;
    double radian=0.0;
    double radianIncrement=2.0/(double)SAMPLING_COUNT; // 抽样弧度的增量
    for (int i = 0; i < SAMPLING_COUNT; i++)
    {
        busySpan[i]=(DWORD)(amplitude + (sin(PI*radian)*amplitude));
        radian+=radianIncrement;
        // printf("%d\t%d\n",busySpan[i],TOTAL_AMPLITUDE-busySpan[i]);
    }
    
    DWORD startTime=0;
    for (int j = 0; ;j=(j+1)%SAMPLING_COUNT)
    {
        startTime=GetTickCount();
        while ((GetTickCount()-startTime)<=busySpan[j])
            ;
        Sleep(TOTAL_AMPLITUDE-busySpan[j]);
        
    }
    return 0;
}