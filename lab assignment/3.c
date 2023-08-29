#include<stdio.h>
int add(int a)
{
    if(a==0)
        return 0;
    return a+add(a-1);
}
int main()
{
    int num;
    printf("enter number = ");
    scanf("%d",&num);
    printf("sum of num is = %d",add(num));
    return 0;
}
