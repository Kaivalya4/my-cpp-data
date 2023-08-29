#include<stdio.h>
int main()
{
    int a[20],i,n,temp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("descending order - ");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
     for(i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]<a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("ascending order - ");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}
