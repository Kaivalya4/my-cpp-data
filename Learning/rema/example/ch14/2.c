/*
we can also call this function recursively -
int bin(int arr, int beg , int end , int val)
{
    if(arr[mid] == val)
        return mid;
    else if(beg > end)
        return -1;
    else if(arr[mid] > val)
    {
        return bin(arr , beg ,mid-1,val);
    }
    else if(arr[mid] < val)
    {
        return bin(arr , mid+1 , end ,val);
    }
}
*/
#include<stdio.h>
void bubble(int arr[] , int n )
{
    int i,j,temp,flag=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(arr[j] > arr[j+1])
            {
                flag =1;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(flag == 0)
            return ;
    }
    return ;
}
void bsearch(int arr[] , int beg , int end , int val)
{
    int mid  , flag = 0;
    while(beg <= end)
    {
        mid = (beg+end)/2;
        if(arr[mid] == val)
        {
            flag = 1;
            printf("\nValue found at index %d .",mid);
            return ;
        }
        else if(arr[mid] > val)
            end = mid -1;
        else if(arr[mid] < val)
            beg = mid +1;
    }
    printf("\nOOps element not found ! ");
    return ;
}
int main()
{
    int arr[10],val , i,n,j;
    printf("Enter number of elements in the array : ");
    scanf("%d",&n);
    printf("\nEnter elements of the array : ");
    for(i=0 ; i<n ;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("array after sorting becomes : ");
    bubble(arr , n);
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nEnter the element to be searched : ");
    scanf("%d",&val);
    bsearch(arr , 0 , n-1 , val);
    return 0;
}
