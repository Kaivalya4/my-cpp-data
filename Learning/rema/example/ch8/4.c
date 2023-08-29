#include<stdio.h>
#define max 10
int dq[max];
int left = -1 , right =-1;
int inputres();
int outputres();
void insright();
void insleft();
int delleft();
int delright();
int display();
int main()
{
    int ch;
    printf("\n1.Input restricted dequeue .");
    printf("\n2.Output restricted dequeue .");
    printf("\n\nEnter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1 : inputres();
                 break;
        case 2 : outputres();
                 break;
        default : printf("\noops invalid choice !");
    }
    return 0;
}
int inputres()
{
    int ch;
    do
    {
        printf("\n\n1.Insert at right .");
        printf("\n2.Delete from right .");
        printf("\n3.Delete from left .");
        printf("\n4.Display .");
        printf("\n5.Exit .");
        printf("\n\n\tEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : insright();
                     break;
            case 2 : delright();
                     break;
            case 3 : delleft();
                     break;
            case 4 : display();
                     break;
            case 5 : break;
            default : printf("\nEnter any valid choice .");
                      break;
        }
    }while(ch != 5);
    return 0;
}
int outputres()
{
    int ch;
    do
    {
        printf("\n\n1.Insert at right .");
        printf("\n2.Insert at left .");
        printf("\n3.Delete from left .");
        printf("\n4.Display .");
        printf("\n5.Exit .");
        printf("\n\n\tEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : insright();
                     break;
            case 2 : insleft();
                     break;
            case 3 : delleft();
                     break;
            case 4 : display();
                     break;
            case 5 : break;
            default : printf("\nEnter any valid choice .");
                      break;
        }
    }while(ch != 5);
    return 0;
}
void insright()
{
    int num;
    printf("\nenter -1 to stop enetering .");
    printf("\nenter data to be added : ");
    scanf("%d",&num);
    while(num != -1)
    {
        if(right == left -1 ||(left == 0 && right == max -1))
        {
            printf("\noverflow !");
            break;
        }
        if(left == -1 && right == -1)
        {
            left =0 ;
            right =0 ;
            dq[right] = num;
        }
        else if(right == max -1 && left !=0)
        {
            right = 0;
            dq[right] = num;
        }
        else
        {
            right ++ ;
            dq[right] = num;
        }
        printf("\nenetr another value to be added : ");
        scanf("%d",&num);
    }
}
void insleft()
{
    int num;
    printf("\nenter -1 to stop enetering .");
    printf("\nenter data to be added : ");
    scanf("%d",&num);
    while(num !=-1)
    {
        if(right == left -1 || (left == 0 && right == max -1))
        {
            printf("\noverflow !");
            break;
        }
        if(left == -1 && right == -1)
        {
            left = right = 0;
            dq[left] = num;
        }
        else if(left == 0)
        {
            left = max -1;
            dq[left] = num;
        }
        else
        {
            left --;
            dq[left] = num ;
        }
        printf("\nenter another value to be added : ");
        scanf("%d",&num);
    }
}
int delleft()
{
    if(left == -1 || right == -1)
    {
        printf("\nunderflow .");
        return 0;
    }
    int val = dq[left];
    if(left == max -1)
    {
        if(left == right)
            left = right = -1;
        else
            left = 0;
    }
    else
        left ++;
    printf("\nvalue deleted = %d",val);
}
int delright()
{
    if(left == -1 || right == -1)
    {
        printf("\nunderflow !");
        return 0;
    }
    int val = dq[right];
    if(right == 0)
    {
        if(left == right)
            left = right =  -1;
        else
            right =max -1;
    }
    else
        right --;
    printf("\nvalue deleted is = %d",val);
}
int display()
{
    if(left == -1 || right == -1 )
    {
        printf("\ndequeue is empty .");
        return 0;
    }
    int front = left ,rear = right;
    if(front >= rear)
    {
        printf("\nLeft :  ");
        while(front != rear )
        {
            if(front == max -1)
            {
                printf("%d\n\t",dq[front]);
                front = 0;
            }
            else
            {
                printf("%d\n\t",dq[front]);
                front ++;
            }
        }
        printf("\rRight : %d",dq[front]);
    }
    else
    {
        printf("\nLeft :  ");
        while(front != rear)
        {
            printf("%d\n\t",dq[front]);
            front++;
        }
        printf("\rRight : %d",dq[front]);
    }
}
