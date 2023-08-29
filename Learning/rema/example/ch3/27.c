#include<stdio.h>
int main()
{
    int arr[2][2][2],i,j,k;
    printf("enter elments of 2*2*2 array  -  ");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            for(k=0;k<2;k++)
            scanf("%d",&arr[i][j][k]);
        }
    }
    printf("\nelements in 2*2*2 array is - \n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            for(k=0;k<2;k++)
                printf("%d ",*(*(*(arr+i)+j)+k));
            printf("\n");
        }
        printf("\n");                    //here we will get two pages of 2*2 dimension.
    }
    return 0;
}
