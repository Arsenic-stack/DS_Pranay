#include <stdio.h>
#include <ctype.h>
#include "posusingstack.h"
int total = 0;
void eval(char arr[])
{
    int i = 0, A, B, val;
    int length=sizeof(arr)/sizeof(char);
    for (int i = 0; i < length; i++)
    {
        char ch = arr[i];
        if (isdigit(ch))
        {
            int x = arr[i] - '0';
            push(x);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            A = pop();
            B = pop();

            switch (ch)
            {
            case '*':
                val = B * A;
                break;
            case '/':
                val = B / A;
                break;
            case '+':
                val = B + A;
                break;
            case '-':
                val = B - A;
                break;
            }
            push(val);
        }
    }
    printf("Result of expression evaluation : %d \n", pop());
}
int main(int argc, char const *argv[])
{
    char arr[100] = "12+";
    //  fgets(arr, 100, stdin);
    eval(arr);
    return 0;
}
