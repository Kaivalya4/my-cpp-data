#include<stdio.h>
int small(int arr[],int n)
{
    int small=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]<small)
            small=arr[i];
    }
    return small;
}
int main()
{
    int arr[10],n,i;
    printf("enter number of elements = ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("arr[%d] = ",i);
        scanf("%d",&arr[i]);
    }
    printf("smallest element = %d",small(arr,n));
    return 0;
}
