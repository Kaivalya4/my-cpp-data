#include<stdio.h>
int main()
{
    char str1[30],text[30], finalstr[70];
    int i=0,j=0,pos,k=0;
    printf("Enter the destination string : ");
    gets(str1);
    printf("\nenter the string to be entered  : ");
    gets(text);
    printf("\nenter the position where the string to be entered : ");
    scanf("%d",&pos);
    while(str1[i]!='\0')
    {
        if( i == pos)
        {
            while(text[j]!='\0')
            {
                finalstr[k]=text[j];
                j++;
                k++;
            }
            i++;
        }
        else
        {
            finalstr[k]=str1[i];
            i++;
            k++;
        }
    }
    finalstr[k]='\0';
    printf("\n final string is : \n");
    puts(finalstr);
    return 0;
}
