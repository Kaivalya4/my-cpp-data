#include<stdio.h>
#include<string.h>
void push(char);
char pop();
char stk[15];
int top=-1;
int main()
{
    char str[20],c;
    int flag=1,i;
    printf("enter the expression : ");
    gets(str);
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]=='(' || str[i] == '{' || str[i] == '[')
            push(str[i]);
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if(top == -1)
                flag=0;
            else
            {
                c=pop();
                if(str[i] ==')'&&(c=='{' || c=='[') )
                    flag=0;
                if(str[i] == '}' && (c=='('|| c=='['))
                    flag=0;
                if(str[i] == ']' && (c=='(' || c== '{'))
                    flag =0;
            }
        }
    }
    if(top>=0)
        flag=0;
    if(flag ==1)
        printf("\nvalid expression .");
    else
        printf("\ninvalid expression .");
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
