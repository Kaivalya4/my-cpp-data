#include<stdio.h>
#include<string.h>
int main()
{
    char a[20],b[20];
    int i,j=0,len=0;
    printf("enter two strings : \n");
    scanf("%s %s",a,b);
    for(i=0;a[i]!='\0';i++)
        len++;
    for(i=len;b[j]!='0';i++)
    {
        a[i]=b[j];
        j++;
    }
    printf("%s",a);
    return 0;
}

