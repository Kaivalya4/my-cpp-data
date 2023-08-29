#include<stdio.h>
int main()
{
    char str1[30],last[40];
    int i=0,j=0,pos,k=0,len;
    printf("Enter the main string : ");
    gets(str1);
    printf("\nenter the length of the string to be deleted : ");
    scanf("%d",&len);
    printf("\nenter the position from where the substring is to be deleted : ");
    scanf("%d",&pos);
    while(str1[i]!='\0')
    {
        if( i == pos)
        {
            while(len>0)
            {
                len--;
                i++;
            }
        }
        else
        {
            last[k] = str1[i];
            i++;
            k++;
        }
    }
    last[k]='\0';
    printf("\n final string is : \n");
    puts(last);
    return 0;
}

