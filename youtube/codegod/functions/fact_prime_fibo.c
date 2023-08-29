//program for factorial,checking prime,fibonacci series

#include<stdio.h>
int fact(int n)
{
    int i,fact=1;
    for(int i=1;i<=n;i++)
    {
        fact = fact * i;
    }
    printf("\n%d",fact);
    return 0;
}
int isprime(int n)
{
    int i,flag=0;
    for(i=2;i<=n/2;i++)
    {
        if(n%i==0)
            flag+=1;
    }
    if(flag == 0)
        printf("\nprime");
    else
        printf("\nnot prime");
    return 0;
}
int fib(int n)
{
    int i,prev=0,cur=1,temp;
    printf("%d%d",prev,cur);
    for(int i=2;i<=n;i++)
    {
        temp=cur;
        cur=cur+prev;
        prev=cur;
        printf("%d",cur);
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d\n",&n);
    fact(n);
    isprime(n);
    fib(n);
    return 0;
}
