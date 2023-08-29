#include<stdio.h>
#include<string.h>
int main()
{
    char str[20],i=0,len,temp;
    printf("\nenter string to be reversed : ");
    gets(str);
    len=strlen(str)-1;
    while(i<len)
    {
        temp=str[i];
        str[i]=str[len];
        str[len]=temp;
        i++;
        len--;
    }
    printf("\n reversed string is : \n");
    puts(str);
    return 0;
}
