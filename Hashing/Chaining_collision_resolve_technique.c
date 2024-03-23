#include <stdio.h>
#include <stdlib.h>
#define HASH_SIZE 5
struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;

NODE getnode()
{
    NODE x;
    x = (NODE) malloc(sizeof(struct node));
    if(x == NULL)
    {
        printf("Out of memory\n");
        exit(0);
    }
    return x;
}

NODE insert_rear(int item, NODE first)
{
    NODE temp; /* Points to newly created node */
    NODE cur; /* To hold the address of the last node */
    temp = getnode(); /* Obtain a new node and copy the item */
    temp->info = item; 
    temp->link = NULL;
    /* If list is empty return new node as the first node*/
    if ( first == NULL ) return temp; 
    /* If list exists, obtain address of the last node */ 
    cur = first;
    while ( cur->link != NULL )
    {
        cur = cur->link;
    }
    cur->link = temp; /* Insert the node at the end */ 
    return first; /* return address of the first node */ 
}

NODE search(int key, NODE first)
{
    NODE cur;
    if ( first == NULL ) return NULL; /* Search for empty list */
    /* Compare one after the other */
    cur = first;
    while (cur != NULL) /* As long as no end of list */
    {
        if (key == cur->info) return cur; /* If found go out of the loop */
        cur = cur->link; /* point cur to the next node */
    }
    return NULL; /* key not found */
}

int H(int k)
{
    return k % HASH_SIZE;
}

void insert_hash_table (int item, NODE a[])
{
    int h_value;
    h_value = H(item);
    a[h_value] = insert_rear (item, a[h_value]);
}

int search_hash_table (int key, NODE a[])
{
    int h_value;
    NODE cur;
    h_value = H(key); // Find the hash value
    cur = search(key, a[h_value]); // Obtain address of searched node
    if (cur == NULL) return 0; // Key not found in the list
    return 1; // Key found in the list
}

void display_hash_table (NODE a[])
{
    int i;
    NODE temp;
    for (i = 0; i < HASH_SIZE; i++)
    {
        printf("a[%d] = ", i);
        temp = a[i];
        if (temp == NULL)
            printf("NULL\n");
        else
        {
            temp = a[i];
            while (temp->link != NULL)
            {
                printf("%d -->", temp->info);
                temp = temp->link;
            }
            printf("%d\n", temp->info);
        }
    }
}

int main()
{
    NODE a[10];
    int item, key, choice, flag, i;
    for ( i = 0; i < HASH_SIZE; i++) a[i] = NULL; // Create initial hash table
    printf("1: Insert 2: Search\n");
    printf("3: Display 4: Exit\n");
    for (; ;){
        printf("Enter the choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the item : "); scanf("%d", &item);
                insert_hash_table(item, a);
                break;
            case 2: 
                printf("Enter key item : "); scanf("%d", &key);
                flag = search_hash_table (key, a);
                if (flag == 0)
                    printf("Key not found\n");
                else
                    printf("Key found\n");
                break;
            case 3: 
                printf("Contents of hash table\n");
                display_hash_table(a);
                printf("\n");
                break;
            default: 
                exit(0);
        }
    }
}
