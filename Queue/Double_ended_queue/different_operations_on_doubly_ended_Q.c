#include <stdio.h>
#include <stdlib.h>

#define size 5

int ch, data, front, rear, q[20];

void insertfront(int data);
void insertrear(int data);
int deletefront();
int deleterear();
void display();

int main(int argc, char *argv[])
{
    front = 0;
    rear = -1;
    printf("1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Exit\n");
    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the data : ");
                scanf("%d",&data);
                insertfront(data);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d",&data);
                insertrear(data);
                break;
            case 3:
                data = deletefront();
                printf("%d deleted\n",data);
                break;
            case 4:
                data = deleterear();
                printf("%d deleted\n",data);
                break;
            case 5:
                display();
                printf("\n");
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Wrong choice\n");
                break;
            
        }
    }
    return EXIT_SUCCESS;
}

void insertfront(int data)
{
    if(front == 0 && rear == -1) // when Queue is empty we can insert at front end of the queue
    {
        q[++rear] = data;
        return;
    }

    if(front != 0) // when Some items are deleted from queue and there are some empty slots at front end of the queue => [] [] [] [30]<- front and rear pointer are here and before this slots are empty
    {
        q[--front] = data;
        return;
    }

    // from here we can't add any items at front end of The queue 
    printf("Front insertion is not possible\n");
}

void insertrear(int data){
    if(rear == size -1)
    {
        printf("Queue is full\n");
        return;
    }
    rear = rear + 1;
    q[rear] = data; 
}

int deleterear()
{
    int data;
    if(front > rear) return -1;
    data = q[rear--];
    if(front > rear) front = 0, rear = -1;

    return data;
}

int deletefront()
{
    int data;
    if(front > rear) return -1;
    data = q[front++];
    return data;
}

void display()
{
    if(front > rear)
    {
        printf("Queue is empty\n");
        return;
    }

    for(int i= front; i <= rear; i++)
    {
        printf("%d ",q[i]); 
    }
}

