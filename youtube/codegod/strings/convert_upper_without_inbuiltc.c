#include<stdio.h>
#include<string.h>
int main()
{
    char a[20];
    printf("enter strings : \n");
    scanf("%s",a);
    for(int i=0;a[i]!=0;i++)
        if(a[i]>='a'&&a[i]<='z')
            a[i]=a[i]-32;
    printf("\n%s",a);
    return 0;
}

