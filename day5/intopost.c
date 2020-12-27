#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define SIZE 100
#define bool _Bool
char STACK[SIZE];
int top = -1;

char INFIX[SIZE], POSTFIX[SIZE];

bool is_operator(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
        return 1;
    return 0;
}

int get_precedence(char x)
{
    if (x == '+' || x == '-')
        return 2;
    else if (x == '*' || x == '/')
        return 3;
    else if (x == '^')
        return 4;
    return -1;
}

void push(char data)
{
    if (top > SIZE - 1)
        printf("Stack Overflow");
    else
        STACK[++top] = data;
}

char pop()
{
    if (top > -1)
        return STACK[top--];
    else
    {
        printf("STACK UNDERFLOW");
        return -1;
    }
}

void infix_to_postfix()
{
    int i = 0, j = 0;
    char x, item;
    push('(');
    strcat(INFIX, ")");
    item = INFIX[i];
    while (item != '\0')
    {
        if (item == '(')
            push(item);
        else if (isdigit(item) || isalpha(item))
            POSTFIX[j++] = item;
        else if (is_operator(item))
        {
            x = pop();
            while (is_operator(x) == 1 && get_precedence(x) >= get_precedence(item))
            {
                POSTFIX[j++] = x;
                x = pop();
            }
            push(x);
            push(item);
        }
        else if (item == ')')
        {
            x = pop();
            while (x != '(')
            {
                POSTFIX[j++] = x;
                x = pop();
            }
        }
        else
        {
            printf("\nInvalid infix Expression.\n");
            exit(1);
        }
        i++;
        item = INFIX[i];
    }
    if (top > 0)
    {
        printf("\nInvalid infix Expression.\n");
        exit(1);
    }

    POSTFIX[j] = '\0';
}
int main()
{
    printf("ASSUMPTION: The infix expression contains single letter variables and single digit constants only.\n");
    printf("\nEnter Infix expression : ");
    scanf("%s", INFIX);
    //   fgets(INFIX, SIZE, stdin);
    infix_to_postfix();
    printf("Postfix Expression: ");
    puts(POSTFIX);

    return 0;
}
