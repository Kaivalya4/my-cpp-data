#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define max 100
float stk[max];
int top =-1;
void poseval(char exp[]);
void push(float);
float pop();
int main()
{
    char exp[100];
    printf("enter any postfix expression :");
    gets(exp);
    poseval(exp);
    printf("answer after the evaluation of postfix notation : ");
    printf("%f",pop());
    return 0;
}
void poseval(char source[])
{
    int i=0;
    float op1 ,op2 , value;
    while(source[i] !='\0')
    {
        int temp[2];
        if(isalnum(source[i]))
        {
            push((float)(source[i]-'0'));
        }
        else
        {
            op2 = pop();
            op1 = pop();
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
        i++;
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
