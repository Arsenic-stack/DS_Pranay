#include <stdio.h>

void thanoi(int n, char frompeg, char topeg, char auxpeg)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", frompeg, topeg);
        return;
    }
    thanoi(n - 1, frompeg, auxpeg, topeg);
    printf("Moved disk %d from %c to peg %c\n", n, frompeg, topeg);
    thanoi(n - 1, auxpeg, topeg, frompeg);
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number of disks");
    scanf("%d", &n);
    thanoi(n, 'A', 'B', 'C');
    return 0;
}
