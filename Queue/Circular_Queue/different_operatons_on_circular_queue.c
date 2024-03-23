#include <stdio.h>
#include <stdlib.h>

#define max 5

int q[max];
int front = 0;
int rear = -1;
int count = 0;

void insert_q(int data)
{
    if(count == max)
    {
        printf("Queue is full\n");
        return;
    }
    rear = (rear + 1) % max;
    q[rear] = data;
    count++;
}

int delete_q()
{
    int item;
    if(count == 0){ printf("Deletion operation cant be performed\n"); return -1;
    }
    item = q[front];
    front = (front + 1) % max;
    count--;
    return item;
}

void display()
{
    if(count == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    for(int i= 0, f = front; i < count; i++ )
    {
        printf("%d ",q[i]); 
        f = (f+1)%max;
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int delete_data;
    insert_q(2); 
    insert_q(3); 
    insert_q(4); 
    insert_q(5); 
    insert_q(6); 
    delete_data = delete_q(); 
    printf("%d deleted\n",delete_data);
    printf("\n");
    insert_q(9);
    display(); // displays 9 3 4 5 6 

    return EXIT_SUCCESS;
}
