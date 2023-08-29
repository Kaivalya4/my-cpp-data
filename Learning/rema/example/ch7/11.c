#include<stdio.h>
int gcd(int a,int b)
{
    if((a-b)>0)
    {
        if(a%b == 0)
            return b;
        else
        {
            return gcd(b,a%b);
        }
    }
    else
    {
        if(b%a == 0)
            return a;
        else
        {
            return gcd(a,b%a);
        }
    }
}
int main()
{
    int a ,b , val;
    printf("\n enter the first number : ");
    scanf("%d",&a);
    printf("\nenter the second number : ");
    scanf("%d",&b);
    val = gcd(a,b);
    printf("\n gcd of the two numbers are : %d",val);
    return 0;
}
