#include <stdio.h>
#include <stdlib.h>

#define max 10

typedef struct 
{
    int row;
    int col;
    int val;
}Term;

void read_sparse(Term a[], int m, int n)
{
    int k = 1;
    int item;
    a[0].row = m, a[0].col = n;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d",&item);
            if(item == 0) continue;
            a[k].row = i, a[k].col = j, a[k].val = item;
            k++;
        }
    }
    a[0].val = k - 1;
}

void transpose(Term a[], Term b[])
{
    int k = 1;

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = a[0].val;

    for(int i = 0; i < a[0].col; i++)
    {
        for(int j = 1; j <= a[0].val; j++)
        {
            if(a[j].col == i)
            {
                b[k].row = a[j].col;
                b[k].col = a[j].row;
                b[k].val = a[j].val;
                k++;
            }
        }
    }
}

void fast_transpose(Term a[], Term b[])
{
    int row_terms[max], starting_pos[max];
    int i,j;

    int num_cols = a[0].col;
    int num_terms = a[0].val;

    b[0].row = num_cols;
    b[0].col = a[0].row;
    b[0].val = num_terms;

    if(num_terms > 0)
    {
        for(int i = 0; i < num_cols; i++)
            row_terms[i] = 0;

        for(int i = 1; i <= num_terms; i++)
            row_terms[a[i].col]++;

        starting_pos[0] = 1;

        for(int i= 1; i < num_cols; i++)
            starting_pos[i] = starting_pos[i-1] + row_terms[i-1];

        for(int i = 1; i <= num_terms; i++)
        {
            j = starting_pos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].val = a[i].val;
        }
    }
}

void display_sparse(Term a[])
{
    int rows = a[0].row;
    int cols = a[0].col;
    int non_zero_count = a[0].val;
    
    printf("Rows: %d, Columns: %d\n", rows, cols);
    printf("Sparse Matrix:\n");
    printf("Row\tColumn\tValue\n");
    
    for (int i = 1; i <= non_zero_count; i++)
    {
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].val);
    }
}


int main(int argc, char *argv[])
{
    Term a[max], b[max];
    read_sparse(a, 5, 4); 
    fast_transpose(a, b); 
    display_sparse(a);
    printf("\n");
    display_sparse(b);
    return EXIT_SUCCESS;
}

/* 
 * Output :
 * 
10 0 0 40
11 0 22 0
0 0 0 0
20 0 0 50
0 15 0 25
Rows: 5, Columns: 4
Sparse Matrix:
Row     Column  Value
0       0       10
0       3       40
1       0       11
1       2       22
3       0       20
3       3       50
4       1       15
4       3       25

Rows: 4, Columns: 5
Sparse Matrix:
Row     Column  Value
0       0       10
0       1       11
0       3       20
1       4       15
2       1       22
3       0       40
3       3       50
3       4       25
* 
* 
*/
