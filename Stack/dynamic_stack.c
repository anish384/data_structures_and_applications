#include <stdio.h>
#include <stdlib.h>

int size = 1;
int *stack = NULL;
int top = 0;


void push(int data)
{
    if(top == size)
    {
        printf("Size increased by 1\n");
        size++;
        stack = (int *)realloc(stack , size * sizeof(int));
        if(stack == NULL)
        {
            printf("failed to allocate the memory\n");
            exit(0);
        }
    }
    stack[top++] = data;
}

int pop()
{
    if(top == 0) {
        printf("Underflow\n");
        return 0;
    }
    return stack[--top];
}

void display()
{
    for(int i = top-1; i >= 0; i--)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    stack = (int *)malloc(size * sizeof(int));
    push(1);
    push(2);
    push(3);
    push(4);
    display();
    return 0;
}
