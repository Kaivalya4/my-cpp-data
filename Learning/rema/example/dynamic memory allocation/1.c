#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr,n,i;
    printf("enter the size of array : ");
    scanf("%d",&n);
    ptr=(int*)malloc(n*2);
    if(ptr == NULL)
    {
        printf("\noops ! memory can not be allocated .");
        exit(0);
    }
    printf("\nenter the elemnts of the array : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&ptr[i]);
    }
    printf("\nelements in the array are : ");
    for(i=0;i<n;i++)
    {
        printf(" %d",ptr[i]);

    }
    free(ptr);
    return 0;
}
