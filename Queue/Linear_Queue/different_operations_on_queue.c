#include <stdio.h>
#include <stdlib.h>

#define max 5

int q[100];
int front = 0;
int rear = -1;

void insert(int data)
{
    if(rear == (max - 1))
    {
        printf("Queue is Full\n");
        return;
    }
    q[++rear] = data; // [a] [b]<-rear 
}

int delete()
{
    if(rear == -1)
    {
        printf("Queue is empty can't perform delete operation\n");
        return -1;
    }
    return q[front++]; // x[a]x [b] [c] [d] [e]
}

void display()
{
    for(int i = front; i <= rear; i++)
    {
        printf("%d ",q[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int data;
    insert(2); 
    insert(3); 
    insert(4); 
    insert(5); 
    insert(5); 
    data = delete();
    insert(5);  // here is the disadvantage of linear queue as even if slot is empty we can't insert in that empty slot
    display();

    return EXIT_SUCCESS;
}
