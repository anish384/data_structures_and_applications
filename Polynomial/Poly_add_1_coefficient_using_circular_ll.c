#include "stdio.h"
#include "stdlib.h"

struct node{
    int cf,px;
    struct node* next;
};

typedef struct node* Node;

Node ini()
{
    Node head;
    head = (Node)malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("Failed to allocate the memory exiting now\n");
        exit(0);
    }
    head->next = head;
    return head;
}

Node insert_rear(Node first, int cf, int px)
{
    Node temp,cur;

    temp = (Node)malloc(sizeof(struct node));
    temp->cf = cf;
    temp->px = px;
    temp->next = NULL;
    if(first->next == first)
    {
        first->next = temp;
        temp->next = first;
        return first;
    }
    
    
    cur = first->next;
    while(cur->next != first)
    {
        cur = cur->next;
    }

    cur->next = temp;
    temp->next = first;

    return first;
}

Node read_poly(Node first)
{
    int cf, px;
    int n;
    printf("Enter the n : ");
    scanf("%d",&n);
    for(int i =0; i < n; i++)
    {
        printf("Enter cf, and px: ");
        scanf("%d %d",&cf,&px);
        first = insert_rear(first , cf , px);
    }
    return first;
}

void print_poly(Node first)
{
    Node cur;
    if(first->next == first)
    {
        printf("Poly doesn't exist\n");
        return;
    }

    cur = first->next;

    while(cur != first)
    {
        if(cur == first->next)
            printf("%d x^%d ",cur->cf,cur->px);
        else 
            printf("+ %d x^%d ",cur->cf,cur->px);
        cur = cur->next;
    }
    printf("\n"); 
}

Node search(Node first, Node second)
{
    Node cur;
    cur = second->next;
    while(cur != second)
    {
        if(cur->px == first->px)
            break;
        cur = cur->next;
    }
    return cur; 
}

Node copy_poly(Node second, Node third)
{
    Node cur = second->next;
    while(cur != second)
    {
        if(cur->cf != -999)
            third = insert_rear(third , cur->cf , cur->px);
        cur = cur->next;
    }
    return third;
}

Node add_poly(Node first, Node second, Node third)
{
    Node cur,pos;
    int sum;
    cur = first->next;
    while(cur != first)
    {
        pos = search(cur , second);
        if(pos != second)
        {
            sum = pos->cf + cur->cf;
            third = insert_rear(third , sum , cur->px);
            pos->cf = -999;
        }
        else{
            third = insert_rear(third , cur->cf , cur->px);
        }
        cur = cur->next;
    }
    third = copy_poly(second , third);
    return third;
}


int main (int argc, char *argv[]) {
    Node first, second, third;
    // first = (Node)malloc(sizeof(struct node));
    // second = (Node)malloc(sizeof(struct node));
    // third = (Node)malloc(sizeof(struct node));
    //
    // first->next = first;
    // second->next = second;
    // third->next = third;
    
    first = ini();
    second = ini();
    third = ini();
    
    read_poly(first); 
    read_poly(second); 

    print_poly(first);
    print_poly(second);

    third = add_poly(first , second , third);
    print_poly(third);

    free(first);
    free(second);
    free(third);
    return 0;
}
