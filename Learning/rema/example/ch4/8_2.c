#include<stdio.h>
#include<string.h>
int main()
{
    char str1[30],str2[20],last[40];
    int i=0,j,copy,k=0,len1,len2,l=0;
    printf("Enter the main string : ");
    gets(str1);
    printf("\nenter the substring to be deleted : ");
    gets(str2);
    len2=strlen(str2);
    len1=strlen(str1);
    while(i<len1)
    {
        j=0;l=0;
        while(l<len2)
        {

            if(str1[i+j]==str2[j])
            {
                j++;
            }
           l++ ;
        }
        if(j==len2)
        {
            copy=i+j;
        }
        last[k]=str1[copy];
        copy++;
        k++;
        i++;
    }
    last[k]='\0';
    printf("\n final string is : \n");
    puts(last);
    return 0;
}


