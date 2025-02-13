#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int top1=-1,top2=-1,stack1[100],stack2[100];
void push1(int val)
{
    if(top1==MAX)
    {printf("Stack full\n");}
    else
    {
        stack1[++top1]=val;
    }
}
void push2(int val)
{
    if(top2==MAX)
    {printf("Stack full\n");}
    else
    {
        stack2[++top2]=val;
    }
}
int pop1()
{
    if(top1<0)
    {printf("StackEmpty\n");}
    else
    {
        return stack1[top1--];
    }
}
int pop2()
{
    if(top2<0)
    {printf("StackEmpty\n");}
    else
    {
        return stack2[top2--];
    }
}
void main()
{
    int n;
    printf("Enter the size of stack{max=10}:");
    scanf("%d",&n);
    printf("Enter the elements of stack");
    for(int i=0;i<n;i++)
    {
        int val;
        scanf("%d",&val);
        push1(val);
    }
    int maxval=0;
    int temptop=top1;
    while(temptop!=-1)
    {
        if(stack1[temptop]>maxval)
        {
            maxval=stack1[temptop];
        }
        temptop--;
    }
    while(top1!=-1)
    {
        int val;
        val=pop1();
        if(val!=maxval)
        {
            push2(val);
        }
    }
    printf("Stack after removing the greatest value\n");
    while(top2>=0)
    {
        printf("%d ",pop2());
    }
}