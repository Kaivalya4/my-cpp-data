#include<stdio.h>
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int *ptr1,*ptr2;
    ptr1=arr;
    ptr2=&arr[8];
    for(;ptr1<=ptr2;)
    {
        printf("%d ",*ptr1);
        ptr1++;
    }
    return 0;
}
