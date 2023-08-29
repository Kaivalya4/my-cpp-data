#include<stdio.h>
int main()
{
    int arr[10],i,n,high1,high2,high3;
    printf("enter number of elements - ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("arr[%d] - ",i);
        scanf("%d",&arr[i]);
    }
    high1=arr[0];
    for(i=0;i<n;i++)
    {
       if(arr[i]>high1)
        high1=arr[i];
    }
    high2=arr[1];
    for(i=0;i<n;i++)
    {
        if(arr[i]>high2&&arr[i]!=high1)
            high2=arr[i];
    }
    high3=arr[3];
    for(i=0;i<n;i++)
    {
       if(arr[i]>high3&&(arr[i]!=high1&&arr[i]!=high2))
            high3=arr[i];
    }
    printf("first largest= %d \n first largest= %d \n first largest= %d ",high1,high2,high3);
    return 0;
}
