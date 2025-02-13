#include<stdio.h>
#include<stdlib.h>
void converter(float num)
{
    int intPart=(int)num; //taking integer part alone
    float frac=num-intPart;
    int binary[32];
    int index=0;
    if(num==0)
    {
        printf("Binary:0\n");
        return;
    }
    //integer part
    while(intPart>0)
    {
        binary[index]=intPart%2;
        index++;
        intPart=intPart/2;
    }
    printf("Binary:");
    for(int i=index-1;i>=0;i--)
    {
        printf("%d",binary[i]);
    }
    //fractional part
    if(frac>0)
    {
        printf(".");
        for(int i=0;i<6;i++)
        {
            frac=frac*2;
            printf("%d",(int)frac);
            frac=frac-(int)frac;
            if(frac==0)break;
        }
    }
    printf("\n");
}
void main()
{
    float num;
    printf("Enter Decimal number to convert to binary:");
    scanf("%f",&num);
    converter(num);
}
