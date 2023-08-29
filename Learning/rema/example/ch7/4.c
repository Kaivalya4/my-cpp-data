#include<stdio.h>
#include<stdlib.h>
int top=-1;
int stk[10];
void push(int);
int main()
{
    int val,*arr,n,i;
    printf("enter number of elements : ");
    scanf("%d",&n);
    arr=(int*)malloc(sizeof(int)*n);
    printf("\nenter the elments of the array : ");
    for(i =0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        push(arr[i]);
    }
    for(i=0;i<n;i++)
    {
        arr[i]=stk[top];
        top--;
    }
    printf("\nreversed array is : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}
void push(int a)
{
    top++;
    stk[top]=a;
}
