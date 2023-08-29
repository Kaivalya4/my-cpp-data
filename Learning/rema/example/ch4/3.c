#include<stdio.h>
#include<string.h>
int main()
{
    char str1[30],str2[30],i,len1=0,len2;
    printf("enter the destination string : ");
    gets(str1);
    printf("\nentre the string to be copied : ");
    gets(str2);
    for(i=0;str1[i]!='\0';i++)len1++;
    len2=strlen(str2);
   /* for(i=0;i<len2;i++)
    {
        str1[len1]=str2[i];
        len1++;
    }
    str1[len1]='\0';
    len1=len1+len2;
    printf("\nwithout inbuilt function : \n");
    puts(str1);*/
    printf("with inbuilt function : \n");
    strcat(str1,str2);
    len1=len1+len2;
    for(i=0;i<len1;i++)
    {
       printf("%c",str1[i]);
    }
    return 0;
}
