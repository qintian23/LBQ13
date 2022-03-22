#include <stdio.h>

/**
 * @brief 宏定义
 * 
 *   HALF_BITS_LENGTH： 存储单元长度的一般4bit
 *           FULLMASK： 表示一个bit的mask，表示 11111111
 *              LMASK： 左半bit的mask，表示11110000
 *              RMASK： 右半bit的mask，表示00001111
 *               LSET： 将b的左边设置成n
 *               RSET： 将b的右边设置成n
 *               LGET： 得到b左边的值
 *               RGET： 得到b右边的值
 *              GRIDW： 表示将帅移动范围的行宽度
 */
#define HALF_BITS_LENGTH 4
#define FULLMASK 255
#define LMASK (FULLMASK << HALF_BITS_LENGTH)
#define RMASK (FULLMASK >> HALF_BITS_LENGTH)
#define RSET(b,n) (b=((LMASK & b) | (n)))
#define LSET(b,n) (b=((RMASK & b) | ((n) << HALF_BITS_LENGTH)))
#define RGET(b) (RMASK & b)
#define LGET(B) ((LMASK&b) >> HALF_BITS_LENGTH)
#define GRIDW 3

int main()
{
    unsigned char b;
    for (LSET(b,1); LGET(b)<=GRIDW*GRIDW; LSET(b,(LGET(b)+1)))
        for (RSET(b,1); RGET(b)<=GRIDW*GRIDW; RSET(b,(RGET(b)+1)))
            if(LGET(b)%GRIDW!=RGET(b)%GRIDW)
                printf("A = %d, B = %d\n",LGET(b),RGET(b));
    return 0;
}