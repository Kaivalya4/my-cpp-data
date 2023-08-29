#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define max 100
float stk[max];
int top =-1;
void poseval(char exp[]);
void push(float);
float pop();
void preeval(char source[]);
int main()
{
    char prefix[100] ;
    printf("enter any prefix expression : ");
    gets(prefix);
    preeval(prefix);
    printf("answer after the evaluation of postfix notation : ");
    printf("%f",pop());
    return 0;
}
void preeval(char source[])
{
    int len=strlen(source)-1;
    float value , op1 , op2;
    for(int i=len ; i>=0;i--)
    {
        if(isdigit(source[i]))
            push((float)(source[i] -'0'));
        else
        {
            op1 = pop();
            op2 = pop();
            switch(source[i])
            {
                case '+': value = op1 + op2;
                          break;
                case '-': value = op1 - op2;
                          break;
                case '*': value = op1 * op2;
                          break;
                case '/': value = op1 / op2;
                          break;
                case '%': value = (int)op1 % (int)op2 ;
                          break;
            }
            push((float)(value));
        }
    }
}
void push(float fl)
{
    if(top == max-1)
    {
        printf("\noverflow");
        exit(0);
    }
    else
    {
        top++;
        stk[top]=fl;
    }
}
float pop()
{
    float ch;
    if(top == -1)
    {
        printf("\nunderflow .");
        exit(0);
    }
    else
    {
        ch = stk[top];
        top--;
        return ch;
    }
}
