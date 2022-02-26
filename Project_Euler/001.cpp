/**
 * @file 001.cpp
 * @author Jianle
 * @brief Multiples of 3 and 5
 *        If we list all the natural numbers below  that are multiples of  or , we get , ,  and . The sum of these multiples is .
 *        Find the sum of all the multiples of  or  below .
 * @version 0.1
 * @date 2022-02-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

int main(void)
{
    long long sum=0;
    int below=1000;
    while (below--)
    {
        if(below%3==0 || below%5==0)
            sum+=below;
    }
    
    printf("SUM = %d\n",sum);

    return 0;
}
