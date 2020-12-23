#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *insert(node *temp, int data)
{
    if (!temp)
    {
        node *toReturn = malloc(sizeof(node));
        toReturn->data = data;
        return toReturn;
    }
    if (data > temp->data)
        temp->right = insert(temp->right, data);
    else
        temp->left = insert(temp->left, data);
    return temp;
}
void displayBinTree(node *root, int i)
{
    int j;
    if (root != NULL)
    {
        displayBinTree(root->left, i + 1);
        for (j = 1; j <= i; j++)
            printf("\t");
        printf("%d \n", root->data);
        displayBinTree(root->right, i + 1);
    }
}
int main()
{

    struct node *root = NULL;

    int CASE = 10;
    while (CASE != 3)
    {
        printf("Choose an option \n1)insert\n2)display\n3)exit\n");
        scanf("%d", &CASE);
        if (CASE == 1)
        {
            printf("Enter the data to insert : ");
            int data;
            scanf("%d", &data);
            root = insert(root, data);
        }
        else if (CASE == 2)
            displayBinTree(root, 1);
    }
    return 0;
}