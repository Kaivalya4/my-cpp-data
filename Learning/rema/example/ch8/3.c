#include<stdio.h>
#define max 10
int queue[max];
int front =-1 ,rear =-1;
int enter();
int del();
int peek();
int display();
int main()
{

    int ch;
    do
    {
        printf("\n1.enter the element .");
        printf("\n2.delete the element .");
        printf("\n3.peek .");
        printf("\n4.display whole queue .");
        printf("\n5.exit .");
        printf("\n\n\tenter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : enter();
                     break;
            case 2 : del();
                     break;
            case 3 : peek();
                     break;
            case 4 : display();
                     break;
            case 5 : break;
            default : printf("\nenter valid choice .");
                      break;

        }
    }while(ch != 5);
    return 0;
}
int enter()
{
   int num;
   printf("\nenter -1 to exit .");
   printf("\nenter data to be added : ");
   scanf("%d",&num);
   while(num !=-1)
   {
       if((front == 0 && rear == max -1) || (front == rear+1))
       {
           printf("\noverflow .");
           return 0;
       }
       if(front == -1 && rear ==-1)
        {
            front = 0;
            rear =0;
            queue[rear] = num;
        }
       else if(front !=0 && rear == max -1 )
        {
            rear =0;
            queue[rear] = num;
        }
       else
        {
            rear ++;
            queue[rear] = num;
        }
        printf("\nenter another data to be added : ");
        scanf("%d",&num);
   }
   return 0;
}
int del()
{
    if(front == -1 && rear ==-1 )
    {
        printf("\nunderflow .");
        return 0;
    }
    int val = queue[front];
    if(front == rear)
        front = rear = -1;
    else if(front == max -1)
        front = 0;
    else
        front = front +1;
    printf("\nvalue deleted from the front position is : %d",val);
    return 0;
}
int peek()
{
    if(front == -1)
    {
        printf("\nqueue is empty .");
        return 0;
    }
    printf("\nvalue at the front position is : %d",queue[front]);
}
int display()
{
    if(front == -1)
    {
        printf("\nqueue is empty .");
        return 0;
    }
    printf("\nfront : ");
    int temp = front;
    while(temp  != rear)
    {
        printf("%d\n\t",queue[temp]);
        if(temp == max -1 )
            temp =0;
        else
            temp ++;
    }
    printf("\rrear :  %d",queue[temp]);
}
