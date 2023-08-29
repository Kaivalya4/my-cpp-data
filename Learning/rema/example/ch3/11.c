#include <stdio.h>
int main()
{
    int arr1[10],arr2[10],arr3[30],n1,n2,i;
    printf("\n Enter the number of elements in the array 1: ");
    scanf("%d", &n1);
    for(i=0;i<n1;i++)
    {
        printf("\n arr[%d] = ", i);
        scanf("%d", &arr1[i]);
    }
    printf("\n Enter the number of elements in the array 2: ");
    scanf("%d", &n2);
    for(i=0;i<n2;i++)
    {
        printf("\n arr[%d] = ", i);
        scanf("%d", &arr2[i]);
    }
    for(i=0;i<n1;i++)
    {
        arr3[i]=arr1[i];
    }
    for(int j=0;j<n2;j++)
    {
        arr3[i]=arr2[j];
        i++;
    }
    int n=n1+n2;
    for(i=0;i<n;i++)
    {
        printf("%d ",arr3[i]);
    }
    return 0;
}
