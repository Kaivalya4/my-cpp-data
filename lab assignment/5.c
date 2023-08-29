#include<stdio.h>
#include<string.h>
struct player
{
    char name[20];
}ply[11];
int main()
{
    int n,count1=0,count2=0;
    printf("enter number of players : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nname of player%d ",i+1);
        scanf("%s",ply[i].name);
    }
    char str[20];
    for(int i=0;i<n;i++)
    {
        count1=0;
        int len=strlen(ply[i].name);
       if(ply[i].name[len-3]=='k')count1++;
       if(ply[i].name[len-2]=='a')count1++;
       if(ply[i].name[len-1]=='r')count1++;
       if(count1==3)
        count2++;
    }
    printf("\nnumber of players with name ending with kar is :%d",count2);
   return 0;
}
