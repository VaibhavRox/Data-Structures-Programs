#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff,px,py;
    struct node *next;
}*Pheader=NULL,*Qheader=NULL,*Rheader=NULL;
struct node *createNode(int coeff,int px,int py)
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->coeff=coeff;
    new->px=px;
    new->py=py;
    new->next=NULL;
    return new;
}
//function to insert node at end of list
void insertNode(struct node **head,int coeff,int px,int py)
{
    struct node* new=createNode(coeff,px,py);
    if(*head==NULL)
    {
        *head=new;
    }
    else
    {
        struct node *temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
    }
}
void readPoly(struct node **poly)
{
    int t;
    printf("Enter the number of terms in polynomial:");
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int coeff,px,py;
        printf("Enter coefficient, power of x and power of y for term %d:",i+1);
        scanf("%d %d %d",&coeff,&px,&py);
        insertNode(poly,coeff,px,py);
    }
}
void addPoly()
{
    struct node *p=Pheader;
    struct node *q=Qheader;
    while(p!=NULL && q!=NULL)
    {
        if(p->px==q->px && p->py==q->py)
        {
            int coefsum=p->coeff+q->coeff;
            if(coefsum!=0)
            {
                insertNode(&Rheader,coefsum,p->px,p->py);
            }
            p=p->next;
            q=q->next;
        }
        else if(p->px>q->px || (p->px==q->px && p->py>q->py))
        {
            insertNode(&Rheader,p->coeff,p->px,p->py);
            p=p->next;
        }
        else
        {
            insertNode(&Rheader,q->coeff,q->px,q->py);
            q=q->next;
        }
    }
    //add remaining terms
    while(p!=NULL)
    {
        insertNode(&Rheader,p->coeff,p->px,p->py);
        p=p->next;
    }
    while(q!=NULL)
    {
        insertNode(&Rheader,q->coeff,q->px,q->py);
        q=q->next;
    }
}
void display(struct node *poly)
{
    struct node *ptr=poly;
    while(ptr->next!=NULL)
    {
        printf("%dx^%dy^%d+",ptr->coeff,ptr->px,ptr->py);
        ptr=ptr->next;
    }
    printf("%dx^%dy^%d",ptr->coeff,ptr->px,ptr->py);
    printf("\n");
}
void main()
{
    printf("Enter first polynomial:\n");
    readPoly(&Pheader);
    printf("Enter second polynomial:\n");
    readPoly(&Qheader);
    addPoly();
    printf("First polynomial: ");
    display(Pheader);
    printf("Second Polynomial: ");
    display(Qheader);
    printf("Result :");
    display(Rheader);

}