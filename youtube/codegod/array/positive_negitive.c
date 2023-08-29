#include<stdio.h>
int main()
{
    int arr[20],i,n;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        if(arr[i]>=0)
            printf("%2d",arr[i]);
    }
     for(i=0;i<n;i++)
    {
        if(arr[i]<0)
            printf("%2d",arr[i]);
    }
    return 0;
}

