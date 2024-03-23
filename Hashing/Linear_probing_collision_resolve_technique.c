/* hashing */

#include <stdio.h>
#include <stdlib.h>

#define hash_size 5

void initialize_hash_table(int a[])
{
    int i;
    for(i = 0; i < hash_size; i++) a[i] = 0;
}

int H(int k)
{
    return k % hash_size; 
}

void insert_hash_table(int a[], int item)
{
    int i, index, h_value;
    h_value = H(item);
    for(i = 0; i < hash_size; i++)
    {
        index = (h_value + i) % hash_size;
        if(a[index] == 0) break; // empty slot found;
    }

    if(a[index] == 0) a[index] = item;
    else printf("hash table is full\n");
}

int search_hash_table(int key, int a[])
{
    int i,index, h_value;
    h_value = H(key);
    for(i = 0; i < hash_size; i++)
    {
        index = (h_value + i) % hash_size;
        if(key == a[index]) return 1;
        if(a[index] == 0) return 0;
    }
    // if(i == hash_size) 
    //     return 0;
    return 0;
}

void display_array(int a[], int n)
{
    int i;
    for (int i= 0; i < n ; i++) {
        printf("%d ",a[i]);
    }
}

int main(int argc, char *argv[])
{
    int a[10], item, key, choice, flag;
    initialize_hash_table(a);
    printf("1: Insert\n2: Search\n3: Display\n4: Exit\n");
    for(;;)
    {
        printf("Enter choice\n");
        scanf("%d",&choice);
        switch (choice ) {
            case 1: 
                printf("Enter item: ");
                scanf("%d",&item);
                insert_hash_table(a, item);
                break;
            case 2:
                printf("Enter key item: ");
                scanf("%d",&key);
                flag = search_hash_table(key , a);
                if(flag == 0) printf("Not found\n");
                else printf("Found\n");
                break;
            case 3:
                printf("containts of hash table\n");
                display_array(a, hash_size);
                printf("\n");
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}
