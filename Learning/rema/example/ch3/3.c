#include<stdio.h>
int main()
{
    int arr[10],n,i,small=0,pos=0;
    int *ptr=&arr;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    small=arr[0];
    for(i=0;i<n;i++)
    {
        if(arr[i]<small)
        {
            small=arr[i];
            pos=i;
            ptr=&arr[i];
        }
    }
    printf("address of smallest element = %d \n and index is = %d",ptr,pos);
    return 0;
}
