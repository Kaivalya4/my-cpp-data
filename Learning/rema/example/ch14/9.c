#include<stdio.h>
#define size 10
int partition(int a[] , int beg , int end )
{
    int loc,temp,left,right ,flag =0;
    loc = left = beg ;
    right = end;
    while(flag == 0)
    {
        while((a[loc] <= a[right]) && (loc!= right))
        {
            right--;
        }
        if(loc == right)
        {
            flag = 1;
        }
        else if(a[loc] > a[right])
        {
            temp = a[loc];
            a[loc] = a[right];
            a[right] = temp;
            loc = right ;
        }
        if(flag == 0)
        {
            while((a[loc]>=a[left]) && (loc != left))
                left ++;
            if(loc == left)
                flag = 1;
            else if(a[loc] < a[left])
            {
                temp = a[loc];
                a[loc] = a[left];
                a[left] = temp;
                loc = left;
            }
        }
    }
    return loc;
}
void quicksort(int a[] , int beg , int end)
{
    int loc;
    if(beg<end)
    {
        loc = partition(a , beg , end );
        quicksort(a,beg,loc-1);
        quicksort(a,loc+1,end);
    }
}
int main()
{
    int arr[size] , n ,i;
    printf("Enter the number of elements of the array : ");
    scanf("%d",&n);
    printf("\nEnter the elements of the array : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    quicksort(arr , 0 ,n-1);
    printf("elements after being sorted : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
