#include "stdio.h"
#include "stdlib.h"
#include "math.h"

struct node 
{
    int cf, px, py, pz;
    struct node *link;
};

typedef struct node *Node;

Node getnode()
{
    Node temp;
    temp = (Node)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("out of memory\n");
        exit(0);
    }
    return temp;
}

Node insert_rear(int cf, int px, int py, int pz, Node head)
{
    Node temp, cur;
    temp = getnode();
    temp->cf = cf;
    temp->px = px;
    temp->py = py;
    temp->pz = pz;

    cur = head->link;
    while (cur->link != head ) {
        cur = cur->link;
    }
    cur->link = temp;
    temp->link = head;
    return head;
}

Node read_poly(Node head)
{
    int n;
    int px,py,pz,cf;
    printf("Enter the no of terms : ");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        printf("Enter cf, px, py, pz : ");
        scanf("%d%d%d%d",&cf,&px,&py,&pz);
        head = insert_rear(cf , px , py , pz , head);
    }
    return head;
}

void display(Node head)
{
    Node temp;
    if(head->link == head)
    {
        printf("Polynomial doesn't exist\n");
        exit(0);
    }

    temp = head->link;
    while (temp != head ) {
        if(temp == head->link)
        {
            printf("%d x^%d y^%d z^%d ",temp->cf,temp->px,temp->py,temp->pz);
        }
        else{
            printf("+ %d x^%d y^%d z^%d ",temp->cf,temp->px,temp->py,temp->pz);
        }
        temp = temp->link;
    }
    printf("\n");
}

float evaluate(Node head)
{
    float res = 0.0;
    int x,y,z;
    Node temp;
    temp = head->link;
    printf("Enter the values for x, y, z: ");
    scanf("%d%d%d",&x,&y,&z);
    while (temp != head ) {
        res += temp->cf * pow(x,temp->px) * pow(y,temp->py) * pow(z,temp->pz);
        temp = temp->link;
    }
    return res;
}


Node search(Node p1, Node p2)
{
    int cf1, px1, py1, pz1, cf2, px2, py2, pz2;
    Node h;
    cf1 = p1->cf; px1 = p1->px; py1 = p1->py; pz1 = p1->pz;
    h = p2->link;
    while (h != p2 ) {
        cf2 = h->cf; px2 = h->px; py2 = h->py; pz2 = h->pz;
        if(px1 == px2 && py1 == py2 && pz1 == pz2) break; 
        h = h->link;
    }
    return h;
}

Node copy_poly(Node h2, Node h3)
{
    Node p2;
    int cf2, px2, py2, pz2;
    p2 = h2->link;
    while (p2 != h2) {
        if(p2->cf != -999)
        {
            cf2 = p2->cf; px2 = p2->px; py2 = p2->py; pz2 = p2->pz;
            h3 = insert_rear(cf2,px2,py2,pz2,h3);
        }
        p2 = p2->link;
    }
    return h3;
}

Node add_poly(Node h1, Node h2, Node h3)
{
    Node p1,p2;
    int cf1,px1,py1,pz1,sum;
    p1 = h1->link;
    while (p1 != h1 ) {
        cf1 = p1->cf, px1 = p1->px, py1 = p1->py, pz1 = p1->pz;
        p2 = search(p1,h2);
        if(p2 != h2)
        {
            sum = cf1 + p2->cf;
            h3 = insert_rear(sum , px1 , py1 , pz1 , h3);
            p2->cf = -999;
        }
        else {
            h3 = insert_rear(cf1 , px1 , py1 , pz1 , h3);
        }
        p1 = p1->link;
    } 
    h3 = copy_poly(h2 , h3);
    return h3;
}


int main (int argc, char *argv[]) 
{
     float res;
    int ch;
    Node e1,h1,h2,h3;
    e1 = getnode();
    h1 = getnode();
    h2 = getnode();
    h3 = getnode();
    e1->link = e1; h1->link = h1; h2->link = h2; h3->link = h3;
    
    printf("1.Evaluate\n2.Add two Polynomial\n3.Exit\n");
    while (1) {
        printf("Enter you choice: ");
        scanf("%d",&ch);
        switch (ch ) {
            case 1:
                e1 = read_poly(e1);
                display(e1);
                res = evaluate(e1);
                printf("Result = %f\n",res);
                free(e1);
                e1 = getnode();
                e1->link = e1;
                break;
            case 2:
                h1 = read_poly(h1);
                h2 = read_poly(h2);
                printf("Poly 1: "); display(h1);
                printf("Poly 2: "); display(h2);
                h3 = add_poly(h1 , h2 , h3);
                printf("\nPoly3: "); display(h3);
                free(h1);free(h2);free(h3);
                h1 = getnode(); h1->link = h1;
                h2 = getnode(); h2->link = h2;
                h3 = getnode(); h3->link = h3;
                break;
            case 3:
                exit(0);
            default:
                printf("Wrong choice");
                break;
        }
    } 
}

