#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *left,*right;
}*root=NULL,*stack[100];
int top=-1;
void push(struct node* temp)
{
    if(top<99)
    {
        top++;
        stack[top]=temp;
    }
}
struct node *pop()
{
    if(top>=0)
    {
        return stack[top--];
    }
}
struct node* createNode(int data)
{
    struct node* new=(struct node *)malloc(sizeof(struct node));
    new->data=data;
    new->left=NULL;new->right=NULL;
    return new;
}
void insertNode(int x)
{
    if(root==NULL)
    {
        root=createNode(x);
        printf("Root node created with data %d",root->data);
        return;
    }
    struct node *curr=root;
    struct node *ptr=NULL;
    while(curr!=NULL)
    {
        ptr=curr;
        if(x<curr->data)
        {
            curr=curr->left;
        }
        else if(x>curr->data)
        {
            curr=curr->right;
        }
        else
        {
            printf("Duplicate value not added\n");
            return;           
        }
    }
    if(x<ptr->data)
    {
        ptr->left=createNode(x);
    }
    else
    {
        ptr->right=createNode(x);
    }
}
void deleteNode(struct node* root,int key)
{
    struct node*curr=root;
    struct node*ptr=NULL;
    while(curr!=NULL&& curr->data!=key)
    {
        ptr=curr;
        if(key<curr->data)
        {
            curr=curr->left;
        }
        else
        {
            curr=curr->right;
        }
    }
    if(curr->left==NULL&&curr->right==NULL)
    {
        if(ptr==NULL){root=NULL;}
        else if(ptr->left==curr){ptr->left=NULL;}
        else{ptr->right=NULL;}
        free(curr);
    }
    else if(curr->left==NULL || curr->right==NULL)
    {
        struct node*child=(curr->left!=NULL)?curr->left:curr->right;
        if(ptr==NULL)
        {
            root=child;
        }
        else if(ptr->left==curr){ptr->left=child;}
        else{ptr->right=child;}
        free(curr);
    }
    else
    {
        struct node* suParent=curr;
        struct node* successor=curr->right;
        while(successor->left!=NULL)
        {
            suParent=successor;
            successor=successor->left;
        }
        curr->data=successor->data;
        if(suParent->left==successor)
        {
            suParent->left=(successor->right!=NULL)?successor->right:NULL;
        }
        else
        {
            suParent->right=(successor->right!=NULL)?successor->right:NULL;
        }
        free(successor);
    }
}
void inorder(struct node *root)
{
    struct node*curr=root;
    while(curr!=NULL||top!=-1)
    {
        while(curr!=NULL)
        {
            push(curr);
            curr=curr->left;
        }
        curr=pop();
        printf("%d ",curr->data);
        curr=curr->right;
    }
    printf("\n");
}
void shoot(struct node* root,int m)  
{
    struct node* curr = root;
    while (curr != NULL || top != -1)
    {
        while (curr != NULL)
        {
            push(curr);
            curr = curr->left;
        }
        curr = pop();
        if (curr->data > m)
        {
            int value = curr->data; // Store the value to delete
            curr = curr->right;    // Move to the right before deletion
            deleteNode(root, value);
        }
        else
        {
            curr = curr->right;
        }
    }
}
void main()
{
    int ch,x;
    while(1)
    {
        printf("1.InsertNode 2.Inorder 3.Shoot 4.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    printf("Enter data to add:");
                    scanf("%d",&x);
                    insertNode(x);
                    break;
            case 2:
                    printf("Inorder Traversal:\n");
                    inorder(root);
                    break;
            case 3:
                    printf("Before Shooting\n");
                    inorder(root);
                    printf("Enter the size:");
                    scanf("%d",&x);
                    printf("After shooting\n");
                    shoot(root,x);
                    inorder(root);
                    break;
            case 4:
                    printf("Thank You!!");
                    exit(0);
            default:
                    printf("Enter valid CHOICE!!!\n");
        }
    }
}