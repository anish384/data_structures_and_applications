#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int cf, px, py, pz;
    struct node* next;
};

typedef struct node* Node;

Node insert_rear(Node head, int cf, int px, int py, int pz)
{
    Node cur,temp;
    temp = (Node)malloc(sizeof(struct node));
    temp->cf = cf;
    temp->px = px; temp->py = py; temp->pz = pz;
    temp->next = NULL;

    if(head->next == head)
    {
        head->next = temp;
        temp->next = head;
        return head;
    }
    cur = head->next;
    while (cur->next != head ) {
        cur = cur->next;
    }
    cur->next = temp;
    temp->next = head;
    return head;
}

Node read_poly(Node head)
{
    int n,cf,px,py,pz;
    printf("Enter the n value: ");
    scanf("%d",&n);
    for(int i = 0; i < n ;i++)
    {
        printf("Enter cf, px, py, pz: ");
        scanf("%d %d %d %d",&cf,&px,&py,&pz);
        head = insert_rear(head , cf , px , py , pz);
    }
    return head;
}

void print_poly(Node head)
{
    Node cur;
    if(head->next == head)
    {
        printf("Poly doesn't exits yet\n");
        return;    
    }
    cur = head->next;
    while (cur != head ) {
        if(cur == head->next)
            printf("%d x^%d y^%d z^%d ",cur->cf, cur->px,cur->py,cur->pz);
        else
            printf("+ %d x^%d y^%d z^%d ",cur->cf, cur->px,cur->py,cur->pz);
        cur = cur->next;
    }
    printf("\n");
}

Node search(Node first, Node second)
{
    Node cur;
    cur = second->next;
    while (cur != second ) {
        if(cur->px == first->px && cur->py == first->py && cur->pz == first->pz)
            break;
        cur = cur->next;
    }
    return cur;
}

Node copy_poly(Node third, Node second)
{
    Node cur = second->next;
    while (cur != second) {
        if(cur->cf != -999)
            third = insert_rear(third , cur->cf , cur->px , cur->py, cur->pz);
        cur = cur->next;
    } 
    return third;
}

Node add_poly(Node first, Node second, Node third)
{
    Node cur, pos;
    int sum;
    cur = first->next;

    while(cur != first)
    {
        pos = search(cur , second);
        if(pos != second)
        {
            sum = pos->cf + cur->cf;
            third = insert_rear(third , sum , cur->px, cur->py, cur->pz);
            pos->cf = -999;
        }
        else{
            third = insert_rear(third , cur->cf, cur->px, cur->py , cur->pz);
        }
        cur = cur->next;
    }
    third = copy_poly(third , second);
    return third;
}

int main(int argc, char *argv[])
{
    Node first, second, third ;
    first = second = third = NULL;
    first = (Node)malloc(sizeof(struct node));
    second = (Node)malloc(sizeof(struct node));
    third = (Node)malloc(sizeof(struct node));

    first->next = first; second->next = second; third->next = third;

    read_poly(first);
    read_poly(second);

    print_poly(first);
    print_poly(second);

    third = add_poly(first , second , third);
    print_poly(third);
    
    free(first);
    free(second);
    free(third);
    return EXIT_SUCCESS;
}
