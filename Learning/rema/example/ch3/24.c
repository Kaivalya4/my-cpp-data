#include<stdio.h>
#include<stdlib.h>
void read(int arr[5][5],int m)   // in case of 2d array you can not have array with blank index as in case of 1d array
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(i>j)
                arr[i][j]=-1;
            else if(i==j)
                arr[i][j]=0;
            else
                arr[i][j]=1;
        }
    }
}
void print(int arr[5][5],int m)
{
    printf("\n");
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            printf(" %d  ",arr[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int arr1[5][5],i,j,m;
    printf("Enter size of matrix = ");
    scanf("%d",&m);
    read(arr1,m);
    print(arr1,m);
    return 0;
}
