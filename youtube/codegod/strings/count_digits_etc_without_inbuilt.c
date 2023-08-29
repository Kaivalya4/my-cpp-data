#include<stdio.h>
#include<string.h>
int main()
{
    char a[20];
    int alpha=0,digit=0,sym=0;
    printf("enter strings : \n");
    scanf("%s",a);
    for(int i=0;a[i]!='\0';i++)
        if((a[i]>=65&&a[i]<=90)||(a[i]>=95&&a[i]<=120))
            alpha++;
        else if(a[i]>='0'&&a[i]<='9')
            digit++;
        else
            sym++;
    printf("\nalpha=  %d \n digit=%d \n sym=%d",alpha,digit,sym);
    return 0;
}

