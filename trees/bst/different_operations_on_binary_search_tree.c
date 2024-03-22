#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

typedef struct node* Node;

int node_count = 0;
int leaf_count = 0;

Node getnode()
{
    Node x;
    x = (Node)malloc(sizeof(struct node));
    if(x == NULL)
    {
        printf("Allocation failure\n");
        exit(0);
    }
    return x;
}

void preorder(Node first)
{
    if(first != NULL)
    {
        printf("%d ",first->data);
        preorder(first->left);
        preorder(first->right);
    }
}

void postorder(Node first)
{
    if(first != NULL)
    {
        postorder(first->left);
        postorder(first->right);
        printf("%d ",first->data);
    }
}

void inorder(Node first)
{
    if(first != NULL)
    {
        inorder(first->left);
        printf("%d ",first->data);
        inorder(first->right);
    }
}

// printing the data of tree in tree form
void display_tree(Node first, int level)
{
    int i;
    if(first == NULL)
    {
        return;
    }

    display_tree(first->right, level - 1);
    for(i = 0; i < level; i++) printf(" ");
    printf("%d\n",first->data);
    display_tree(first->left, level-1);
}

// printing data of tree in level order 
void level_order(Node first)
{
    Node q[40],cur;
    int f = 0, r = -1;

    q[++r] = first;

    while(f <= r)
    {
        cur = q[f++];
        printf("%d ",cur->data);

        if(cur->left != NULL)
            q[++r] = cur->left;
        if(cur->right != NULL)
            q[++r] = cur->right;
    }
    printf("\n");
}

Node insert_da(Node first, int data)
{
    Node temp,cur,prev;
    temp = getnode();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if(first == NULL)
        return temp;
    
    prev = NULL;
    cur = first;

    while (cur != NULL ) {
        prev = cur;
        if(data < cur->data)
            cur = cur->left;
        else 
            cur = cur->right;
    }

    if(data < prev->data)
        prev->left = temp;
    else 
        prev->right = temp;
    return first; 
}

Node insert_dx(Node first, int data)
{
    Node temp, cur, prev;
    temp = getnode();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if(first == NULL)
        return temp;

    prev = NULL;
    cur = first;

    while(cur != NULL)
    {
        prev = cur;
        if(cur->data == data)
        {
            printf("Duplicate elements are not allowed\n");
            free(temp);
            return first;
        }
        if(data < cur->data)
            cur = cur->left;
        else 
            cur = cur->right;
    }

    if(data < prev->data)
        prev->left = temp;
    else 
        prev->right = temp;
    return first;
}

void search(Node first, int key)
{
    if(first == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    Node cur = first;
    while(cur != NULL)
    {
        if(cur->data == key){
            printf("Found\n");
            return;
        }     
        if(key < cur->data)
            cur = cur->left;
        else 
            cur = cur->right;
    }
    printf("Not found\n"); 
}

void max(Node first)
{
    if(first == NULL)
    {
        printf("List is empty");
        return ;
    }
    Node cur = first;
    while (cur->right != NULL ) {
        cur = cur->right;
    }
    printf("max in tree: %d\n",cur->data);
}

void min(Node first)
{
    if(first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node cur = first;
    while(cur->left != NULL){
        cur = cur->left; 
    }
    printf("Min in tree: %d\n",cur->data);
}

int height(Node first)
{
    if(first == NULL) return 0;
    else 
    {
        int left_side = height(first->left);
        int right_side = height(first->right);
        if(left_side> right_side)
            return left_side + 1;
        else 
            return right_side + 1;
    }
}

void count_node(Node first)
{
    if(first == NULL) return;
    count_node(first->left);
    node_count++;
    count_node(first->right);
}

void count_leaf(Node root)
{
if ( root == NULL ) return ;
 count_leaf(root->left); /* Traverse recursively towards left */
/* if a node has empty left and empty right child ? */
 if (root->left == NULL && root->right == NULL ) leaf_count++;
 count_leaf(root->right); /* Traverse recursively towards right */
}

Node delete_item(int item, Node root)
{
    Node cur, parent, suc, q;
    if (root == NULL)
    {
        printf("Tree is empty! Item not found\n");
        return root;
    }
    parent = NULL;
    cur = root; /* obtain node to be deleted, its parent */
    while (cur != NULL)
    {
        if (item == cur->data) 
            break;
        parent = cur;
        if (item < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if (cur == NULL)
    {
        printf("Item not found\n");
        return root;
    }
    /* Item found and delete it */
    /* CASE 1 */
    if (cur->left == NULL) /* If left subtree is empty */
        q = cur->right; /* obtain non-empty right subtree */
    else if (cur->right == NULL) /* If right subtree is empty */
        q = cur->left; /* obtain non-empty left subtree */
    else
    { /* CASE 2 */
        suc = cur->right; /* obtain the inorder successor */
        while (suc->left != NULL)
            suc = suc->left;
        suc->left = cur->left; /* Attach left of node to be deleted to */
                               /* left of successor of node to be deleted */
        q = cur->right;        /* Right subtree is obtained */
    }
    if (parent == NULL) 
        return q; /* If parent does not exist return q as root */
    /* connecting parent of the node to be deleted to q */
    if (cur == parent->left)
        parent->left = q;
    else
        parent->right = q;
    free(cur);
    return root;
}

void iter_preorder(Node root)
{
    Node cur, s[20];
    int top = -1;
    
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    
    cur = root;
    
    for (;;)
    {
        while (cur != NULL)
        {
            printf("%d ", cur->data); /* Visit the node */
            s[++top] = cur; /* push(cur, &top, s) */
            cur = cur->left; /* traverse left */
        }
        
        if (top != -1) /* If stack is not empty */
        {
            cur = s[top--]; /* Obtain the recent node from the stack */
            cur = cur->right; /* traverse right */
        }
        else
            return;
    }
}

void iter_inorder(Node root)
{
    Node cur, s[20];
    int top = -1;
    
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    
    cur = root;
    
    for (;;)
    {
        while (cur != NULL)
        {
            s[++top] = cur; /* push(cur,&top,s); */
            cur = cur->left; /* traverse left */
        }
        
        if (top != -1) /* If stack not empty */
        {
            cur = s[top--]; /* Remove recent node from stack */
            printf("%d ", cur->data); /* visit node */
            cur = cur->right; /* traverse right */
        }
        else
            return;
    }
}

void iter_postorder(Node root)
{
    struct stack
    {
        Node address;
        int flag;
    };
    
    Node cur;
    struct stack s[20];
    int top = -1;
    
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    
    cur = root;
    
    for (;;)
    {
        while (cur != NULL)
        {
            top++;
            s[top].address = cur; /* push(cur,&top,s) */
            s[top].flag = 1;
            cur = cur->left; /* traverse left */
        }
        
        /* -ve values on stack indicate right subtree is
         * traversed and the node can be visited
         */
        while (s[top].flag < 0)
        {
            cur = s[top].address; /* cur = pop(&top,s); */
            top--;
            printf("%d ", cur->data); /* visit the node */
            
            if (top == -1)
                return;
        }
        
        /* Ascend to traverse the right subtree */
        cur = s[top].address; /* cur = pop(&top,s); */
        cur = cur->right;
        s[top].flag = -1; /* -ve indicates right subtree is traversed */
    }
}



int main(int argc, char *argv[])
{
    Node first = NULL;
    printf("************************* Binary Search Tree *************************\n");
    printf("1.Insert(duplicate are allowed)\n2.Insert(duplicate are now allowed)\n3.Search\n4.find max\n5.find minimun\n6.find the height of bst\n7.count the nodes of bst\n8.count the leaf nodes of bst\n9.delete an item from bst\n10.inorder(iter)\n11.postorder(iter)\n12.preorder(iter)\n13.inorder(recur)\n14.postorder(recur)\n15.preorder(recur)\n16.print in level order\n17.Display in tree form\n");
    int ch, data;
    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the data (duplicate are allowed): ");
                scanf("%d",&data);
                first = insert_da(first , data); 
                break;
            case 2:
                printf("Enter the data (duplicate are now allowed): ");
                scanf("%d",&data);
                first = insert_dx(first , data); 
                break;
            case 3:
                printf("Enter the search element: ");
                scanf("%d",&data);
                search(first , data);
                break;
            case 4:
                max(first);       
                break;
            case 5:
                min(first);
                break;
            case 6:
                data = height(first);
                printf("Height of tree: %d\n",data);
                break;
            case 7:
                count_node(first);
                break;
            case 8:
                count_leaf(first);
                break;
            case 9:
                printf("Enter the data that you want to delete\n");
                scanf("%d",&data);
                first = delete_item(data , first);
                break;
            case 10:
                iter_inorder(first);
                printf("\n");
                break;
            case 11:
                iter_postorder(first);
                printf("\n");
                break;
            case 12:
                iter_preorder(first);
                printf("\n");
                break;
            case 13:
                inorder(first);
                printf("\n");
                break;
            case 14:
                preorder(first);
                printf("\n");
                break;
            case 15:
                postorder(first);
                printf("\n");
                break;
            case 16:
                level_order(first);
                printf("\n");
                break;
            case 17:
                printf("Enter the level : ");
                scanf("%d",&data);
                display_tree(first , data); 
                printf("\n");
                break;
            case 18:
                exit(0);
                break;
            default:
                printf("Wrong choice\n");
                break;
        }
    }
}
