//passing an elment of array
#include<stdio.h>
int func(int*a)
{
    printf("%d\n",*a);
    *a+=1;
    return 0;
}
int main()
{
    int arr[4]={1,2,3,4};
    func(&arr[2]);          //array is always passed by reference not by value
    printf("%d",arr[2]);
    return 0;
}
