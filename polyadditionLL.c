#include<stdio.h>
#include<stdlib.h>
struct node
{
    int expo,coeff;
    struct node *next;
}*Rheader=NULL,*Qheader=NULL,*Pheader=NULL;
void readPoly(struct node **p,int t)
{
    struct node *ptr=NULL;
    *p=(struct node*)malloc(sizeof(struct node));
    ptr=*p;
    for(int i=0;i<t;i++)
    {
        struct node *new=(struct node*)malloc(sizeof(struct node));
        printf("Coefficient:");
        scanf("%d",&new->coeff);
        printf("Exponent:");
        scanf("%d",&new->expo);
        new->next=NULL;
        ptr->next=new;
        ptr=new;
    }
}
void addPoly()
{
    struct node *Pptr,*Qptr,*Rptr,*new,*ptr;
    Pptr=Pheader->next;
    Qptr=Qheader->next;
    Rheader=(struct node*)malloc(sizeof(struct node));
    Rptr=Rheader;
    Rptr->next=NULL;
    while(Pptr!=NULL && Qptr!=NULL)
    {
        struct node*new=(struct node*)malloc(sizeof(struct node));
        if(Pptr->expo==Qptr->expo)
        {
            new->coeff=Pptr->coeff+Qptr->coeff;
            new->expo=Pptr->expo;
            Pptr=Pptr->next;Qptr=Qptr->next;
        }
        else if(Pptr->expo>Qptr->expo)
        {
            new->coeff=Pptr->coeff;
            new->expo=Pptr->expo;
            Pptr=Pptr->next;
        }
        else
        {
            new->coeff=Qptr->coeff;
            new->expo=Qptr->expo;
            Qptr=Qptr->next;
        }
        new->next=NULL;
        Rptr->next=new;
        Rptr=new;
    }
    while(Pptr!=NULL)
    {
        struct node *new=(struct node*)malloc(sizeof(struct node));
        new->coeff=Pptr->coeff;
        new->expo=Pptr->expo;
        new->next=NULL;
        Rptr->next=new;
        Rptr=new;
        Pptr=Pptr->next;
    }
    while(Qptr!=NULL)
    {
        struct node *new=(struct node*)malloc(sizeof(struct node));
        new->coeff=Qptr->coeff;
        new->expo=Qptr->expo;
        new->next=NULL;
        Rptr->next=new;
        Rptr=new;
        Qptr=Qptr->next;
    }
}
void displayPoly(struct node *p)
{
    struct node *ptr;
    ptr=p->next;
    while(ptr->next!=NULL)
    {
        printf("%dx^%d+",ptr->coeff,ptr->expo);
        ptr=ptr->next;
    }
    printf("%dx^%d",ptr->coeff,ptr->expo);
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
    addPoly();
    printf("The result Polynomial is:\n");
    displayPoly(Rheader);
}