#include <stdio.h>
#include <stdlib.h>

struct node{
    int cf, px, py, pz;
    struct node* next;
};

typedef struct node* Node;

Node insert_rear(Node first, int cf, int px, int py, int pz)
{
    Node temp,cur;
    temp = (Node)malloc(sizeof(struct node));
    temp->cf = cf;
    temp->px = px;
    temp->py = py;
    temp->pz = pz;
    temp->next = NULL;

    if(first == NULL)
    {
        return temp;
    }
    cur = first;
    while (cur->next != NULL ) {
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
        printf("Poly not exist\n");
        return;    
    }

    cur = first;
    while (cur != NULL ) {
        if(cur == first)
        {
            printf("%d x^%d y^%d z^%d ",cur->cf,cur->px,cur->py,cur->pz);
        }
        else {
            printf("+ %d x^%d y^%d z^%d ",cur->cf,cur->px,cur->py,cur->pz);
        }
        cur = cur->next;
    }
    printf("\n");
}

Node search(int px1, int py1, int pz1, Node second)
{
    Node cur;
    cur = second;
    while (cur != NULL ) {
        if(cur->px == px1 && cur->py == py1 && cur->pz == pz1)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

Node copy_poly(Node third, Node second)
{
    Node cur;
    cur = second;
    while (cur != NULL ) {
        if(cur->cf != -999)
            third = insert_rear(third , cur->cf , cur->px , cur->py , cur->pz);
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
        pos = search(cur->px , cur->py , cur->pz , second);
        if(pos != NULL)
        {
            sum = pos->cf + cur->cf;
            third = insert_rear(third , sum , cur->px , cur->py , cur->pz);
            pos->cf = -999;
        }
        else{
            third = insert_rear(third, cur->cf, cur->px, cur->py, cur->pz);
        }
        cur = cur->next;
    }
    third = copy_poly(third , second);
    return third;
}

int main(int argc, char *argv[])
{
    Node first = NULL, second = NULL, third = NULL;
    int n;
    printf("Enter the n value: ");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        int cf, px, py, pz;
        printf("Enter cf, px, py, pz : ");
        scanf("%d %d %d %d",&cf,&px,&py,&pz);
        first = insert_rear(first , cf , px , py , pz);
    }
    int n2;
    printf("Enter the n value: ");
    scanf("%d",&n2);
    for(int i = 0; i < n2; i++)
    {
        int cf, px, py, pz;
        printf("Enter cf, px, py, pz : ");
        scanf("%d %d %d %d",&cf,&px,&py,&pz);
        second = insert_rear(second , cf , px , py , pz);
    }

    print_poly(first);
    print_poly(second);
    printf("----------------------------------------\n");
    third = add_poly(first, second, third);
    print_poly(third);
     
    return EXIT_SUCCESS;
}
