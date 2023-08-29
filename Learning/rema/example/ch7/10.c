#include<stdio.h>
int fact(int num)
{
    if(num == 0)
        return 1;
    return num *fact(num-1) ;
}
int main()
{
    int num , val;
    printf("enter the number whose factorial is to be finded : ");
    scanf("%d",&num);
    val = fact(num);
    printf("\nfactorial of the number is : %d",val);
    return 0;
}
