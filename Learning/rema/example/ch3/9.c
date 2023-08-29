#include<stdio.h>
int main()
{
    int arr[10],i,pos,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("arr[%d] = ",i);
        scanf("%d",&arr[i]);
    }
    printf("enter position at which ele. is to be deleted = ");
    scanf("%d",&pos);
    i=pos;
    for(i;i<n;i++)
    {
        arr[i]=arr[i+1];
    }
    n=n-1;
    for(i=0;i<n;i++)
    {
        printf("\narray is %d ",arr[i]);
    }
    return 0;
}
