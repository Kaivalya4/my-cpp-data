#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr1[5][5],arr2[5][5],i,j,k,m1,m2,n1,n2,pro[5][5],sum=0;
    printf("For Matrix1 --\nRows = ");
    scanf("%d",&m1);
    printf("\nColumn = ");
    scanf("%d",&n1);
    printf("\n\nFor Matrix2 --\nRows = ");
    scanf("%d",&m2);
    printf("\nColumn = ");
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
    if(n1!=m2)
    {
        printf("\nmultiplaction not possible!!!");
        exit(0);
    }
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n2;j++)
        {
            pro[i][j]=0;
            for(k=0;k<=n2;k++)
            {
                pro[i][j]=pro[i][j]+arr1[i][k]*arr2[k][j];
            }
        }
    }

    printf("\nmatrix1 is  = \n ");
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n1;j++)
        {
            printf("%d  ",arr1[i][j]);
        }
        printf("\n");
    }
    printf("\nmatrix 2 is  = \n");
    for(i=0;i<m2;i++)
    {
        for(j=0;j<n2;j++)
        {
            printf("%d ",arr2[i][j]);
        }
        printf("\n");
    }
    printf("\nProduct of matrix is  = \n ");
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n2;j++)
        {
            printf("%d  ",pro[i][j]);
        }
        printf("\n");
    }
    return 0;
}
