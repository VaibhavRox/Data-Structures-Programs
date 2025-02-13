#include <stdio.h>
#include <stdlib.h>
int front1=0,rear1=0,front2=0,rear2=0;
int size1,size2,Q1[100],Q2[100];
void enqueue(int Q[],int *rear,int size,int val)
{
    if(*rear==size)
    {
        printf("Queue Full\n");
        return;
    }
    else
    {
        Q[*rear]=val;
        (*rear)++;
    }
}
int dequeue(int Q[],int *front,int rear)
{
    if(*front==rear)
    {
        printf("Queue Empty\n");
        return -1;
    }
    else
    {
        return Q[(*front)++];
    }
}
void display(int Q[],int front,int rear)
{
    if(rear==front)
    {
        printf("Queue Empty\n");
        return;
    }
    printf("THe Queue is:\n");
    for(int i=front;i<rear;i++)
    {
        printf("%d ",Q[i]);
    }
    printf("\n");
}
void removeNegatives()
{
    if(front1==rear1)
    {printf("Queue Empty\n");return;}
    printf("Removing Negatives...\n");
    while(front1<rear1)
    {
        int val=dequeue(Q1,&front1,rear1);
        if(val>0)
        {
            enqueue(Q2,&rear2,size2,val);
        }
    }
}
void main()
{
    int ch,val;
    printf("Enter size of queue{max=100}:");
    scanf("%d",&size1);
    size2=size1;
    while(1)
    {
        printf("1.Enqueue  2.Display 3.RemoveNegatives 4.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
                    printf("Enter value to enqueue:");
                    scanf("%d",&val);
                    enqueue(Q1,&rear1,size1,val);
                    break;
            case 2: display(Q1,front1,rear1);
                    break;
            case 3: removeNegatives();
                    display(Q2,front2,rear2);
                    break;
            case 4: exit(0);
            default:printf("INVALID CHOICE\n");
        }
    }
}