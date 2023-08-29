#include<stdio.h>
int main()
{
    int arr[10] ,i,temp,j,n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("\nEnter the elemnets of the array : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nSelection sort begins :- ");
    for(i=0;i<n;i++)               //we can split this into two function
    {
        for(j=i;j<n;j++)
            if(arr[i]>arr[j])      //one function will find the position of smallest element and then we will swap first position with smallest element and secon position with second smallest and so on.
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        printf("\nAfter the %d pass elements in the array is : ",i+1);
        for(j=0;j<n;j++)
            printf("%d ",arr[j]);
    }
    return 0;
}
