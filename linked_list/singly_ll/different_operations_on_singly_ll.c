#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *link;
};

typedef struct node* Node;

Node insert_front(Node first, int data)
{
    Node temp;
    temp = (Node)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    if(first == NULL){
        return temp;
    }

    temp->link = first;
    return temp;
}

Node insert_end(Node first, int data)
{
    Node temp;
    temp = (Node)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    if(first == NULL)
    {
        return temp;
    }

    Node cur = first;
    while (cur->link != NULL) {
        cur = cur->link; 
    }
    cur->link = temp;
    return first;
}

Node delete_front(Node first)
{
    if(first == NULL)
    {
        printf("Deletion operation can't be performed\n");
        return NULL;
    }
    Node cur = first->link;
    free(first);
    return cur;
}

Node delete_end(Node first)
{
    Node cur = first;
    Node prev = NULL;
    if(first == NULL){
        printf("Deletion operation can't be performed\n");
        return NULL;
    }
    while (cur->link != NULL ) {
        prev = cur;
        cur = cur->link;
    }
    prev->link = NULL;
    free(cur);
    return first;
}

void search(Node first,int key)
{
    Node cur;
    int count = 0;
    cur = first;
    while (cur->link!= NULL ) {
        if(cur->data == key)
        {
            printf("Found at %d\n",count);
            return;
        }
        count++;
        cur = cur->link;
    }
    printf("Not found\n"); 
}

void display(Node first)
{
    Node cur = first;
    if(first == NULL){
        printf("List is empty\n");
        return;
    }
    while (cur != NULL) {
        printf("%d ",cur->data);
        cur = cur->link;
    }
    printf("\n");
}

void length(Node first)
{
    int count = 0;
    Node cur = first;
    if(first == NULL)
    {
        printf("linked list is empty\n");
        return;
    }

    while (cur != NULL ) {
        count++;
        cur = cur->link;
    }
    printf("Length of linked list is : %d\n",count);
}

Node delete_specefic(Node first, int key)
{
    if(first->link == NULL && first->data == key)
    {
        free(first);
        return NULL;
    }
    Node cur = first, prev = NULL;
    int flag = 0;
    while (cur != NULL ) {
        if(cur->data == key)
        {
            flag = 1;
            break; 
        }
        prev = cur;
        cur = cur->link;
    }
    if(flag == 0)
    {
        printf("not found\n");
        return first;
    }
    prev->link = cur->link;
    free(cur);
    return first;
}

Node concate(Node first, Node second)
{
    Node cur = first;
    while (cur->link != NULL ) {
        cur = cur->link;
    }
    cur->link = second;
    return first;
}

Node ordered_list(Node first, int data)
{
    Node cur = first, prev = NULL, temp;
    temp = (Node)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    
    if(first == NULL) return temp;

    if(data <= first->data)
    {
        temp->link = first;
        return temp;
    }

    while (cur != NULL && data > cur->data) {
        prev = cur;
        cur = cur->link;
    }
    prev->link = temp;
    temp->link = cur;
    return first;
}

Node reverse_list(Node first)
{
    Node cur,temp;
    cur = NULL;
    while (first != NULL ) {
        temp = first->link;
        first->link = cur;
        cur = first;
        first = temp;
    }
    return cur;
}

int main(int argc, char *argv[])
{
    Node first = NULL;
    Node second = NULL;
    Node order = NULL;

    first = insert_front(first , 2);
    first = insert_front(first , 3);

    first = insert_end(first , 10);
    first = insert_end(first , 12);



    display(first);
    second = insert_front(second , 100);
    second = insert_front(second , 200);
    second = insert_end(second , 199);
    second = insert_end(second, 99);
    search(first , 2);
    display(second);

    first = concate(first , second);
    printf("Concatenated list : ");
    display(first);
    length(first);
    length(second);

    order = ordered_list(order , 2);
    order = ordered_list(order , 10);
    order = ordered_list(order, -1);
    order = ordered_list(order, 101);
    printf("ordered list : ");
    display(order);
    first = delete_specefic(first , 10);
    display(first);
    first = reverse_list(first);
    display(first);
}
