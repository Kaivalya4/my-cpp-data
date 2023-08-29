#include<stdio.h>
int main()
{
    int a[5][5],n,i,j,sum=0,sum1=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
            for( j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
                if(i<=j)
                    sum=sum+a[i][j];
                if(i>=j)
                    sum1=sum1+a[i][j];
            }
    }
    printf("\nupper triangular sum = %d \n lower triangular sum = %d",sum,sum1);
    return 0;
}
