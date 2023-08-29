#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr1[5][5],arr2[5][5],i,j,m1,m2,n1,n2,sum[5][5];
    printf("For Matrix1 --\nRows = ");
    scanf("%d",&m1);
    printf("\n Column = ");
    scanf("%d",&n1);
    printf("\n\nFor Matrix2 --\nRows = ");
    scanf("%d",&m2);
    printf("\n Column = ");
    scanf("%d",&n2);
    printf("\nEnter elemnts for matrix 1 = ");
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n1;j++)
        {
            scanf("%d",&arr1[i][j]);
        }
    }
     printf("\nEnter elemnts for matrix 2 = ");
    for(i=0;i<m2;i++)
    {
        for(j=0;j<n2;j++)
        {
            scanf("%d",&arr2[i][j]);
        }
    }
    if((m1!=m2)&&(n1!=n2))
    {
        printf("size of matrix not matched !!!");
        exit(0);
    }
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n2;j++)
        {
            sum[i][j]=arr1[i][j]+arr2[i][j];
        }
    }
    printf("\nmatrix 1 is ----\n ");
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n1;j++)
        {
            printf("%d ",arr1[i][j]);
        }
        printf("\n");
    }
     printf("\n matrix 2 is --- \n");
    for(i=0;i<m2;i++)
    {
        for(j=0;j<n2;j++)
        {
            printf("%d ",arr2[i][j]);
        }
        printf("\n");
    }
     printf("\n their sum is --- \n");
    for(i=0;i<m2;i++)
    {
        for(j=0;j<n2;j++)
        {
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}
