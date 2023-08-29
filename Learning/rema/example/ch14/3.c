#include<stdio.h>
void bubble(int arr[] ,int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void interpol(int arr[] , int beg , int end , int val)
{
    int flag,mid;
    while(beg<=end)
    {
        mid = beg + (end-beg)*((val-arr[beg])/(arr[end] - arr[beg]));
        if(arr[mid]>val)
            end = mid-1;
        else if(arr[mid] < val)
            beg = mid+1;
        else if(arr[mid] == val)
        {
            flag = 1;
            printf("\nvalue found at index = %d",mid);
            return ;
        }
    }
    if(flag == 0)
        printf("Oops Value not found !!! ");
    return ;
}
int main()
{
    int arr[15] ,n,i,val;
    printf("Enter number of elemnts : ");
    scanf("%d",&n);
    printf("Enter elements of the array : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nElements in the array when it get sorted : ");
    bubble(arr , n);
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\nEnter the element to be searched : ");
    scanf("%d",&val);
    interpol(arr,0,n-1,val);
    return 0;
}
