#include <stdio.h>

void thanoi(int n, char frompeg, char topeg, char auxpeg)
{
    if (n == 1)
    {
        printf("move disk 1 %c to %c ", frompeg, topeg);
        return;
    }
    thanoi(n-1,auxpeg,topeg,frompeg);
    // incomplete
}