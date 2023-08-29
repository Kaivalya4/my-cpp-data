#include<stdio.h>
#include<string.h>
int main()
{
    char s1[]="kaivalya";
    char s2[20];
    printf("\n%s",strrev(s1));
    printf("%s\n",strlen(s1));
    printf("%s\n",strupr(s1));
    printf("%s\n",strlwr(s1));
    strcpy(s2,s1);
    printf("%s",s2);
    return 0;
}

