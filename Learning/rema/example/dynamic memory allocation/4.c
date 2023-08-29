#include<stdio.h>
#include<stdlib.h>
int main()
{
    int **ptr,i,j,row,col;
    printf("enter number of rows and column of array respectively : ");
    scanf("%d %d",&row,&col);
    ptr=(int**)malloc(row*sizeof(int));
    if(ptr == NULL)
    {
        printf("\nmemory can not be allocated !!!");
        exit(0);
    }
    for(i=0;i<row;i++)
    {
        ptr[i]=(int*)malloc(col*sizeof(int));
        if(ptr[i] == NULL)
        {
            printf("memory cannot be allocated !!!");
            exit(0);
        }
    }
    printf("\nenter the elements of array : ");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&ptr[i][j]);
        }
    }
    printf("\nelements in the array are :");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            printf(" %d",ptr[i][j]);
    }
    for(i=0;i<row;i++)
        free(ptr[i]);
    free(ptr);
    return 0;
}
