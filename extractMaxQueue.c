#include <stdio.h>
#include <stdlib.h>
int front=0,rear=0,size;
int Q[100];
void enqueue(int val)
{
    if(rear==size)
    {
        printf("Queue full!\n");
    }
    else
    {
        Q[rear]=val;
        rear++;
    }
}
void dequeue()
{
    if(rear==front)
    {printf("Queue Empty!");}
    else
    {
        printf("Dequeued element %d",Q[front]);
        front++;
    }
}
void extractMax()
{
    if(rear==front){printf("Queue empty!!\n");return;}
    int maxval=Q[front];
    int maxInd=front;
    for(int i=front+1;i<rear;i++)
    {
        if(Q[i]>maxval)
        {
            maxval=Q[i];
            maxInd=i;
        }
    }
    printf("Extracted max element:%d\n",maxval);
    //shifting
    for(int i=maxInd;i<rear;i++)
    {
        Q[i]=Q[i+1];
    }
    rear--;
}
void display()
{
    if(rear==front)
    {
        printf("Queue empty\n");
        return;
    }
    printf("The Queue:\n");
    for(int i=front;i<rear;i++)
    {
        printf("%d ",Q[i]);
    }
    printf("\n");
}
void main()
{
    int ch;
    printf("Enter the size of queue {MAX=100}: ");
    scanf("%d", &size);

    while (1) {
        printf("Queue Operations:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Extract-Max\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: {
                int val;
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            }

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                extractMax();
                break;

            case 5:
                printf("Thank You!\n");
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }
}
