#include<stdio.h>
#include<stdlib.h>
struct node
{
    int node_data;
    struct node *next;
};
void create(struct node *adj[], int n);
void display(struct node *adj[], int n);
void del(struct node *adj[] , int n);
int main()
{
    struct node *adj[10];
    int n;
    printf("Enter number of node of graphs : ");
    scanf("%d",&n);
    for(int i=0 ;i<n;i++)
        adj[i] = NULL;
    create(adj,n);
    printf("\nyour graph is : \n");
    display(adj,n);
    printf("\npress any key to delete the graph : - ");
    del(adj,n);
    printf("\ngraph successfully deleted .");
    return 0;
}
void create(struct node *adj[] , int n)
{
    struct node *new_node, *ptr;
    int i,j,num,val;
    for(i =0 ;i<n;i++)
    {
        ptr = NULL;
        printf("\nEnter number of neighbour of %d  : ",i);
        scanf("%d",&num);
        for(j=1;j<=num;j++)
        {
            printf("\nEnter the data for neighbour number %d of %d : ",j,i);
            scanf("%d",&val);
            new_node = (struct node *)malloc(sizeof(struct node)) ;
            new_node -> node_data = val ;
            new_node -> next = NULL;
            if(adj[i] == NULL)
                adj[i] = new_node;
            else
                ptr -> next = new_node;
            ptr = adj[i];
        }
    }
}
void display(struct node *adj[],int n)
{
    struct node *ptr;
    ptr = adj[0];
    int i;
    for(i=0; i<n ;i++)
    {
        ptr = adj[i];
        printf("The neighbours of node %d are : ",i );
        while(ptr != NULL)
        {
            printf("%d ",ptr -> node_data);
            ptr = ptr -> next;
        }
    }
}
void del(struct node *adj[] , int n)
{
    struct node *ptr , *temp;
    int i;
    for(i =0 ;i< n;i++)
    {
        ptr = adj[i];
        while( ptr != NULL)
        {
            temp = ptr;
            ptr = ptr -> next;
            free(ptr);
        }
        adj[i] = NULL;
    }
}
