#include <stdio.h>
#include <stdlib.h>
struct Poly
{
        int coeff,exp;
        struct Poly *next;
}*Rheader=NULL,*Pheader=NULL,*Qheader=NULL;
void readPoly(struct Poly **p,int t)
{
    struct Poly *new=NULL,*ptr=NULL;
    *p=(struct Poly*)malloc(sizeof(struct Poly));
    ptr=*p;
    for (int i=0;i<t;i++)
    {
        new=(struct Poly*)malloc(sizeof(struct Poly));
        printf("Enter the Coeff:");
        scanf("%d",&new->coeff);
        printf("Enter the Exponent:");
        scanf("%d",&new->exp);
        new->next=NULL;
        ptr->next=new;
        ptr=new;
    }
}
void multiply()
{
    struct Poly *new,*Rptr,*Qptr,*Pptr,*ptr;
    Pptr=Pheader->next;
    Qptr=Qheader->next;
    Rheader=(struct Poly*)malloc(sizeof(struct Poly));
    Rheader->next=NULL;
    while(Pptr!=NULL)
    {
        Qptr=Qheader->next;
        while(Qptr!=NULL)
        {
            struct Poly *new=(struct Poly*)malloc(sizeof(struct Poly));
            new->coeff=Pptr->coeff*Qptr->coeff;
            new->exp=Pptr->exp+Qptr->exp;
            new->next=NULL;
            if(Rheader->next==NULL)
            {Rheader->next=new;}
            else
            {
                Rptr=Rheader->next;
                ptr=NULL;
                while(Rptr!=NULL && Rptr->exp>new->exp)
                {
                    ptr=Rptr;
                    Rptr=Rptr->next;
                }
                if(Rptr!=NULL && Rptr->exp==new->exp)
                {
                    Rptr->coeff=Rptr->coeff+new->coeff;
                    free(new);
                }
                else
                {
                    if(ptr==NULL)
                    {
                        new->next=Rheader->next;
                        Rheader->next=new;
                    }
                    else
                    {
                        new->next=ptr->next;
                        ptr->next=new;
                    }
                }
            }
            Qptr=Qptr->next;
        }
        Pptr=Pptr->next;
    }
}
void displayPoly(struct Poly *p)
{
    struct Poly *ptr;
    ptr=p->next;
    while(ptr->next!=NULL)
    {
        printf("%dx^%d+",ptr->coeff,ptr->exp);
        ptr=ptr->next;
    }
    printf("%dx^%d",ptr->coeff,ptr->exp);
    printf("\n");
}
void main()
{
    int t1,t2;
    printf("Enter number of terms in frist polynomial:");
    scanf("%d",&t1);
    readPoly(&Pheader,t1);
    displayPoly(Pheader);
    printf("Enter number of terms in second polynomial:");
    scanf("%d",&t2);
    readPoly(&Qheader,t2);
    displayPoly(Qheader);
    multiply();
    printf("The result Polynomial is:\n");
    displayPoly(Rheader);
}