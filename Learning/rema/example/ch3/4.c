#include<stdio.h>
int main()
{
    int arr[10],n,i,large=0,seclarge=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    large=arr[0];
    for(i=0;i<n;i++)
    {
        if(arr[i]>large)
        {
           large=arr[i];
        }
    }
    seclarge=-99999999;
    for(i=0;i<n;i++)
    {
        if(seclarge<arr[i]&&arr[i]!=large)
            seclarge=arr[i];
    }
    printf("\nsec large number is - %d",seclarge);
    return 0;
}

