#include<stdio.h>
#include<math.h>
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
void jump(int arr[] , int beg , int end ,int val,int n)
{
    int step = sqrt(n);
    if(arr[step]<val)
    {
        while(arr[step]<val && beg<=end)
        {
           beg = step;
           step = step +sqrt(step);
        }
        end = step;
        for(int i=beg;i<end;i++)
        {
            if(arr[i] == val)
            {
                printf("\nvalue found at index = %d",i+1);
                return ;
            }
        }
    }
    else if(arr[step] > val)
    {
        while(arr[step]>val && beg<=end)
        {
            end = step;
            step = step - sqrt(step);
        }
        beg = step;
        for(int i=beg;i<end;i++)
        {
            if(arr[i] == val)
            {
                printf("\nvalue found at index = %d",i);
                return ;
            }
        }
    }
    printf("Oops value not found !!");
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
    jump(arr,0,n-1,val,n);
    return 0;
}
