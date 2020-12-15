#include <stdio.h>
#include <ctype.h>
#include "posusingstack.h"
int total = 0;
void eval()
{
    char temp = 'x';
    temp = pop();
    while (temp != -127)
    {
        if (temp == '*')
            total += ((int)pop() * (int)pop());
        else if (temp == '+')
            total += ((int)pop() + (int)pop());
        else if (temp == '-')
            total += ((int)pop() - (int)pop());
        if (temp == '/')
            total += ((int)pop() / (int)pop());
        temp = pop();
    }
}

int main(int argc, char const *argv[])
{
    //     char arr[100]="12+";
    //    // fgets(arr, 100, stdin);
    //     int i = 0;
    //     while (arr[i] != '\0')
    //     {
    //         push(arr[i]);
    //         i++;
    //     }
    //     eval();
    printf("later");
    return 0;
}
