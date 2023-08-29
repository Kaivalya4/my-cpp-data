#include<stdio.h>
int main()
{
    int arr[10],n,i,num=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=n-1;i>=0;i--)
    {
        int dec=1;
        for(int k=i;k>0;k--)
        {
            dec*=10;
        }
        num=num+(arr[n-1-i]*dec);
    }
    printf("\nnumber is - %d",num);
    return 0;
}


