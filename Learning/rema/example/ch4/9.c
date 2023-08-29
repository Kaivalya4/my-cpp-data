#include<stdio.h>
#include<string.h>
int main()
{
    char str1[90],str2[20],str3[20],last[100];
    int i=0,j=0,I,t=0,len1,len2,len3,k=0;
    printf("Enter the main string : ");
    gets(str1);
    printf("\nenter the substring to be removed : ");
    gets(str2);
    printf("\nenter the substring to be entered : ");
    gets(str3);
    len2=strlen(str2);
    len1=strlen(str1);
    len3=strlen(str3);
    while(i<len1)
    {
        j=0;
        while(j<len2&&str1[i+j]==str2[j])
        {
            j++;
        }
        if(j==len2)
        {
            I=i;
            k=i+j;
            break;
        }
        i++;
    }
    i=0;
    while(i<len1)
    {
        if(i==I)
        {
            for(j=0;j<len3;j++)
            {
                last[t]=str3[j];
                t++;
            }
            i=k;
        }
        last[t]=str1[i];
        i++;
        t++;
    }
    last[t]='\0';
    printf("\n final string is : \n");
    puts(last);
    return 0;
}


