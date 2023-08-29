#include<stdio.h>
#define max 20
int queue[max];
int front =-1 , rear = -1;
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
    int val;
    printf("\nenter -1 to exit .");
    printf("\nenter the value to be added : ");
    scanf("%d",&val);
    while(val != -1)
    {
        if(rear == max -1 )
        {
            printf("\nmemory overflow .");
            return 0;
        }
        else
        {
            if (front == -1 &&  rear == -1)
                front = 0;
            rear +=1;
            queue[rear] = val;
        }
        printf("enter another value to be added : ");
        scanf("%d",&val);
    }
}
int del()
{
    if(front == -1 && front > rear)
    {
       // front = rear = -1;
        printf("\nunderflow .");
        return 0;
    }
    int val = queue[front];
    front ++ ;
    printf("\nvalue deleted from the queue is  : %d",val);
}
int peek()
{
    if(front == -1 && front >rear)
    {
        printf("\nqueue is empty .");
        return 0;
    }
    printf("value present at the front is : %d",queue[front]);
}
int display()
{
    if(front == -1 && front >rear)
    {
        printf("\nqueue is empty .");
        return 0;
    }
    int i;
    printf("\nvalue in the queues are : \n");
    printf("front : ");
    for(i= front ; i<rear ; i++)
    {
        printf("%d\n\t",queue[i]);
    }
    printf("\rrear  : %d",queue[i]);
}
