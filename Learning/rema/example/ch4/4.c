#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char str1[30],str2[30],i=0,len1,len2;
    printf("enter the string 1 : ");
    gets(str1);
    printf("\nentre the string 2: ");
    gets(str2);
    len1=strlen(str1);
    len2=strlen(str2);
    if(len1 != len2)
    {
        printf("\nstrings are not equal!!");
        exit(0);
    }
    else
    {
        while(i<len1)
        {
            if(str1[i] == str2[i])
                i++;
            else if(str1[i]>str2[i])
            {
                printf("\nstr1 comes after str2");
                exit(0);
            }
            else
             {
                 printf("\nstr2 comes after str1");
                 exit(0);
             }
        }
    }
    if(i == len1)
        printf("\nstrings are equal : ");
    return 0;
}
