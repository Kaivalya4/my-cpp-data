#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
struct node *push(struct node *);
struct node *pop(struct node *);
void peek(struct node *);
void show(struct node *);
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
            case 1 : top = push(top);
                     break;
            case 2 : top = pop(top);
                     break;
            case 3 : peek(top);
                     break;
            case 4 : show(top);
                     break;
            case 5 : break;
            default : printf("\nenter the valid choice . ");
                      break;

        }
    }while(ch!=5);
    return 0;
}
struct node *push(struct node *top)
{
    struct node *new_node , *ptr;
    int num;
    printf("\nenetr -1 to stop entering data .");
    printf("\nenter the data to be pushed : ");
    scanf("%d",&num);
    while(num != -1)
    {
        new_node=(struct node *)malloc(sizeof(struct node));
        new_node -> data = num;
        new_node -> next = top;
        top = new_node ;
        printf("\nenter the data again to be pushed : ");
        scanf("%d",&num);
    }
    return top;
}
struct node *pop(struct node *top)
{
    struct node *ptr;
    int val;
    if(top == NULL)
    {
        printf("\nunderflow .");
        return top;
    }
    else
    {
        ptr = top;
        top = top -> next;
        printf("\nvalue poped from the top is : %d",ptr -> data);
        free(ptr);
        return top;
    }
}
void  peek(struct node *top)
{
    if(top == NULL)
        printf("\nstack is empty.");
    else
        printf("\nvalue at top position is : %d",top -> data);
}
void show(struct node *top)
{
    if(top == NULL)
        printf("\nstack is empty .");
    else
    {
        struct node *ptr;
        ptr =top;
        printf("\n\nTOP :   ");
        while(ptr != NULL)
        {
            printf("%d\n\t",ptr -> data);
            ptr = ptr->next;
        }
    }
}
