#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
}*header1=NULL,*header2=NULL,*header3=NULL;
void createList(struct node*header)
{
    int x,i=1;
    scanf("%d",&x);
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->next=NULL;
    header->next=new;
    struct node *temp=new;
    while(1)
    {
        scanf("%d",&x);
        if(x==-999){break;}
        struct node* new=(struct node*)malloc(sizeof(struct node));
        new->data=x;
        new->next=NULL;
        temp->next=new;
        temp=new;
    }
}
void addtomerge(int value)
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=value;
    new->next=NULL;
    if(header3->next==NULL){header3->next=new;}
    else
    {
        struct node *temp=header3;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new; //append at end 
    }
}
void merger()
{
    //add even numbers from first ll
    struct node* ptr=header1->next;
    while(ptr!=NULL)
    {
        if(ptr->data%2==0)
        {
            addtomerge(ptr->data);
        }
        ptr=ptr->next;
    }
    //add even numbers from second LL
    ptr=header2->next;
    while(ptr!=NULL)
    {
        if(ptr->data%2==0)
        {
            addtomerge(ptr->data);
        }
        ptr=ptr->next;
    }
    //add odd numbers from first LL
    ptr=header1->next;
    while(ptr!=NULL)
    {
        if(ptr->data%2!=0)
        {
            addtomerge(ptr->data);
        }
        ptr=ptr->next;
    }
    //add odd numbers from second LL
    ptr=header2->next;
    while(ptr!=NULL)
    {
        if(ptr->data%2!=0)
        {
            addtomerge(ptr->data);
        }
        ptr=ptr->next;
    }
}
void display(struct node *header)
{
    struct node *ptr=header->next;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
void main()
{
    header1=(struct node*)malloc(sizeof(struct node));
    header1->data=0;header1->next=NULL;
    header2=(struct node*)malloc(sizeof(struct node));
    header2->data=0;header2->next=NULL;
    header3=(struct node*)malloc(sizeof(struct node));
    header3->data=0;header3->next=NULL;
    printf("Input the numbers to build the first list. Stop your input with -999\n");
    createList(header1);
    printf("Input the numbers to build the second list. Stop your input with -999\n");
    createList(header2);
    printf("List1 is\n");
    display(header1);
    printf("List2 is\n");
    display(header2);
    merger();
    printf("The merged list is\n");
    display(header3);
}