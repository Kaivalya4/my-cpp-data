#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp1,*fp2;
    fp1=fopen("initial.txt","w");
    char ch;
    if(fp1==NULL)
    {
    	fclose(fp1);
        printf("file <initial.txt>not created");
        exit(0);
    }
    while(1)
    {
        ch =getchar();
        if(ch=='.')
            exit(0);
        fputc(ch,fp1);
    }
    fclose(fp1);
    fp2=fopen("final.txt","w");
    fp1=fopen("initial.txt","r");
    while((ch=fgetc(fp1))!=EOF)
    {
        fputc(ch,fp2);
    }
    fclose(fp2);
    fp2=fopen("final.txt","r");
    printf("\ncontents in the copied file are : \n");
    while((ch=fgetc(fp2))!=EOF)
    {
        printf("%d",ch);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
