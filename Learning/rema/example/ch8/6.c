#include<stdio.h>
#define max 10
int rearA = -1 , frontA = -1 , rearB = max , frontB = max;
int q[max];
void insA();
void insB();
void delA();
void delB();
void disA();
void disB();
int main()
{
    int ch;
    do
    {
        printf("\n\n1.Insert in queue A.");
        printf("\n2.Insert in queue B.");
        printf("\n3.Delete from queue A.");
        printf("\n4.Delete from queue B.");
        printf("\n5.Display queue A.");
        printf("\n6.Display queue B.");
        printf("\n7.Exit .");
        printf("\n\n\tEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : insA();
                     break;
            case 2 : insB();
                     break;
            case 3 : delA();
                     break;
            case 4 : delB();
                     break;
            case 5 : disA();
                     break;
            case 6 : disB();
                     break;
            case 7 : break;
            default : printf("\nEnter any valid choice .");
                      break;
        }
    }while(ch != 7);
    return 0;
}
void insA()
{
    int num;
    printf("\nenter -1 to stop entering .");
    printf("\nenter data to be added : ");
    scanf("%d",&num);
    while(num != -1)
    {
        if(rearA == rearB -1)
        {
            printf("\noverflow !");
            break;
        }
        else
        {
            if(rearA == -1 ||  frontA== -1)
            {
                rearA =frontA =0;
                q[rearA] = num;
            }
            else
            {
                rearA++;
                q[rearA] = num;
            }
        }
        printf("\nenter another data to be added : ");
        scanf("%d",&num);
    }
}
void insB()
{
    int num;
    printf("\nenter -1 to stop entering .");
    printf("\nenter data to be added : ");
    scanf("%d",&num);
    while(num != -1)
    {
        if(rearA == rearB -1)
        {
            printf("\noverflow !");
            break;
        }
        else
        {
            if(rearB == max ||  frontB== max)
            {
                rearB =frontB =max -1;
                q[rearB] = num;
            }
            else
            {
                rearB--;
                q[rearB] = num;
            }
        }
        printf("\nenter another data to be added : ");
        scanf("%d",&num);
    }
}
void delA()
{
    if(frontA == -1 || frontA >rearA)
    {
        printf("\nunderflow !");
        rearA = frontA = -1;
    }
    else
    {
        printf("\nelement deleted is : %d",q[frontA]);
        frontA++;
    }
}
void delB()
{
    if(frontB == max ||frontB <rearB)
    {
        printf("\nunderflow !");
        rearB = frontB = max;
    }
    else
    {
        printf("\nelement deleted is : %d",q[frontB]);
        frontB--;
    }
}
void disA()
{
    if(frontA == -1)
        printf("\nqueue A is empty .");
    else
    {
        int i;
        printf("\nfront of A :  ");
        for(i=frontA;i<rearA;i++)
        {
            printf("%d\n\t    ",q[i]);
        }
        printf("\rrear of A : %d",q[i]);
    }
}
void disB()
{
    if(frontB == max)
        printf("\nqueue B is empty .");
    else
    {
        int i;
        printf("\nfront of B :  ");
        for(i=frontB;i>rearB;i--)
        {
            printf("%d\n\t    ",q[i]);
        }
        printf("\rrear of B : %d",q[i]);
    }
}


