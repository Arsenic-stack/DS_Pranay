#include <stdio.h>
#include <stdlib.h>
int gcd(int n1, int n2);
int main()
{
    int n1, n2;
    printf("Enter two positive integers: ");
    scanf("%d %d", &n1, &n2);
#ifdef WINDOWS
    system("cls");
#else
    system("clear");
#endif
    printf("G.C.D of %d and %d is %d.\n", n1, n2, gcd(n1, n2));
    return 0;
}
int gcd(int n1, int n2)
{
    if (n1 > n2)
        return gcd(n1 - n2, n2);
    if (n1 < n2)
        return gcd(n2 - n1, n1);
    if (n1==n2)
        return n1;
}