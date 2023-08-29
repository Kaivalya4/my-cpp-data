#include<stdio.h>
int main()
{
    int arr[20],i,n,max,min;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    max=min=arr[0];
    for(i=0;i<n;i++)
    {
        if(max<arr[i])
            max=arr[i];
        if(min>arr[i])
            min=arr[i];
    }
    printf("\nmax=%d min=%d",max,min);
}
