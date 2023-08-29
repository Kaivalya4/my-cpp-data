//making transpose.for square matrix
#include<stdio.h>
int main()
{
    int a[5][5],i,m,temp=0;
    scanf("%d%d",&m);
    for(i=0;i<m;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
            printf("%d",a[i][j]);
        printf("\n");
    }
    for(i=0;i<m;i++)
        for(int j=0;j<m;j++)
        {
            if(j>=i)
            {
                temp=a[i][j];
                a[i][j]=a[j][i];
                a[j][i]=temp;
            }
        }
    for(i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
            printf("%d",a[i][j]);
        printf("\n");
    }
    return 0;
}
