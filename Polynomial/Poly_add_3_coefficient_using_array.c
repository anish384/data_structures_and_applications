#include <stdio.h>
#include <stdlib.h>

struct poly
{
    int cf,px,py,pz;
};

typedef struct poly Poly;

void read_poly(Poly p[], int n)
{
    int cf,px,py,pz;
    for(int i = 0; i < n; i++)
    {
        printf("Enter the cf, px, py, pz: ");
        scanf("%d %d %d %d",&cf,&px,&py,&pz);
        p[i].cf = cf;
        p[i].px = px;
        p[i].py = py;
        p[i].pz = pz;
    }
}

void print_poly(Poly p[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
            printf("%d x^%d y^%d z^%d  ",p[i].cf,p[i].px,p[i].py,p[i].pz);
        else 
            printf("+ %d x^%d y^%d z^%d  ",p[i].cf,p[i].px,p[i].py,p[i].pz);
    }
}

int search(int px1, int py1, int pz1, Poly p2[], int n)
{
    for(int i= 0; i < n; i++)
    {
        if(px1 == p2[i].px &&py1 == p2[i].py &&pz1 == p2[i].pz)
            return i;
    }
    return -1;
}

int copy(Poly p3[], int k, Poly p2[], int n)
{
    for(int i = 0; i < n ;i++)
    {
        if(p2[i].cf != -999)
        {
            p3[k].cf = p2[i].cf;
            p3[k].px = p2[i].px;
            p3[k].py = p2[i].py;
            p3[k].pz = p2[i].pz;
        }
    }
    return k;
}

int add_poly(Poly p1[], int m, Poly p2[], int n, Poly p3[])
{
    int k = 0,pos,sum;
    for(int i = 0; i < m; i++)
    {
        pos = search(p1[i].px, p1[i].py, p1[i].pz, p2 , n);
        if(pos >= 0)
        {
            sum = p1[i].cf + p2[pos].cf;
            p3[k].cf = sum;
            p2[pos].cf = -999;
        }
        else{
            p3[k].cf = p1[i].cf;
        }
        p3[k].px = p1[i].px;
        p3[k].py = p1[i].py;
        p3[k].pz = p1[i].pz;
        k++;
    }
    k = copy(p3 , k , p2 , n);
    return k;
}

int main(int argc, char *argv[])
{
    Poly p[5];
    Poly p2[5];
    Poly p3[5];
    read_poly(p , 2);
    read_poly(p2 , 2);
    print_poly(p, 2);
    printf("\n");
    print_poly(p2 , 2);
    int k = add_poly(p , 2 , p2 , 2 , p3);
    print_poly(p3 , k);
    return EXIT_SUCCESS;
}

