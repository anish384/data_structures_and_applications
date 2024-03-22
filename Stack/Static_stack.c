#include <stdio.h>


#define max 5
int stack[max];
int top = -1;

void push(int data)
{
    if(top == (max -1))
    {
        printf("Stack is full\n");
        return;
    }
    stack[++top] = data;
}

int pop()
{
    if(top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[--top];
}

void display()
{
    for(int i = top; i >= 0; i--)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    push(1);
    push(2);
    push(3);
    pop();
    display();
    return 0;
}
