#include<stdio.h>
int main()
{
    int a[5][5],j,i,m,n,temp=0;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d",a[i][j]);
        printf("\n");
    }

    for(j=0;j<n;j++)
    {
        for(i=0;i<m;i++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    /* for(i=0;i<m;i++)      //this will not work
    {
        for(int j=0;j<n;j++)
            printf("%d",a[j][i]);
        printf("\n");
    }*/
    return 0;
}
