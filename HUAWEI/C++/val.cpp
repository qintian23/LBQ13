#include <stdio.h>

int main()
{

    int maxIntVal(10); // 初始化
    // maxIntVal(20); // 错误，这种方式只有在声明时使用
    maxIntVal=0xffffffff; // -1
    maxIntVal=0x7fffffff;
    printf("%d, %d\n",sizeof(maxIntVal), maxIntVal);

    unsigned mival=0xffffffff; // 溢出？？
    // mival=0x8fffffff;
    printf("%d, %d\n",sizeof(mival), mival);

    return 0;
}