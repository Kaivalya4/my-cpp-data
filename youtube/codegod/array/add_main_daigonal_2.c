#include<stdio.h>
int main()
{
    int a[5][5],i,n,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            if(i == j)
            {
                sum=sum+a[i][j];
            }
        }
    }
   for(i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);     //using & here gives address of the variable
        }
        printf("\n");
    }
    printf("\ndigonal sum - %d",sum);
}

