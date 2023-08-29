#include<stdio.h>
int main()
{
    int arr[5][3],sum[3]={0},sum1=0 ,i ,j;
    for(i=0;i<5;i++)
    {
        printf("Enter For student %d - \n",i+1);
        for(j=0;j<3;j++)
        {
            printf("Enter marks for suject %d = ",j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    for(j=0;j<3;j++)
    {
        int large=arr[0][j];
        for( i=0;i<5;i++)
        {
            if(arr[i][j]>large)
            {
                large=arr[i][j];
            }
        }
        printf("\nHighest marks in subject%d = %d",j+1,large);
    }
    return 0;
}

