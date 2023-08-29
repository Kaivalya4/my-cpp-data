#include<stdio.h>
#define max 6
int stk[max] , top = -1;
void push(int);
int pop(void);
void peek();
void display();
int main()
{
    int ch , val;
    do
    {
        printf("\n\t1.PUSH\n ");
        printf("\t2.POP\n");
        printf("\t3.PEEK\n");
        printf("\t4.DISPLAY\n");
        printf("\t5.exit . \n\n");
        printf("enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : printf("\nenter the value to be pushed : ");
                     scanf("%d",&val);
                     push(val);
                     break;
            case 2 : val = pop();
                     if(val == -1)
                        printf("\nunderflow.");
                     else
                        printf("\nvalue poped from the top is : %d",val);
                     break;
            case 3 : peek();
                     break;
            case 4 : display();
            case 5 : break;
            default : printf("\nenter the valid choice . ");
                      break;

        }
    }while(ch!=5);
    return 0;
}
void push(int val)
{
    if(top == max-1)
    {
        printf("\nOverflow !!!!");
    }
    else
    {
        top++;
        stk[top]=val;
    }

}
int pop()
{
    int val;
    if(top == -1)
    {
        return -1;
    }
    else
    {
        val=stk[top];
        top--;
        return val;
    }
}
void peek()
{
    if(top == -1)
    {
        printf("\nstack is empty");
    }
    else
    {
        printf("value at the top position of stack is : %d ",stk[top]);
    }
}
void display()
{
    if(top == -1)
    {
        printf("\nstack is empty .");
    }
    else
    {
        printf("stack is : \n ");
        printf ("\tTOP : \t");
        for(int i=top;i>=0;i--)
            printf("%d\n\t\t",stk[i]);
    }
}
