#include<stdio.h>
int main()
{
    int a[5][5],i,n,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);           //same here
    for(i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i==j)
                sum=sum+a[i][j];       //only single line hence no bracket
    printf("\ndigonal sum - %d",sum);
}
