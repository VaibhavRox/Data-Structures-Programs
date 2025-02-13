#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *next;
}*header1=NULL,*header2=NULL;
int n1,n2;
struct node *createNode(int data)
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    return new;
}
void createList(int n,struct node* header)
{
    int x;
    struct node*new=(struct node*)malloc(sizeof(struct node));
    printf("Enter data of node 1:");
    scanf("%d",&x);
    new->data=x;
    new->next=NULL;
    header->next=new;
    struct node*temp=new;
    for(int i=2;i<n+1;i++)
    {
        struct node *new=(struct node*)malloc(sizeof(struct node));
        printf("Enter data of node %d:",i);
        scanf("%d",&x);
        new->data=x;
        new->next=NULL;
        temp->next=new;
        temp=new;
    }
}
void merger(int n1,int n2)
{
    struct node *ptr=NULL;
    if(n1>n2)
    {
        ptr=header1->next;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=header2->next;
    }
    else
    {
        ptr=header2->next;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=header1->next;
    }
}
void display(struct node *header)
{
    struct node *ptr=header->next;
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}
void displaymerger()
{
    struct node*ptr=NULL;
    if(n1>n2)
    {
        ptr=header1->next;
        while(ptr!=NULL)
        {
            printf("%d->",ptr->data);
            ptr=ptr->next;
        }
        printf("NULL\n");
    }
    else
    {
        ptr=header2->next;
        while(ptr!=NULL)
        {
            printf("%d->",ptr->data);
            ptr=ptr->next;
        }
        printf("NULL\n");
    }
}
void main()
{
    header1=(struct node*)malloc(sizeof(struct node));
    header1->data=0;
    header1->next=NULL;
    header2=(struct node*)malloc(sizeof(struct node));
    header2->data=0;
    header2->next=NULL;
    printf("Enter the number of nodes in first linked list:");
    scanf("%d",&n1);
    createList(n1,header1);
    printf("Enter the number of nodes in second linked list:");
    scanf("%d",&n2);
    createList(n2,header2);
    printf("First LL\n");
    display(header1);
    printf("Second LL\n");
    display(header2);
    printf("Merging the smaller LL to end of the larger LL\n");
    merger(n1,n2);
    displaymerger();
    
    
}