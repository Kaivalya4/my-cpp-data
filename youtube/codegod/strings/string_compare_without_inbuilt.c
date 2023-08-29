#include<stdio.h>
#include<stdlib.h>
int main()
{
    char a[20],b[20];
    printf("enter two strings : \n");
    scanf("%s %s",a,b);
    int len1=0,len2=0;
    for(int i=0;a[i]!='\0';i++)
        len1++;
    for(int i=0;b[i]!='\0';i++)
        len2++;
    if(len1>len2)
    {
        for(int i=0;a[i]!='\0';i++)
        {
            if(a[i]>b[i])
            {
                printf("string 1 is greater");
                exit(0);
            }
            else
            {
                printf("string 2 is greater");
                exit(0);
            }
        }
    }
    else
    {
        for(int i=0;b[i]!='\0';i++)
        {
            if(a[i]>b[i])
            {
                printf("string 1 is greater");
                exit(0);
            }
            else
            {
                printf("string 2 is greater");
                exit(0);
            }
        }
    }
    return 0;
}

