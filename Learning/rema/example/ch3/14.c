#include<stdio.h>
int small(int arr[],int n)
{
    int small=arr[0];
    int m,k;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<small)
        {
            small=arr[i];
            k=i;
        }
    }
    int large=arr[1];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>large)
        {
            large=arr[i];
            m=i;
        }
    }
   arr[m]=small;
   arr[k]=large;
   return 0;

}
int main()
{
    int arr[10],n,i;
    printf("enter number of elements = ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\narr[%d] = ",i);
        scanf("%d",&arr[i]);
    }
    small(arr,n);
    for(i=0;i<n;i++)
    {
        printf("\n%d ",arr[i]);
    }
    return 0;
}
