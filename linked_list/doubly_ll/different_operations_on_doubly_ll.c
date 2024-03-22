#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *prev;
    struct node *next;
};

typedef struct node* Node;

Node getnode()
{
    Node x;
    x = (Node)malloc(sizeof(struct node));
    if(x == NULL)
    {
        printf("Failed to allocate the memory\n");
        exit(0);
    }
    return x;
}

Node insert_front(Node first, int data)
{
    Node temp;
    temp = getnode();
    temp->data = data;
    temp->prev = temp->next = NULL;
    if(first == NULL)
    {
        return temp;
    }
    temp->next = first;
    return temp;
}

Node insert_rear(Node first, int data)
{
    Node cur, temp;
    temp = getnode();
    temp->data = data;
    temp->next = temp->prev = NULL;
    if(first == NULL)
    {
        return temp;
    }
    cur = first;
    while (cur->next != NULL ) {
        cur = cur->next;
    }
    cur->next = temp;
    temp->prev = cur;
    return first;
}

Node delete_front(Node first)
{
    Node cur;
    if(first == NULL)
    {
        printf("Deletion can't be performed as list is empty\n");
        return NULL;
    }
    cur = first->next;
    cur->prev = NULL;
    free(first);
    return cur;
}

Node delete_end(Node first)
{
    Node cur,prev;
    if(first == NULL)
    {
        printf("Deletion can't be performed\n");
        return NULL;
    }
    prev = NULL;
    cur = first;
    while (cur->next != NULL ) {
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
    printf("Deleted %d\n",cur->data);
    free(cur);
    return first;
}

void display(Node first)
{
    Node cur;
    cur = first;
    while (cur!= NULL ) {
        printf("%d ",cur->data);
        cur = cur->next;
    }
}

int length(Node first)
{
    int count = 0;
    Node cur = first;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
}

Node insert_intermidate(Node first, int data)
{
    Node cur,temp,prev= NULL;
    int len,count = 0;
    len = length(first);
    cur = first;

    temp = getnode();
    temp->data = data;
    temp->next = temp->prev = NULL;
    
    if(first == NULL)
    {
        return temp;     
    }
    while (cur != NULL && count != (len / 2)) {
        prev = cur;
        cur = cur->next; 
        count++;
    }
    if(len == 1)
    {
        cur->next = temp;
        temp->next = NULL;
        temp->prev = cur;
        return cur;
    }
    temp->next = cur;
    cur->prev = temp;
    temp->prev = prev;
    prev->next = temp;
    return first;
}

Node Insert_specific(Node first, int data, int key)
{
    Node cur,temp,prev;
    temp = getnode();
    temp->data = data;
    temp->next = temp->prev = NULL;
    int len = 0,count = 1;
    len = length(first);
    if(key > len) // when given position is wrong 
    {
        printf("position is wrong\n");
        return NULL;
    }
    if(key == 1) // if length is first then 
    {
        temp->next = first; // link temp node to first and then return temp 
        return  temp;
    }
    prev = NULL;
    cur = first;
    while (cur != NULL && count != key ) { // iterate through list until count == key
        prev = cur; // key track of prev node 
        cur = cur->next;
        count++;
    }
    if(count == len) // if user wants to insert at end 
    {
        prev->next = temp;
        temp->prev = cur->prev;
        temp->next = cur;
        return first;
    }
    cur->prev = temp; // this part covers when user gives intermidate position 
    temp->next = cur;
    prev->next = temp;
    temp->prev = prev;
    return first;
}

int search(Node first, int key)
{
    int count = 0;
    if(first == NULL)
    {
        printf("List is empty\n");
        return -1;
    }
    Node cur;
    cur = first;
    while (cur != NULL ) {
        if(cur->data == key)
        {
            printf("found\n");
            return count;
        }
        cur = cur->next;
        count++;
    }
    printf("Not found\n");
    return -1;
}


Node deletion_with_given_value(Node first, int key)
{
    if (first == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    Node cur = first;
    Node prev = NULL;

    while (cur != NULL && cur->data != key) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("Data not found in the list\n");
        return first;
    }

    // If the node to be deleted is the first node
    if (prev == NULL) {
        first = cur->next;
        if (first != NULL) // Ensure we don't dereference a NULL pointer
            first->prev = NULL;
        free(cur);
        return first;
    }

    // If the node to be deleted is an intermediate node
    if (cur->next != NULL) {
        prev->next = cur->next;
        cur->next->prev = prev;
    } else {
        // If the node to be deleted is the last node
        prev->next = NULL;
    }

    free(cur);
    return first;
}

int main(int argc, char *argv[])
{
    Node first = NULL;
    int ch;
    int data;
    int len;
    int key;
    printf("1.Insert_front()\n2.Insert_rear()\n3.delete_front()\n4.delete_end\n5.length\n6.insert_intermidate\n7.insert_specific number\n8.search()\n9.deletion_with_given_value()\n10.Display\n");
    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the data that you want to insert in the front : ");
                scanf("%d",&data);
                first = insert_front(first , data);
                break;
            case 2:
                printf("Enter the data that you want to insert in the end: ");
                scanf("%d",&data);
                first = insert_rear(first , data);
                break;
            case 3:
                first = delete_front(first);
                break;
            case 4:
                first = delete_end(first);
                break;
            case 5:
                len = length(first);
                printf("Length of Doubly ll is : %d\n",len);
                break;
            case 6:
                printf("Enter the data that you want to insert at intermidate of doubly ll: ");
                scanf("%d",&data);
                first = insert_intermidate(first , data);
                break;
            case 7:
                printf("Enter the data : ");
                scanf("%d",&data);
                len = length(first);
                printf("Enter the place that you want to store this data must be >= 0 or <= %d: ",len);
                scanf("%d",&key);
                first = Insert_specific(first , data , key);
                break;
            case 8:
                printf("Enter the data that you want to search: ");
                scanf("%d",&data);
                key = search(first , data); 
                if(key != -1)
                    printf("Found at %d\n",key);
                else 
                    printf("Not found\n");
                break;
            case 9:
                printf("Enter the data that you want to delete\n");
                scanf("%d",&data);
                first = deletion_with_given_value(first , data);
                break;
            case 10:
                display(first);
                break;
            
        }
    }
}
