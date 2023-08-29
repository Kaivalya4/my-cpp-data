#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    printf("enter the string : ");
    gets(str);
    int count=0,count1=0,len=0; len=strlen(str);
   // for(int i=0;str[i]!='\0';i++)
    //{
      //  len++;
    //}
    printf(" \n%d\n",len);
    for(int i=0;i<len;i++)
    {
        if(str[i]==' '&&str[i+1]!=' ')
            count++;
        if(str[i]==' ')
            count1++;
    }
    printf("\nnumber of characters(without space) = %d",len-count1);
    printf("\nnumber of characters(with space) = %d",len);
    printf("\nnumber of words = %d",count+1);
   return 0;
}

