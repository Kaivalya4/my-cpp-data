#include<stdio.h>
int main()
{
    int n,i,j,arr[10],val,sign =0 ;
    printf("Enter number of elemnts of array : ");
    scanf("%d",&n);
    printf("\nEnter elements of array : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the value to be searched : ");
    scanf("%d",&val);
    for(i=0;i<n;i++)
    {
        if(arr[i] == val)
        {
            sign =1;
            printf("\nElemnet found at %d index .",i);
        }
    }
    if(sign==0)
        printf("\nElement not found .");
    return 0;
}
