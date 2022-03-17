#include <stdio.h>

int main(int argc, char** argv)
{
    int mon=8000;
    double wuxian=0.0;
    double yijin=0.0;
    double shui=0.0;
    double mm;

    if(mon<6000)
    {
        wuxian=3800*0.105;
        if(mon>=4500)
        {
            yijin=3000*0.008;
        }
    }
    else
    {
        wuxian=5000*0.105;
        if(mon<9000)
        {
            yijin=5000*0.008;
        }
        else if(mon<12000)
        {
            yijin=6500*0.008;
        }
        else
        {
            yijin=8000*0.008;
        }
    }

    shui=(mon-5000-wuxian-yijin);
    if(shui<=3000)
        shui=shui*0.03;
    else if(shui<=12000)
        shui=shui*0.1-210;
    else if(shui<=25000)
        shui=shui*0.2-1410;
    else if(shui<=35000)
        shui=shui*0.25-2660;
    else if(shui<=55000)
        shui=shui*0.3-4410;
    else if(shui<=80000)
        shui=shui*0.35-7160;
    else 
        shui=shui*0.45-15160;
    
    mm=mon-wuxian-yijin-shui;

    printf("五险：%lf，一金：%lf，个人所得税：%lf，月薪：%lf，年薪：%lf\n",wuxian,yijin,shui,mm,mm*14);
    return 0;
}