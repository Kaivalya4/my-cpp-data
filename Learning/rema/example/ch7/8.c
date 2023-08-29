#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define max 100
int top=-1;
char stk[max];
void revtopos(char source[] ,char target[]);
void push(char stk[] , char);
char pop(char stk[]);
int getpriority(char );
char rev[100];
void reverse(char exp[]);

int main()
{
    char infix[100] ,  postfix[100];
    printf("enter any infix expression : ");
    gets(infix);
    reverse(infix);
    printf("\nreverse of infix expression :  ");
    puts(rev);
    revtopos(rev,postfix);
    printf("\ncorresponding postfix expression is  : ");
    puts(postfix);
    reverse(postfix);
    printf("\ncorresponding prefix expression is  : ");
    puts(rev);
    return 0;
}
void reverse(char exp[])
{
    int i=0 , j=0;
    for(i=strlen(exp)-1 ;i>=0;i--)
    {
        if(exp[i] == '(')
            rev[j] = ')';
        else if(exp[i] == ')')
            rev[j] = '(';
        else
            rev[j] = exp[i];
        j++;
    }
    rev[j] = '\0';
}
void revtopos(char source[],char target[])
{
    int i=0,j=0;
    while(source[i]!='\0')
    {
        if(source[i] == '(')
        {
            push(stk,source[i]);
            i++;
        }
        else if(source[i] == ')')
        {
            while((top !=-1) &&(stk[top]!='('))
            {
                target[j] = pop(stk);
                j++;
            }
            if(top == -1)
            {
                printf("\nincorrect expression .");
                exit(0);
            }
            pop(stk);
            i++;
        }
        else if(isalnum(source[i]))
        {
            target[j] = source[i];
            j++;
            i++;
        }
        else if(source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '%')
        {
            while((top!=-1) && (stk[top] !='(') && (getpriority(stk[top]) >= getpriority(source[i])))
            {
                target[j]=pop(stk);
                j++;
            }
            push(stk,source[i]);
            i++;
        }
        else
        {
            printf("\nincorrect element in expression .");
            exit(0);
        }
    }
   while((top!=-1) && (stk[top]!='('))
    {
        target[j] = pop(stk);
        j++;
    }
    target[j]='\0';
}
void push(char stk[] ,char ch)
{
    if(top == max-1)
        printf("\noverflow .");
    else
    {
        top++;
        stk[top]=ch;
    }
}
char pop(char stk[])
{
    int ch;
    if(top == -1)
        printf("\nunderflow .");
    else
    {
        ch = stk[top];
        top--;
    }
    return ch;
}
int getpriority(char ch)
{
    if(ch == '*' || ch == '/' || ch == '%')
        return 1;
    else if(ch == '+' || ch == '-')
        return 0;
}
