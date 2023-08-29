#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start =NULL;
struct node *create(struct node *);
void show(struct node *);
struct node *add_beg(struct node *);
void add_last(struct node *);
void add_after(struct node *);
void add_before(struct node *);
struct node *del_beg(struct node *);
void del_last(struct node *);
void del_after(struct node *);
struct node * del_given(struct node *);
int main()
{
    int ch;
    do
    {
        printf("\t\t\t\t\t\tMain Menu \n\n");
        printf("\t1.create the list .\n ");
        printf("\t2.display the list . \n");
        printf("\t3.Add node at start . \n");
        printf("\t4.Add node at the end . \n");
        printf("\t5.Add node after a given node . \n");
        printf("\t6.Add node before a given node . \n");
        printf("\t7.delete the starting node . \n");
        printf("\t8.delete the last node . \n");
        printf("\t9.delete the node after the given node . \n");
        printf("\t10.delete the given node . \n");
        printf("\t11.delete the entire list . \n");
        printf("\t13.exit . \n\n");
        printf("enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : start = create(start);
                     printf("\nlinked list created . ");
                     break;
            case 2 : show(start);
                     break;
            case 3 : start = add_beg(start);
                     printf("\nlist successfully updated .");
                     break;
            case 4 : add_last(start);
                     printf("\nlist successfully updated .");
                     break;
            case 5 : add_after(start);
                     printf("\nlist successfully updated .");
                     break;
            case 6 : add_before(start);
                     printf("\nlist successfully updated .");
                     break;
            case 7 : start=del_beg(start);
                     printf("\nlist successfully updated .");
                     break;
            case 8 : del_last(start);
                     printf("\nlist updated successfully .");
                     break;
            case 9 : del_after(start);
                     printf("\nlist updated successfully .");
                     break;
            case 10 : start= del_given(start);
                      printf("\nlist updated successfully .");
                      break;

        }

    }while(ch!=13);
    return 0;

}
struct node *create(struct node * start)
{
    struct node *new_node , *ptr;
    int num;
    printf("\nenter -1 to exit ");
    printf("\nenter the data for the linked list : ");
    scanf("%d",&num);
    while(num!=-1)
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        new_node -> data =num;
        if(start == NULL)
        {
            start = new_node;
            new_node -> next = NULL;
        }
        else
        {
            ptr=start;
            while(ptr -> next != NULL)
                ptr = ptr -> next ;
            ptr -> next =new_node;
            new_node -> next =NULL;
        }
        printf("\nenetr the next data for the linked list : ");
        scanf("%d",&num);
    }
    return start ;
}
void show(struct node *start)
{
    struct node *ptr;
    if(start != NULL)
    {
        ptr=start;
        printf("\n");
        while(1)
        {
            printf(" %d",ptr -> data);
            if(ptr ->next == NULL)
                break;
            ptr =ptr ->next;
        }
    }
  else
        printf("\nlist is empty .");
}
struct node *add_beg(struct node *start)
{
    struct node *new_node,*temp = NULL;
    int num;
    printf("\nenter the new data to be added at the beginning : ");
    scanf("%d",&num);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node -> data=num;
    temp = new_node;
    new_node -> next =start;
    start=temp;
};
void add_last(struct node *start)
{
    struct node*new_node,*ptr,*temp;
    int num;
    printf("\nenter the new data to be added at the beginning : ");
    scanf("%d",&num);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node ->data =num;
    ptr=start;
    while(ptr ->next !=NULL )
        ptr=ptr -> next;
    ptr ->next =new_node;
    new_node ->next =NULL;
}
void add_after(struct node *start)
{
    struct node *new_node,*ptr ,*preptr;
    int num,val;
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("\nenter the data to be added : ");
    scanf("%d",&num);
    printf("\nenetr the data after which node to be added : ");
    scanf("%d",&val);
    new_node ->data = num;
    ptr=start;
    preptr =ptr;
    while(preptr ->data !=val )
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr -> next =new_node;
    new_node ->next = ptr;
}
void add_before(struct node *start)
{
    struct node *new_node,*ptr ,*preptr;
    int num,val;
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("\nenter the data to be added : ");
    scanf("%d",&num);
    printf("\nenetr the data after which node to be added : ");
    scanf("%d",&val);
    new_node ->data = num;
    ptr=start;
    preptr =start;
    while(ptr ->data !=val )
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr -> next =new_node;
    new_node ->next = ptr;
}
struct node *del_beg(struct node *start)
{
    struct node *ptr;
    ptr=start;
    start=start-> next;
    free(ptr);
    return start;
}
void del_last(struct node *start)
{
    struct node *ptr,*preptr;
    ptr=start;
    preptr=start;
    while(ptr->next !=NULL)
    {
        preptr=ptr;
        ptr=ptr-> next;
    }
    preptr -> next =NULL;
    free(ptr);
}
void del_after(struct node *start)
{
    struct node *preptr ,*ptr;
    int num;
    printf("\nenter the value after the node to be deleted : ");
    scanf("%d",&num);
    ptr=start;
    preptr=start;
    while(preptr ->data != num)
    {
        preptr = ptr;
        ptr = ptr -> next;
    }
    preptr -> next = ptr ->next;
    free(ptr);
}
struct node * del_given(struct node *start)
{
    struct node *preptr , *ptr;
    int num;
    printf("\nenter the value to be deleted from the list : ");
    scanf("%d",&num);
    preptr = start;
    ptr = start;
    if(ptr -> data == num)
    {
        start = del_beg(start);
        return start;
    }
    else
    {
        while(ptr -> data != num)
        {
            preptr =ptr;
            ptr = ptr-> next;
        }
        preptr ->next = ptr ->next ;
        free(ptr);
        return start;
    }
}
struct node *del_list(struct node *start)
{
    struct node *ptr,*preptr;
    preptr=start;
    ptr=start;
    while(ptr != NULL)
    {
        preptr=ptr;
        free(preptr);
        ptr=ptr->next;
    }
    start = NULL;
    return start;
}
