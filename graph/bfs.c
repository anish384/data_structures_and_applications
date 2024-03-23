#include <stdio.h>
#include <stdlib.h>

int n, a[20][20], visited1[20], visited2[20], source;

void read_data()
{
    printf("Enter the of nodes: ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix: \n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}

void print_data(int visited[])
{
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
            printf("\n%d vertex is not reachable\n",i);
        else 
            printf("\n%d vertex is reachable\n",i);
    }
}

void bfs()
{
    int i,j, f = 0, r = 0, q[20];

    q[r] = source;
    visited1[source] = 1;
    while(f <= r)
    {
        i = q[f++];
        printf("--%d--",i);
        for(j = 0; j < n; j++)
        {
            if(a[i][j] == 1 && visited1[j] == 0)
            {
                q[++r] = j;
                visited1[j] = 1;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    source = 1;
    read_data();
    bfs();
    print_data(visited1);
    return EXIT_SUCCESS;
}
