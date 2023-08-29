#include<stdio.h>
int main()
{
    int arr1[10],arr2[10],arr3[10],i,n,j=0,k=0;
    printf("enter number of elements - ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("arr1[%d] - ",i);
        scanf("%d",&arr1[i]);
    }
    for(i=0;i<n;i++)
    {
       if(arr1[i]%2==0)
       {
           arr2[j]=arr1[i];
           j++;
       }
       else
       {
           arr3[k]=arr1[i];
           k++;
       }
    }
    printf("\nOdd array = ");
    for(i=0;i<k;i++)
    {
        printf("%d ",arr3[i]);
    }
    printf("\Even array = ");
    for(i=0;i<j;i++)
    {
        printf("%d ",arr2[i]);
    }
    return 0;
}
