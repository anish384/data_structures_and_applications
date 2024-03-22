#include <stdio.h>
#include <stdlib.h>

struct poly
{
    int cf;
    int px;
};

typedef struct poly Poly;

void read_poly(Poly p[], int n)
{
    int i,cf,px;
    for(i = 0; i < n; i++)
    {
        printf("Enter cf, px: ");
        scanf("%d %d",&cf,&px);
        p[i].cf = cf;
        p[i].px = px;
    }
}

void print_poly(Poly p[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
            printf("%d",p[i].cf);
        else
            printf("+ %d ",p[i].cf);

        if(p[i].px != 0) printf("x^%d ",p[i].px);
    }
}

int search(int px1, Poly p2[], int n)
{
    for(int i= 0; i < n; i++)
    {
        if(p2[i].px == px1) return i;
    }
    return -1;
}

int copy_poly(Poly p3[], int k, Poly p2[], int n)
{
    for(int j = 0; j < n; j++)
    {
        if(p2[j].cf != -999)
        {
            p3[k].cf = p2[j].cf;
            p3[k].px = p2[j].px;
            k++;
        }
    }
    return k;
}

int add_poly(Poly p1[], int m, Poly p2[], int n, Poly p3[])
{
    int cf1,px1,pos,sum;
    int k = 0;

    for(int i = 0; i < m; i++)
    {
        cf1 = p1[i].cf;
        px1 = p1[i].px;

        pos = search(px1 , p2, n);

        if(pos >= 0)
        {
            sum = cf1 + p2[pos].cf;
            if(sum != 0) p3[k].cf = sum;
            p2[pos].cf = -999;
        }
        else{
            p3[k].cf = cf1;
        }
        p3[k].px = px1;
        k++;
    }
    k = copy_poly(p3,k,p2,n);
    return k;
}

int main(int argc, char *argv[])
{
    Poly p[5];
    Poly p2[5];
    Poly p3[5];
    read_poly(p , 3);
    read_poly(p2 , 3);
    print_poly(p , 3);
    printf("\n");
    print_poly(p2 , 3);
    printf("\n");
    int k = add_poly(p , 3 , p2 , 3 , p3);
    printf("------------------------------------------------------------\n");
    print_poly(p3 , k);
    
    return EXIT_SUCCESS;
}

