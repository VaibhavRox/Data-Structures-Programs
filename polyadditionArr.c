#include <stdio.h>
#include <stdlib.h>
struct Poly
{
    int expo,coeff;
}p1[10],p2[10],p3[20];
int add(struct Poly p1[],struct  Poly p2[],struct Poly p3[],int t1,int t2)
{
    int i=0,j=0,k=0;
    while(i<t1 && j<t2)
    {
        if(p1[i].expo==p2[j].expo)
        {
            p3[k].coeff=p1[i].coeff+p2[j].coeff;
            p3[k].expo=p1[i].expo;
            i++;j++;k++;
        }
        else if(p1[i].expo>p2[j].expo)
        {
            p3[k].coeff=p1[i].coeff;
            p3[k].expo=p1[i].expo;
            i++;k++;
        }
        else
        {
            p3[k].coeff=p2[j].coeff;
            p3[k].expo=p2[j].expo;
            j++;k++;
        }
    }
    //add leftover terms
    while(i<t1)
    {
        p3[k].coeff=p1[i].coeff;
        p3[k].expo=p1[i].expo;
        i++;k++;
    }
    while(j<t2)
    {
        p3[k].coeff=p2[j].coeff;
        p3[k].expo=p2[j].expo;
        j++;k++;
    }
    return k;
}
int read(struct Poly p[])
{
    int t;
    printf("Enter the number of terms:");
    scanf("%d",&t);
    printf("Enter the polynomial:\n");
    for(int i=0;i<t;i++)
    {
        printf("Coefficient:");
        scanf("%d",&p[i].coeff);
        printf("Exponent:");
        scanf("%d",&p[i].expo);
    }
    return t;
}
void display(struct Poly p[],int t)
{
    int i;
    for(i=0;i<t-1;i++)
    {
        printf("%dx^%d+",p[i].coeff,p[i].expo);
    }
    printf("%dx^%d",p[i].coeff,p[i].expo);
}
void main()
{
    int t1,t2,t3;
    printf("----------------------Polynomial Addition using arrays--------------------------\n");
    printf("First Polynomial\n");
    t1=read(p1);
    display(p1,t1);
    t2=read(p2);
    display(p2,t2);
    printf("Addition result\n");
    t3=add(p1,p2,p3,t1,t2);
    display(p3,t3);
}