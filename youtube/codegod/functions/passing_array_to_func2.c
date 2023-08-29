//passing whole array with usized array
#include<stdio.h>
int func(int a[]) //you can use both sized and unsized array
{
    for(int i=0;i<4;i++)
        printf("%d ",a[i]++);
    printf("\n");
    return 0;
}
int main()
{
    int arr[4]={1,2,3,4};
    func(arr);        //& and * not used in passing whole array .though & is not used then also it is passing by refrence
    for(int i=0;i<4;i++)
        printf("%d ",arr[i]);
    return 0;
}
