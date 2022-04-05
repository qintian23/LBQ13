#include "easyLogger.h"

int main()
{
    easyLogger::myInst()->Log("shiyanlou logger test start");
    easyLogger::myInst()->Log("info info info");
    easyLogger::myInst()->Log("shiyanlou logger test end");
    return 0;
}