#include<stdio.h>
#include<stdlib.h>
void fib(int fir , int sec , int n)
{
    if(n ==2 )
        exit(0);
    else
    {
        int temp;
        temp = sec;
        sec= fir + sec;
        fir = temp;
        printf("%d ",sec);
        fib(fir , sec , n-1);
    }
}
int main()
{
    int first =0 , second =1 , n;
    printf("enter the number upto which you want series : ");
    scanf("%d",&n);
    printf("\n%d %d ",first,second);
    fib(first , second , n);
    return 0;
}
