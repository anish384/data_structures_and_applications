#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 2
int s[MAX_SIZE];
#define MAX_STACKS 10 // Maximum number of stacks
int boundary[MAX_STACKS];
int top[MAX_STACKS];
int n; // Number of stacks entered by the user
int i, item; // stack number and element to be inserted
void push()
{
    /* Check for overflow of stack */
    if (top[i] == boundary[i+1])
    {
        printf("Stack %d is full\n", i);
        return;
    }
    s[++top[i]] = item;
}

int pop()
{
    if (top[i] == boundary[i])
        return -1; // stack is empty
    return s[top[i]--];
}

void display()
{
    int j;
    /* If stack is empty */
    if (top[i] == boundary[i])
    {
        printf("Stack %d empty\n",i);
        return;
    }
    /* Display contents of stack */
    printf("Contents of the stack\n");
    for (j=boundary[i+1]; j>=0; j--)
    {
        printf("%d ",s[j]);
    }
    printf("\n");
}

int main()
{
    int choice, j;
    printf("Enter number of queues (say 4 or 5)\n");
    scanf("%d", &n);
    for (j = 0; j <= n ; j++)
         boundary [j] = top[j] = MAX_SIZE / n * j - 1 ; /* stack is empty */
    for (;;)
    {
         printf("Stack number: ");
        for (j = 0; j < n; j++) printf("%d ", j);
         printf("Enter stack number: ");
         scanf("%d", &i);
        printf("1:Push 2:Pop\n"); printf("3:Display 4:Exit\n");
        printf("Enter the choice\n"); scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the item to be inserted\n");
                scanf("%d",&item);
                push();
                break;
            case 2:
                item = pop();
                if (item == -1)
                    printf("Stack is empty\n");
                else
                    printf("Item deleted = %d\n", item);
                break;
            case 3:
                display();
                break;
            default:
                exit(0);
        }
    }
}
