
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *create()
{
    node *p;
    int x;
    printf("Enter data(-1 for no data):");
    scanf("%d", &x);

    if (x == -1)
        return NULL;

    p = (node *)malloc(sizeof(node));
    p->data = x;

    printf("Enter left child of %d:\n", x);
    p->left = create();

    printf("Enter right child of %d:\n", x);
    p->right = create();

    return p;
}

void preorder(node *t)
{
    if (t != NULL)
    {
        printf("%d ", t->data);
        preorder(t->left);
        preorder(t->right);
    }
}
void postorder(node *t)
{
    if (t != NULL)
    {
        postorder(t->left);
        postorder(t->right);
        printf("%d ", t->data);
    }
}

void inorder(node *t)
{
    if (t != NULL)
    {
        inorder(t->left);
        printf("%d ", t->data);
        inorder(t->right);
    }
}
void tests()
{
    node *root;
    root = create();
    printf("\nThe preorder traversal of tree is:\n");
    preorder(root);
    printf("\n");
    printf("\nThe postorder traversal of tree is:\n");
    postorder(root);
    printf("\n");
    printf("\nThe inorder traversal of tree is: \n");
    inorder(root);
    printf("\n");
    exit(0);
}

int main(int argc, char const *argv[])
{
    // tests();
    node *root;
    int CASE = 10;
    while (CASE != 5)
    {
        printf("Choose an option \n1)create tree \n2)preorder \n3)inorder \n4)postorder \n5)exit\n");
        scanf("%d", &CASE);
        if (CASE == 1)
        {
            root = create();
        }
        else if (CASE == 2)
            preorder(root);
        else if (CASE == 3)
            inorder(root);
        else if (CASE == 4)
            postorder(root);
    }
    return 0;
}
