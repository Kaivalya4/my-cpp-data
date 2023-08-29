#include<stdio.h>
#include<string.h>
void push(char);
char pop();
char stk[100000];
int top=-1;
int main()
{
    char str[100000],c;
    int flag=1,i,k=0,j=0;
    gets(str);
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]=='(' || str[i] == '{' || str[i] == '[')
        {
            push(str[i]);
            j=i+1;
        }
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if(top == -1)
            {
                k=1;
                flag=0;
                printf("%d",i+1);
                break;
            }
            else
            {
                c=pop();
                j--;
                if(str[i] ==')'&&(c=='{' || c=='[') )
                {
                    k=1;
                    flag=0;
                    printf("%d",i+1);
                    break;
                }
                if(str[i] == '}' && (c=='('|| c=='['))
                {
                    k=1;
                    flag=0;
                    printf("%d",i+1);
                    break;
                }
                if(str[i] == ']' && (c=='(' || c== '{'))
                {
                    k=1;
                    flag =0;
                    printf("%d",i+1);
                    break;
                }
            }
        }
    }
    if(top>=0)
        flag=0;
    if(flag ==1)
        printf("Success");
    if(top != -1 && k !=1)
        printf("%d",j);
    return 0;
}
void push(char ch)
{
    top++;
    stk[top]=ch;
}
char pop()
{
    char c=stk[top];
    top--;
    return c;
}
