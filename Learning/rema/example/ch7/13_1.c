#include<stdio.h>
#include<stdlib.h>
int fib(int n){

    if(n==1)
        return 1;
    if(n==0)
        return 0;
    else
        return fib(n-1) + fib(n-2) ;
}
int main()
{
    int first =0 , second =1 , n;
    printf("enter the number upto which you want series : ");
    scanf("%d",&n);
    for(int i=0 ; i< n ; i++)
    {
        printf("%d ",fib(i));
    }
    return 0;
}
