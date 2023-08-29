#include<stdio.h>
int main()
{
    int arr[10],n,i,dup;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        dup=arr[i];
        for(int k=i+1;k<n;k++)
        {
            if(arr[i]==arr[k])
                printf("duplicate number is %d",arr[k]);
        }

    }
    return 0;
}
