#include<stdio.h>
int main()
{
    int arr[5][3],sum[3]={0},sum1=0 ,i ,j;
    for(i=0;i<5;i++)
    {
        printf("Enter For salesman %d - \n",i+1);
        for(j=0;j<3;j++)
        {
            printf("Number of Item %d sold - ",j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<5;i++)
    {
        int sum =0;
        for( j=0;j<3;j++)
        {
            sum =sum +arr[i][j];
        }
        printf("\nTotal items sold by sales  man %d = %d",i+1,sum);

    }
    for(j=0;j<3;j++)
    {
        int sum =0;
        for( i=0;i<5;i++)
        {
            sum =sum +arr[i][j];
        }
        printf("\nTotal number of item %d sold =%d",j+1,sum);
    }
    return 0;
}
