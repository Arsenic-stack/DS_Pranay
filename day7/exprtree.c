#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree
{
    char data;
    tree *left, *right;
} tree;

int top = -1;
tree *stack[20];

tree *node;

void push(tree *node)
{
    stack[++top] = node;
}

tree *pop()
{
    return (stack[top--]);
}

int check(char ch)
{
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
        return 2;
    else
        return 1;
}

int cal(tree *node)
{
    int ch;
    ch = check(node->data);
    if (ch == 1)
        return node->data - 48;

    else if (ch == 2)
    {
        if (node->data == '+')
            return cal(node->left) + cal(node->right);
        if (node->data == '-')
            return cal(node->left) - cal(node->right);
        if (node->data == '*')
            return cal(node->left) * cal(node->right);
        if (node->data == '/')
            return cal(node->left) / cal(node->right);
    }
    return 0;
}

void inorder(tree *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%c", node->data);
        inorder(node->right);
    }
}

void operand(char b)
{
    node = (tree *)malloc(sizeof(tree));
    node->data = b;
    push(node);
}

void operators(char a)
{
    node = (tree *)malloc(sizeof(tree));
    node->data = a;
    node->right = pop();
    node->left = pop();
    push(node);
}

int main()
{
    int i, op, result;
    char postfix[20];

    printf("Enter the expression in postfix form \n");
    fflush(stdin);
    scanf("%s", postfix);

    i = 0;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        op = check(postfix[i]);
        if (op == 1)
            operand(postfix[i]);
        else if (op == 2)
            operators(postfix[i]);
    }
    result = cal(stack[top]);
    printf("\nThe value of the postfix expression you entered is %d\n", result);
    printf("\nThe inorder traversal of the tree is: ");
    inorder(stack[top]);
    printf("\n");
}
