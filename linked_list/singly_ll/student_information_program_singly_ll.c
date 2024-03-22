#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;

struct student
{
    int usn;
    char name[20], field[20];
    int sem;
};

struct node{
    struct student s;
    struct node* link;
};

typedef struct node* Node;

Node create()
{    
    int usn;
    char name[20], field[20];
    int sem;

    printf("Enter the usn: ");
    scanf("%d",&usn);
    printf("Enter the name: ");
    scanf("%s",name);
    printf("Enter the field he is in: ");
    scanf("%s",field);
    printf("Enter the sem he is in: ");
    scanf("%d",&sem);

    Node temp;
    temp = (Node)malloc(sizeof(struct node));
    temp->s.usn = usn;
    temp->s.sem = sem;
    strcpy(temp->s.name, name);
    strcpy(temp->s.field, field);
    temp->link = NULL;
    count++;
    return temp;
}

Node insert_front(Node head)
{
    if(head == NULL)
    {
        head = create();
        return head;
    }
    Node temp;
    temp = create();

    temp->link = head;
    return temp;
}

Node insert_rear(Node head)
{
    if(head == NULL)
    {
        head = create();
        return head;
    }
    Node temp,cur;
    temp = create();
    cur = head;
    while (cur->link != NULL ) {
        cur = cur->link;
    }

    cur->link = temp;
    return head;
}

Node delete_front(Node head)
{
    if(head == NULL)
    {
        printf("List is empty Deletion can't be performed\n");
        return NULL;
    }

    Node cur;
    cur = head->link;
    printf("delete_front(): %d deleted\n",head->s.usn);  
    free(head);
    count--;
    return cur;
}

Node delete_rear(Node head)
{
    if(head == NULL)
    {
        printf("List is empty Deletion can't be performed\n");
        return NULL;
    }

    Node prev, cur;
    prev = NULL;
    cur = head;
    while (cur->link != NULL ) {
        prev = cur;
        cur = cur->link;
    }
    
    prev->link = NULL;
    printf("delete_rear(): %d usn deleted\n",cur->s.usn);
    free(cur);
    count--;
    return head;
}

void display(Node head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node cur;
    cur = head;
    while (cur != NULL ) {
        printf("%d %s %s %d\n",cur->s.usn,cur->s.name,cur->s.field,cur->s.sem);
        cur = cur->link;
    }
    printf("Total no of student are %d\n",count);
}

int main(int argc, char *argv[])
{
    Node head = NULL;
    int choice;
    printf("1.Insert front\n2.Insert rear\n3.Delete front\n4.Delete rear\n5.Display\n6.Exit\n");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                head = insert_front(head);
                break;
            case 2:
                head = insert_rear(head);
                break;
            case 3:
                head = delete_front(head);
                break;
            case 4:
                head = delete_rear(head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Wrong option\n");
                break;
        }
        
    } 
}

