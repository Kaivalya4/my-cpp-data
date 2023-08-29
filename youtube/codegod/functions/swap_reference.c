#include<stdio.h>
int swap(int*,int*);
int main()
{
    int num1,num2;
   /* scanf("%d",&num1);
    int*ptr=&num1;
    printf("%d %d",ptr,&ptr);*/ //ptr will give address of himself whereas &ptr gives address of num1
    scanf("%d%d",&num1,&num2);
    swap(&num1,&num2);
    printf("%d %d",num1,num2);

    return 0;
}
int swap(int*m,int*n)
{
    int temp;
    temp=*m;
    *m=*n;
    *n=temp;
    return 0;
}


