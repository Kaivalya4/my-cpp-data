#include<stdio.h>
#define max 10
int stk[max] , topA= -1 ,topB=max;
void pushA();
int popA();
void peekA();
void displayA();
void pushB();
int popB(void);
void peekB();
void displayB();
int main()
{
    int ch ,val;
    do
    {
        printf("\n\t1.PUSH stack A\n ");
        printf("\t2.PUSH stack B\n ");
        printf("\t3.POP stcak A\n");
        printf("\t4.POP stcak B\n");
        printf("\t5.PEEK stcak A\n");
        printf("\t6.PEEK stcak B\n");
        printf("\t7.DISPLAY stack A\n");
        printf("\t8.DISPLAY stack B\n");
        printf("\t9.exit . \n\n");
        printf("enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : pushA();
                     break;
            case 2 : pushB();
                     break;
            case 3 : val = popA();
                     if(val == -1)
                        printf("\nunderflow.");
                     else
                        printf("\nvalue poped from the top of stack A is : %d",val);
                     break;
            case 4 : val = popB();
                     if(val == -1)
                        printf("\nunderflow.");
                     else
                        printf("\nvalue poped from the top of stack B is : %d",val);
                     break;
            case 5 : peekA();
                     break;
            case 6 : peekB();
                     break;
            case 7 : displayA();
                     break;
            case 8 : displayB();
                     break;
            case 9 : break;
            default : printf("\nenter the valid choice . ");
                      break;

        }
    }while(ch!=9);
    return 0;
}
void pushA()
{
    int val;
    printf("\nenter -1 to stop entering data .");
    printf("\nenter the value to be pushed : ");
    scanf("%d",&val);
    while(val != -1)
    {
        if(topA == topB -1)
        {
            printf("oops ! memory overflow !!!! ");
            break;
        }
        else
        {
            topA++;
            stk[topA]=val;
        }
        printf("\nenter another value to be pushed : ");
        scanf("%d",&val);
    }
}
void pushB()
{
    int val;
    printf("\nenter -1 to stop entering data .");
    printf("\nenter the value to be pushed : ");
    scanf("%d",&val);
    while(val != -1)
    {
        if(topA == topB -1)
        {
            printf("oops ! memory overflow !!!! ");
            break;
        }
        else
        {
            topB--;
            stk[topB]=val;
        }
        printf("\nenter another value to be pushed : ");
        scanf("%d",&val);
    }
}
int popA()
{
    int val;
    if(topA == -1)
    {
        return -1;
    }
    else
    {
        val=stk[topA];
        topA--;
        return val;
    }
}
int popB()
{
    int val;
    if(topB == max)
    {
        return -1;
    }
    else
    {
        val=stk[topB];
        topB++;
        return val;
    }
}
void peekA()
{
    if(topA == -1)
    {
        printf("\nstack is empty");
    }
    else
    {
        printf("value at the top position of stack is : %d ",stk[topA]);
    }
}
void peekB()
{
    if(topB == max)
    {
        printf("\nstack is empty");
    }
    else
    {
        printf("value at the top position of stack is : %d ",stk[topB]);
    }
}
void displayA()
{
    if(topA == -1)
    {
        printf("\nstack is empty .");
    }
    else
    {
        printf("stack is : \n ");
        printf ("\tTOP : \t");
        for(int i=topA;i>=0;i--)
            printf("%d\n\t\t",stk[i]);
    }
}
void displayB()
{
    if(topB == max)
    {
        printf("\nstack is empty .");
    }
    else
    {
        printf("stack is : \n ");
        printf ("\tTOP : \t");
        for(int i=topB;i<10;i++)
            printf("%d\n\t\t",stk[i]);
    }

}
