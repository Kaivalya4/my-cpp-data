//count alphabets,digits,symbols from agiven string
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char a[20];
    int alpha=0,dig=0,sym=0;
    scanf("%s",a);
    for(int i=0;i<strlen(a);i++)  //for(int i=0;a[i}!='\0';i++)
    {
        if(isalpha(a[i]))
            alpha++;
        else if(isdigit(a[i]))
            dig++;
        else
            sym++;
    }
    printf("\nalphabets : %d",alpha);
    printf("\ndigit : %d",dig);
    printf("\nsymbols : %d",sym);
    return 0;
}
