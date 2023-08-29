#include<stdio.h>
int Exp(int a , int b)
{
    if(b == 0)
        return 1;
    else
    {
        return a * Exp(a,b-1);
    }
}
int main()
{
    int a , b , val;
    printf("enter the base : ");
    scanf("%d",&a);
    printf("\nenter the power : ");
    scanf("%d",&b);
    val= Exp(a,b);
    printf("\n exponential of the given numbers are : %d", val);
    return 0;
}
