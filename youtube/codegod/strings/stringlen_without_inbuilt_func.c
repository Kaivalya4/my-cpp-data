#include<stdio.h>
int main()
{
    char a[20],len=0;
    printf("enter  string : \n");
    scanf("%s",a);
    for(int i=0;a[i]!=0;i++)
        len++;
    printf("%d",len);
    return 0;
}

