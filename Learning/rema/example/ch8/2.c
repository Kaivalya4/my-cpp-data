#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct queue
{
    struct node *front;
    struct node *rear;
};
struct queue *insert_q(struct queue *);
struct queue *del(struct queue *);
void peek(struct queue *);
void display(struct queue *);
int main()
{
    printf("hello !");
    struct queue *q;
    q -> front  = NULL;
    q -> rear = NULL;
    int ch = 0;
    do
    {
        printf("\n1.Insert elements .");
        printf("\n2.Delete the element .");
        printf("\n3.Peek .");
        printf("\n4.display whole queue .");
        printf("\n5.exit .");
        printf("\n\n\tenter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : q = insert_q(q);
                     break;
            case 2 : q = del(q);
                     break;
            case 3 : peek(q);
                     break;
            case 4 : display(q);
                     break;
            case 5 : break;
            default : printf("\nenter valid choice .");
                      break;

        }
    }while(ch != 5);
    return 0;
}
struct queue *insert_q(struct queue *q)
{
    struct node *new_node;
    int num;
    printf("\nenter -1 to exit entering data .");
    printf("\nenter the data to be added : ");
    scanf("%d",&num);
    while( num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node ));
        new_node -> data = num;
        if( q -> front == NULL)
        {
            q -> front = new_node;
            q -> rear = new_node;
            q -> front -> next = NULL;
            q -> rear -> next = NULL;
        }
        else
        {
            q -> rear -> next = new_node;
            q -> rear = new_node;
            q -> rear -> next = NULL;
        }
        printf("\nenter other datak to be added : ");
        scanf("%d",&num);
    }
    return q;
}
struct queue *del(struct queue *q)
{
    if(q -> front == NULL )
    {
        printf("\nunderflow .");
    }
    else
    {
        struct node *ptr;
        ptr = q -> front;
        q -> front = q -> front -> next;
        free(ptr);
    }
    return q;
}
void peek(struct queue *q)
{
    if(q -> front == NULL)
        printf("\nunderflow .");
    else
        printf("\nvalue at position front : %d",q -> front -> data);
}
void display(struct queue *q)
{
    if(q -> front == NULL)
        printf("\nunderflow .");
    else
    {
        struct queue *ptr;
        ptr -> front = q -> front;
        while(ptr -> front == q -> rear) ;
    }
}
