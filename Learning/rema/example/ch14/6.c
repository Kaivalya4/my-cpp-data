#include<stdio.h>
int main()
{
    int arr[10] , n ,i,top,j,temp;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    printf("\nEnter the elements of the array : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Insertion sort begins ---- \n");
    for(i=1 ; i<n ;i++)
    {
        top = arr[i];
        j = i-1;
        while(top <= arr[j] && j>=0)
        {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            j--;
        }
        printf("\nAfter the %d pass Element in the arrays are : ",i+1);
        for(j=0 ; j<n ;j++)
        {
            printf("%d ",arr[j]);
        }
    }
    return 0;
}
