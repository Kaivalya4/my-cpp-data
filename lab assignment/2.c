#include<stdio.h>
#include<math.h>
int main()
{
    int i,n,num=0;
    printf("enter number = ");
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        while(i!=0)
        {
           num=i%10;
           num+=pow(num,3);
           i=i/10;
        }
        if(i==num)
            printf("%d ",i);
    }
    return 0;
}

