#include<stdio.h>
#include<stdlib.h>
void selectionSort(int A[],int n)
{
    for(int i=0;i<=n-2;i++)
    {
        for(int j=i+1;j<=n-1;j++)
        {
            if(A[i]>A[j])
            {
                int temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
        }
    }
}
int binarySearch(int A[],int n,int key)
{
    int l=0,r=n-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(A[mid]==key)
        {
            return mid;
        }
        else if(A[mid]>key)
        {
            r=mid-1;            //key is smaller than mid value
        }
        else
        {
            l=mid+1;            //key is bigger than mid value
        }
    }
    return -1;
}
void display(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
void main()
{
    int n,key;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int A[n];
    printf("Enter the elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    display(A,n);
    printf("Sorting the elements.........\n");
    selectionSort(A,n);
    display(A,n);
    printf("Enter element to search:");
    scanf("%d",&key);
    int result=binarySearch(A,n,key);
    if(result==-1){printf("ELement not found in array\n");}
    else{printf("Element found at index:%d\n",result);}
}