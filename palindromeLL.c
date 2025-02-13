#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next,*prev;
}*header=NULL;
void display()
{
    struct node*ptr=header->next;
    while(ptr!=NULL)
    {
        printf("%c",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
int palindrome()
{
    int flag=1,l=0,r=0;
    struct node*left=header->next;
    struct node*right=header->next;
    while(right->next!=NULL)
    {
        right=right->next;
        r++;
    }
    while(l<=r)
    {
        if(left->data!=right->data)
        {
            flag=0;
            break;
        }
        left=left->next;l++;
        right=right->prev;r--;
    }
    return flag;
}
void main()
{
    char ch;
    header=(struct node*)malloc(sizeof(struct node));
    header->data=0;
    header->next=NULL;
    printf("Enter word:");
    ch=getchar();
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=ch;
    new->next=NULL;
    header->next=new;
    new->prev=header;
    struct node*temp=new;
    while(1)
    {
        ch=getchar();
        if(ch=='#')break;
        struct node*new=(struct node*)malloc(sizeof(struct node));
        new->data=ch;
        new->next=NULL;
        temp->next=new;
        new->prev=temp;
        temp=new;
    }
    display();
    int res=palindrome();
    if(res==1)
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not Palindrome\n");
    }
}