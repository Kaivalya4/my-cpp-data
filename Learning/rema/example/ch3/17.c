#include<stdio.h>
int main()
{
    int arr[8][8] ,i ,j;
    for(i=0; i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(i>=j)
                arr[i][j]=1;
            else
                arr[i][j]=0;
        }
    }
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(i>=j)
            {
                if(i!=j)
                {
                    arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
                }
            }
        }

    }
     for(i=0; i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(i>=j)
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}



