#include <stdio.h>
#include <stdlib.h>

#define size 5

void insert_data(int data, int q[], int *r)
{
    int j;
    
    if(*r == size -1)
    {
        printf("Queue is full\n");
        return;
    }

    j = *r;

    while(j >= 0 && data < q[j])
    {
        q[j+1] = q[j];
        j--;
    }

    q[j+1] = data;
    *r = *r + 1;
}

int delete(int *front, int *rear, int q[])
{
    if(*front > *rear) return -1;
    return q[(*front)++];
}

void display(int front, int rear, int q[])
{
    if(front > rear)
    {
        printf("Queue is empty\n");
        return;
    }

    for(int i = front; i <= rear; i++)
    {
        printf("%d ",q[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int ch, data, front, rear, q[10];
    front = 0;
    rear = -1;

    printf("1.Insert into priority queue\n2.delete\n3.Display\n");
    
    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("enter the data: ");
                scanf("%d",&data);
                insert_data(data , q, &rear);
                break;
            case 2:
                data = delete(&front, &rear, q);
                if(data == -1)
                    printf("Queue is empty\n");
                else 
                    printf("Item deleted %d\n",data);
                break;
            case 3:
                display(front, rear , q);
                break;
            default:
                exit(0);
            
        }
    }

    return EXIT_SUCCESS;
}
