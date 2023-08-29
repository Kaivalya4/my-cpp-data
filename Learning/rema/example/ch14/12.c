#include<stdio.h>
int main()
{
    int arr[20] , i ,n,gap_size,flag = 1,temp;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter the elements of the array : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    gap_size = n;
    while(flag == 1 || gap_size > 1)
    {
        flag =0;
        gap_size = (gap_size+1)/2;
        for(i=0;i<(n-gap_size);i++)
        {
            if(arr[i+gap_size] < arr[i])
            {
                temp = arr[i+gap_size];
                arr[i+gap_size] = arr[i];
                arr[i] = temp;
                flag = 0;
            }
        }
    }
    printf("Sorted array is : ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
