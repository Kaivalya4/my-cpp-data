#include<stdio.h>
int main()
{
    char a[20],b[20];
    printf("enter two strings : \n");
    scanf("%s %s",a,b);
    for(int i=0;b[i]!=0;i++)
        a[i]=b[i];
    printf("%s",a);
    return 0;
}

