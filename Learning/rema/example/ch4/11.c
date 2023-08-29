#include<stdio.h>
#include<string.h>
int main()
{
    char text[1000];
    int i,word,line,ch;
    line=word=ch=0;
    printf("\t\t\t\t\tenter ! to exit : \n\t\t\t\t\t******************\n");
    for(i=0;i<1000;i++)
    {
        text[i]=getchar();
        if(text[i]=='!')
            break;
    }
    for(i=0;text[i]!='!';i++)
    {
        if(text[i] == '\n')
            line++;
        if(text[i]== ' '&&text[i+1]!=' ')
            word++;
        ch++;
    }
    printf("\nnumber of lines = %d",line+1);
    printf("\nnumber of words = %d",word);
    printf("\nnumber of characters(incl. spaces) = %d",ch);
    printf("\nnumber of characters(without any spaces) = %d",ch-word);
    return 0;
}

