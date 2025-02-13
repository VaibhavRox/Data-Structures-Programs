#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
}*header=NULL;
void createList(struct node* header)
{
    int x;
    printf("Input the numbers to build a list. Stop your input with -999\n");
    scanf("%d",&x);
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->next=NULL;
    header->next=new;
    struct node *temp=new;
    while(1)
    {
        scanf("%d",&x);
        if(x==-999){break;}
        struct node *new=(struct node*)malloc(sizeof(struct node));
        new->data=x;
        new->next=NULL;
        temp->next=new;
        temp=new;
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
void removeOutofOrder()
{
    if(header==NULL||header->next==NULL)
    {
        printf("List has no out of order elements to remove!!\n");
        return;
    }
    struct node *curr=header->next;
    while(curr!=NULL && curr->next!=NULL)
    {
        if(curr->next->data<curr->data)
        {
            struct node * temp=curr->next;
            curr->next=temp->next;
            free(temp);
        }
        else
        {
            curr=curr->next;
        }
    }
}
void main()
{
    header=(struct node*)malloc(sizeof(struct node));
    header->data=0;header->next=NULL;
    createList(header);
    printf("Original list is\n");
    display(header);
    removeOutofOrder();
    printf("The list after removing out of order elements is\n");
    display(header);   
}