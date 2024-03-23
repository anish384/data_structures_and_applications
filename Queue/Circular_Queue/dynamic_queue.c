#include <stdio.h>
#include <stdlib.h>

int item, front, rear, count, *q;

int size = 1;

void insertq(int data)
{
    if(count == size)
    {
        printf("Queue size is full: Updating queue size\n");
        size++;
        q = (int *)realloc(q,size * sizeof(int));
        if(front > rear)
        {
            for(int i = size - 2; i >= front; i--)
            {
                q[i+1] = q[i];
            }
            front++;
        }
    }
    rear = (rear + 1) % size;
    q[rear] = data;
    count++;
}

int deleteQ()
{
    int data;
    if(count == 0) return -1;

    data = q[front];
    front = (front + 1) % size;

    return data;
}

void display()
{
    if(count == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    for(int i = 0, f = front; i < count; i++)
    {
        printf("%d ",q[f]);
        f = (f + 1) % size;
    }
}

int main(int argc, char *argv[])
{
    q = (int *)malloc(sizeof(int));
    insertq(2);
    insertq(3);
    insertq(4);
    insertq(5);
    insertq(6);
    insertq(7);
    insertq(8);
    deleteQ(); 
    insertq(10000);
    display();
    return EXIT_SUCCESS;
}
