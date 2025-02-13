#include <stdio.h>
#include <stdlib.h>
#define MAX 10 
int top1=-1,top2=-1,top3=-1;
int s1[100],s2[100],s3[100];
void push1(int val)
{
    if (top1==MAX)
    {printf("Stack Full");}
    else
    {
        top1++;
        s1[top1]=val;
    }
}
void push2(int val)
{
    if (top2==MAX)
    {printf("Stack Full");}
    else
    {
        top2++;
        s2[top2]=val;
    }
}
void push3(int val)
{
    if (top3==MAX)
    {printf("Stack Full");}
    else
    {
        top3++;
        s3[top3]=val;
    }
}
int pop1()
{
    if(top1<0){printf("Stack empty!\n");}
    else{return s1[top1--];}
}
int pop3()
{
    if(top3<0){printf("Stack empty!\n");}
    else{return s3[top3--];}
}
void main()
{
    int n;
    printf("Enter stack size{max=10}:");
    scanf("%d",&n);
    printf("Enter the %d integers:",n);
    for(int i=0;i<n;i++)
    {
        int val;
        scanf("%d",&val);
        push1(val);
    }
    int th;
    printf("Enter the threshold");
    scanf("%d",&th);
    printf("Original stack contents are:");
    for(int i=0;i<n;i++)
    {
        printf("%d ",s1[i]);
    }
    while(top1!=-1)
    {
        if(s1[top1]>=th)
        {
            int val=pop1();
            push2(val);
        }
        else
        {
            int val=pop1();
            push3(val);
        }
    }
    if(top2==-1)
    {
        printf("Sorry There are no elements greater than %d",th);
    }
    else
    {
        printf("Stack after removing values greater than threshold:");
        while(top3!=-1)
        {
            printf("%d ",pop3());
        }
    }
}