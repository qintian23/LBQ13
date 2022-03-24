#include <stdio.h>
#include <math.h>
#include <complex.h> // C
#include <complex>
#include <iostream>

using namespace std;

int main()
{
    // 整型
    int maxIntVal(10); // 初始化
    // maxIntVal(20); // 错误，这种方式只有在声明时使用
    maxIntVal=0xffff; // 
    printf("%d, %d\n",sizeof(maxIntVal), maxIntVal);
    maxIntVal=0xffff0000;
    printf("%d, %d\n",sizeof(maxIntVal), maxIntVal);

    unsigned mival=0xffffffff; // 溢出？？
    // mival=0x8fffffff;
    printf("%d, %d\n",sizeof(mival), mival);

    // 特殊数值来源于 math.h 的宏定义
    printf("log2(e) = %lf\n",M_LOG2E);
    printf("log10(e) = %lf\n",M_LOG10E);
    printf("ln(2) = %lf\n",M_LN2);
    printf("ln(10) = %lf\n",M_LN10);
    printf("pi/2 = %lf\n",M_PI_2);
    printf("pi/4 = %lf\n",M_PI_4);
    printf("1/pi = %lf\n",M_1_PI);
    printf("2/pi = %lf\n",M_2_PI);
    printf("2/sqrt(pi) = %lf\n",M_2_SQRTPI);
    printf("sqrt(2) = %lf\n",M_SQRT2);
    printf("1/sqrt(2) = %lf\n",M_SQRT1_2);

    printf("-0 == 0 ? %s\n",-0==0?"yex":"no");
    int sval=1e2;
    printf("1e2 = %d\n",sval);

    // C/C++中一般使用某类型的大值作为无穷大值如，int inf=0x7fffffff; 但是对于一些运算如最短路，这个inf再加上一个值就会溢出，因此一般使用：0x3f3f3f3f

    // C中的复数
    _Complex double dcomplex=2.000+3I;
    cout<< '(' << creal(dcomplex) << ',' << cimag(dcomplex) <<')' <<endl;
    __complex__ double dcomplex1=2.000+4I;
    cout<< '(' << creal(dcomplex1) << ',' << cimag(dcomplex1) <<')' <<endl;
    _Complex double dcomplex2=conj(dcomplex); // 获取复数的共轭
    cout<< '(' << creal(dcomplex2) << ',' << cimag(dcomplex2) <<')' <<endl;
    dcomplex1=1+1I;
    double rho=carg(dcomplex1);
    cout<< rho  << '=' << M_PI_4 << endl;
    _Complex double lcomplex=cproj(dcomplex1);
    cout<< '(' << creal(lcomplex) << ',' << cimag(lcomplex) <<')' <<endl;

    // C++复数
    complex<double> mycomplex(7.000,2);
    cout<< mycomplex <<endl;
    complex<double> mycomplex1=4+3I;
    cout<< mycomplex1 <<endl;
    complex<double> mycomplex2=mycomplex1+mycomplex;
    cout<< mycomplex2 <<endl;
    cout<< real(mycomplex1) << ',' << mycomplex1.imag() <<endl;
    return 0;
}