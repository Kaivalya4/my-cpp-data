#include<stdio.h>
#include<string.h>
int main()
{
    char a[20],b[20];
    printf("enter two strings : \n");
    scanf("%s %s",a,b);
    printf("\n%s",strcat(a,b));
    return 0;
}
