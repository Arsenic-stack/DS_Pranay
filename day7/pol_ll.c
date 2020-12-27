#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct node
{
    int coeff;
    int power;
    struct node *next;
} node;
node *head = NULL;
void insert(int coeff, int power)
{
    node *temp = (node *)(malloc(sizeof(node)));
    temp->coeff = coeff;
    temp->power = power;
    if (head == NULL)
    {
        temp->next = NULL;
        head = temp;
    }
    else
    {
        if (power > head->power)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            node *traverse = head;
            while (traverse->next && (traverse->next->power > power))
                traverse = traverse->next;
            temp->next = traverse->next;
            traverse->next = temp;
        }
    }
}
void display()
{
    node *temp = head;
    while (temp->next)
    {
        printf("%dx^%d+", temp->coeff, temp->power);
        temp = temp->next;
    }
    printf("%dx^%d=0\n", temp->coeff, temp->power);
}

long int eval(int x)
{
    long int sum = 0;
    node *temp = head;
    while (temp)
    {
        sum = sum + temp->coeff * pow(x, temp->power);
        temp = temp->next;
    }
    printf("\n%ld\n", sum);
}
void tests()
{
    insert(70, 7);
    insert(50, 5);
    display();
    eval(1);
    exit(0);
}

int main(int argc, char const *argv[])
{
    // tests();
    int CASE = 10;
    while (CASE != 4)
    {
        printf("Choose an option \n1)insert\n2)display\n3)evaluate\n4)exit\n");
        scanf("%d", &CASE);
        if (CASE == 1)
        {
            printf("Enter the coefficent and power to insert : ");
            int data, power;
            scanf("%d %d", &data, &power);
            insert(data, power);
        }
        else if (CASE == 2)
            display();
        else if (CASE == 3)
        {
            printf("Enter the value of x : ");
            int x;
            eval(x);
        }
    }
    return 0;
}
