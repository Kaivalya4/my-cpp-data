#include<stdio.h>
#include<string.h>
int stk[400000] , top = -1 , top1 = -1;
int res[400000];
void push();
int main()
{
    int i,n,num;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        char str[10];
        scanf("%s",str);
        if(!strcmp(str,"push"))
        {
            scanf("%d",&num);
            push(num);
        }
        else if(!strcmp(str,"pop"))
        {
            if(stk[top] == res[top1])
            {
                while(res[top1] == res[top] )
                    top1--;
            }
            top--;
        }
        else if(!strcmp(str,"max"))
            printf("%d\n",res[top]);
    }
    return 0;
}
void push(int num)
{
    top++ , top1++;
    stk[top] = num;
    if(num > res[top1-1])
        res[top1] = num;
    else
        res[top1] = res[top-1];
}

