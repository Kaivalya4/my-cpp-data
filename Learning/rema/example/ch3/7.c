#include<stdio.h>
int main()
{
    int arr[10],n,i,j,pos,num;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nenter pos and number = \n");
    scanf("%d %d",&pos,&num);
    j=n;
    for(j;j>=pos;j--)
    {
       arr[j+1]=arr[j];
    }
    n=n+1;
    arr[pos]=num;
    for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    return 0;
}

