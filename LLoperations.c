#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*header=NULL;
void display()
{
    struct node *p;
    p=header->next;
    while(p!=NULL)
    {
        printf("%d->",p->data);
        p=p->next;
    }
    printf("NULL\n");
}
void createList(int n)
{
    int x;
    struct node*new,*temp;
    header=(struct node*)malloc(sizeof(struct node));
    header->data=0;
    header->next=NULL;
    new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL)
    {
        printf("Memory allocation error");
    }
    else
    {
        printf("Enter data of node 1:");
        scanf("%d",&x);
        new->data=x;
        new->next=NULL;
        header->next=new;
        temp=new;
        for(int i=2;i<=n;i++)
        {
            new=(struct node*)malloc(sizeof(struct node));
            printf("Enter data of node %d:",i);
            scanf("%d",&x);
            new->data=x;
            new->next=NULL;
            temp->next=new;
            temp=new;
        }
    }
}
void insertFront()
{
    int x;
    printf("Enter the data to add:");
    scanf("%d",&x);
    if(header->next==NULL)
    {
        struct node *new=(struct node*)malloc(sizeof(struct node));
        new->data=x;
        new->next=NULL;
        header->next=new;
    }
    else
    {
        struct node *ptr=header->next;
        struct node *new=(struct node*)malloc(sizeof(struct node));
        new->data=x;
        new->next=ptr;
        header->next=new;
    }
}
void insertLast()
{
    int x;
    printf("Enter the data to add:");
    scanf("%d",&x);
    if(header->next==NULL)
    {
        struct node *new=(struct node*)malloc(sizeof(struct node));
        new->data=x;
        new->next=NULL;
        header->next=new;
    }
    else
    {
        struct node *ptr=header->next;
        if(ptr->next==NULL)
        {
            struct node *new=(struct node*)malloc(sizeof(struct node));
            new->data=x;
            new->next=NULL;
            ptr->next=new;
        }
        else
        {
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            struct node *new=(struct node*)malloc(sizeof(struct node));
            new->data=x;
            new->next=NULL;
            ptr->next=new;
        }
    }
}
void insertAny(int key)
{
    if(header->next==NULL)
    {
        printf("No data currently in the list, so add in front by default");
        insertFront();
    }
    else
    {
        struct node *ptr=header->next;
        while(ptr->data!=key && ptr!=NULL)
        {
            ptr=ptr->next;
        }
        if(ptr==NULL)
        {
            printf("Key Not Found\n");
            return;
        }
        if(ptr->next==NULL)
        {
            struct node *new=(struct node*)malloc(sizeof(struct node));
            int x;
            printf("Enter data to add:");
            scanf("%d",&x);
            new->data=x;
            new->next=NULL;
            ptr->next=new;
        }
        else
        {
            struct node *temp=ptr->next;
            struct node *new=(struct node*)malloc(sizeof(struct node));
            int x;
            printf("Enter data to add:");
            scanf("%d",&x);
            new->data=x;
            new->next=temp;
            ptr->next=new;
        }
    }
}
void deleteFront()
{
    if(header->next==NULL)
    {printf("No data to be deleted\n");return;}   
    else
    {
        struct node *ptr=header->next;
        if(ptr->next==NULL)
        {
            header->next=NULL;
            printf("Data being deleted:%d\n",ptr->data);
            free(ptr);
        }
        else
        {
            header->next=ptr->next;
            printf("Data being deleted:%d\n",ptr->data);
            free(ptr);
        }
    }
}
void deleteLast()
{
    if(header->next==NULL)
    {printf("No data to be deleted\n");return;}
    else
    {
        struct node *ptr=header->next;
        if(ptr->next==NULL)
        {
            header->next=NULL;
            printf("Data being deleted:%d\n",ptr->data);
            free(ptr);
        }
        else
        {
            struct node *temp=NULL;
            while(ptr->next!=NULL)
            {
                temp=ptr;
                ptr=ptr->next;
            }
            temp->next=NULL;
            printf("Data being deleted:%d\n",ptr->data);
            free(ptr);
        }
    }
}
void deleteAny(int key)
{
    struct node *temp=NULL;
    if(header->next==NULL)
    {printf("No data to be deleted\n");return;}
    struct node *ptr=header->next;
    while( ptr!=NULL && ptr->data!=key )
    {
        temp=ptr;
        ptr=ptr->next;
    }
    if(ptr==NULL)
    {
        printf("Key Not Found\n");
        return;
    }
    if(ptr->next==NULL)
    {
        temp->next=NULL;
        printf("Data being deleted: %d\n",ptr->data);
        free(ptr);
    }
    else
    {
        printf("Data being deleted:%d\n",ptr->data);
        temp->next=ptr->next;
        free(ptr);
    }
}
void main()
{
    int n,i=1,ch;
    struct node *p;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    createList(n);
    printf("Displaying the Linked list:\n");
    p=header->next;
    while(p!=NULL)
    {
        printf("\tData %d:%d",i,p->data);
        i++;
        p=p->next;
    }
    int key;
    printf("\nOptions after creating linked list:\n");
    while(1)
    {
        printf("1.insertFront  2.insertEnd  3.insertAny  4.deleteFront  5.deleteLast  6.deleteAny  7.Exit\n");
        printf("Choose any:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insertFront();
                printf("Updated Linked list:");
                display();
                break;
            case 2:
                insertLast();
                printf("Updated Linked List:");
                display();
                break;
            case 3:
                printf("Enter after which data you want to enter:");
                scanf("%d",&key);
                insertAny(key);
                display();
                break;
            case 4:
                deleteFront();
                display();
                break;
            case 5:
                deleteLast();
                display();
                break;
            case 6:
                printf("Enter  which data you want to delete:");
                scanf("%d",&key);
                deleteAny(key);
                display();
                break;
            case 7:
                exit(0);
        }
    }
}