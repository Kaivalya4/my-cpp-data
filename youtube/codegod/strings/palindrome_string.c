//string whose reverse is same string is called palindrome string
#include<stdio.h>
#include<stdlib.h>
 int main()
{
    char a[20],b[20];
    int len=0;
    printf("enter strings : \n");
    scanf("%s",a);
    for(int i=0;a[i]!='\0';i++)
        len++;
    for(int i=len-1;i>=0;i++)
        b[i]=a[i];
    for(int i=0;i<len;i++)
    {
        if(a[i]!=b[i])
        {
            printf("\nnot palindrome");
            exit(0);
        }
    }
    printf("\npalindrome");
    return 0;
}
