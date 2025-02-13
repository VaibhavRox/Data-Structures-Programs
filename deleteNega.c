#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*header=NULL;
void createList(struct node*header)
{
    int x;
    printf("Enter the integers,enter-999 to stop entering");
    scanf("%d",&x);
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->next=NULL;
    header->next=new;
    struct node*temp=new;
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
void deleteNode(struct node *head,int key)
{
    struct node*ptr=head->next;
    struct node *temp=NULL;
    if(ptr->data==key)
    {
        head->next=ptr->next;
        free(ptr);
        return;
    }
    while(ptr!=NULL && ptr->data!=key)
    {
        temp=ptr;
        ptr=ptr->next;
    }
    if(ptr==NULL){printf("Key not found\n");return;}
    else
    {
        temp->next=ptr->next;
        free(ptr);
    }
}
void deleteNega(struct node*head)
{
    struct node*ptr=head->next;
    while(ptr!=NULL)
    {
        if(ptr->data<0)
        {
            deleteNode(head,ptr->data);
            ptr=head->next;
        }
        else
        {
            ptr=ptr->next;
        }
    }
}
void display(struct node *head)
{
    struct node *ptr=head->next;
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}
void main()
{
    header=(struct node*)malloc(sizeof(struct node));
    header->data=0;header->next=NULL;
    createList(header);
    display(header);
    printf("After removing negative elements:\n");
    deleteNega(header);
    display(header);
}