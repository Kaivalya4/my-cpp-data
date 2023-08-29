#include<stdio.h>
#include<stdlib.h>
int fibo(int prev,int cur,int n)
{   if(n==2)
    {
        exit(0);
    }
    else
    {
        int temp;
        temp=cur;
        cur=prev+cur;
        prev=temp;
        printf("%d ",cur);
        fibo(prev,cur,n-1);
    }
    return 0;
}
int main()
{
    int n,prev=0,cur=1;
    scanf("%d",&n);
    printf("%d %d ",prev,cur);
    fibo(prev,cur,n);
    return 0;
}
