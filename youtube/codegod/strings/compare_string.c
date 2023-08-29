#include<stdio.h>
#include<string.h>
int main()
{
    int s1[20],s2[20];
    printf("enter string1 and string2 respectively :\n");
    scanf("%s %s",s1,s2);
    if(strcmp(s1,s2)>0)
        printf("\nstring 1 is greater");
    else if(strcmp(s1,s2)<0)
        printf("\nstring 2 is greater ");
    else
        printf("\nstrings are equal");
    return 0;
}
