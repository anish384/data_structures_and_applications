#include <stdio.h>
#include <stdlib.h>

struct node{
    int cf, px;
    struct node* next;
};

typedef struct node* Node;

Node insert_rear(Node first, int cf, int px)
{
    Node temp,cur;
    temp = (Node)malloc(sizeof(struct node));
    temp->cf = cf;
    temp->px = px;
    temp->next = NULL;

    if(first == NULL)
        return temp;

    cur = first;
    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = temp;
    return first;
}

void print_poly(Node first)
{
    Node cur;
    if(first == NULL)
    {
        printf("Poly isn't threre\n");
        return;    
    }
    cur = first;
    while (cur != NULL ) {
        if(cur == first)
            printf("%d x^%d ",cur->cf,cur->px);
        else 
            printf("+ %d x^%d ",cur->cf, cur->px);
        cur = cur->next;
    } 
    printf("\n");
}

Node search(int px1, Node second)
{
    Node cur;
    cur = second;
    while(cur != NULL)
    {
        if(cur->px == px1)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

Node copy_poly(Node third, Node second)
{
    Node cur;
    cur = second;
    while(cur != NULL)
    {
        if(cur->cf != -999)
            third = insert_rear(third , cur->cf, cur->px);
        cur = cur->next;
    }
    return third;
}

Node add_poly(Node first, Node second, Node third)
{
    Node cur,pos;
    int sum;
    cur = first;
    while(cur != NULL)
    {
        pos = search(cur->px, second);
        if(pos != NULL)
        {
            sum = pos->cf + cur->cf;
            third = insert_rear(third , sum , cur->px);
            pos->cf = -999;
        }
        else{
            third = insert_rear(third , cur->cf, cur->px);
        }
        cur = cur->next;
    }
    third = copy_poly(third , second);
    return third;
}

void free_poly(Node poly)
{
    Node temp;
    while(poly != NULL)
    {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main(int argc, char *argv[])
{
    Node first, second, third;
    first = second = third = NULL;
    int n,cf,px;
    printf("Enter n value: ");
    scanf("%d",&n);
    for(int i =0; i < n; i++)
    {
        printf("Enter cf, px: ");
        scanf("%d %d",&cf,&px);
        first = insert_rear(first , cf , px); 
    }
    printf("Enter n value: ");
    scanf("%d",&n);
    for(int i =0; i < n; i++)
    {
        printf("Enter cf, px: ");
        scanf("%d %d",&cf,&px);
        second = insert_rear(second , cf , px); 
    }
    print_poly(first);
    print_poly(second);
    printf("--------------------------------------------------\n");
    third = add_poly(first , second , third);
    print_poly(third);

    free_poly(first);
    free_poly(second);
    free_poly(third);
    return EXIT_SUCCESS;
}
