#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char *ch;
    ch=(char*)malloc(10);
    if(ch == NULL)
    {
        printf("memory cannot be allocated ");
        exit(0);
    }
    strcpy(ch,"hi");
    printf("\n%s",ch);
    ch=realloc(ch,20);
    if(ch == NULL)
    {
        printf("\nnew memory cannot be alloctaed");
        exit(0);
    }
    strcpy(ch,"hi there");
    printf("\n%s",ch);
    free(ch);
    return 0;
}
