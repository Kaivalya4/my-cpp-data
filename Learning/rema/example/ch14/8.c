#include<stdio.h>
int temp[10] , indexing =-1;
void merge(int arr[] , int beg , int mid , int end)
{
    int i = beg , j = mid+1 , k=0;
    while(i<=mid && j<=end)
    {
        if(arr[i]<arr[j])
        {
            indexing ++;
            temp[indexing] = arr[i];
            i++;
        }
        else
        {
            indexing ++ ;
            temp[indexing] = arr[j];
            j++;
        }
    }
    if(i> mid)
    {
        while(j<=end)
        {
            temp[++indexing] = arr[j];
            j++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[++indexing] = arr[i];
            i++;
        }
    }
    for(k=beg ; k<=indexing ;)
    {
        arr[k] = temp[k];
        k++;
    }
}
void merge_sort(int arr[],int beg,int end)
{
    if(beg<end)
    {
        int mid = (beg+end)/2;
        merge_sort(arr,beg,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,beg,mid,end);
    }
}
int main()
{
    int arr[10],n,i;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("\nEnter the elements of the array : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    merge_sort(arr,0,n-1);
    printf("\nElements after being sorted is : ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
