#include<stdio.h>
int main()
{
    int a[5][5],b[5][5],c[5][5],m,i,j,k;
    scanf("%d",&m);
    for(i=0;i<m;i++)
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<m;i++)
        for(j=0;j<m;j++)
            scanf("%d",&b[i][j]);
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
            printf("%d",a[i][j]);
        printf("\n");
    }
    for(i=0;i<m;i++)
     {
         for(j=0;j<m;j++)
            printf("%d",b[i][j]);
        printf("\n");
     }
    for(i=0;i<m;i++)
        for(j=0;j<m;j++)
        {
            c[i][j]=0;
            for(k=0;k<m;k++)
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
        }
     for(i=0;i<m;i++)
     {
         for(j=0;j<m;j++)
            printf("%d ",c[i][j]);
        printf("\n");
     }
    return 0;

}
