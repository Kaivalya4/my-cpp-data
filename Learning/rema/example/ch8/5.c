#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int priority;
    struct node *next;
};
struct node *start = NULL;
struct node *insert(struct node *);
struct node *del(struct node *);
void display(struct node *);
int main()
{
    int ch;
    do
    {
        printf("\n\n1.Insert .");
        printf("\n2.Delete .");
        printf("\n3.Display .");
        printf("\n4.Exit .");
        printf("\n\n\tEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : start = insert(start);
                     break;
            case 2 : start = del(start);
                     break;
            case 3 : display(start);
                     break;
            case 4 : break;
            default : printf("\nEnter any valid choice .");
                      break;
        }
    }while(ch != 4);
    return 0;
}
struct node *insert(struct node *start)
{
    struct node *new_node , *ptr;
    int num , pri;
    printf("\nEnter -1 to stop entering data .");
    printf("\nEnter data to be added and its priority : ");
    scanf("%d%d",&num,&pri);
    while(num !=-1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node -> data = num;
        new_node -> priority = pri;
        if(start == NULL || pri < start -> priority)
        {
            new_node -> next = start;
            start = new_node;
        }
        else
        {
            ptr = start;
            while(ptr -> next -> priority < pri && ptr -> next != NULL)
                ptr = ptr -> next;
            new_node -> next = ptr -> next;
            ptr -> next = new_node;
        }
        printf("\nenter another value to be added and its priority : ");
        scanf("%d%d",&num,&pri);
    }
    return start;
}
struct node *del(struct node *start)
{
    if(start == NULL)
    {
        printf("\nqueue is empty .");
    }
    else
    {
        struct node *ptr;
        ptr = start;
        start = start -> next;
        free(ptr);
    }
    return start;
}
void display(struct node *start)
{

    if(start == NULL)
        printf("\noops ! queue is empty ! ");
    else
    {
        struct node *ptr;
        ptr = start;
        printf("Priority    Data ");
        while(ptr != NULL)
        {
            printf("\n\t%d  -  %d",ptr -> priority , ptr -> data);
            ptr = ptr -> next;
        }
    }
}
