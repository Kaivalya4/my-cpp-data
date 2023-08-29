#include<stdio.h>
#include<stdlib.h>
struct player
{
    int plyrid;
    struct player *next;
};
struct player *ptr , *start , *new_node;
int main()
{
    int n , k , i , j;
    printf("enter number of players : ");
    scanf("%d",&n);
    printf("\nenter value of k : ");
    scanf("%d",&k);
    start = (struct player *)malloc(sizeof(struct player));
    start -> plyrid = 1;
    ptr = start;
    for(i =2;i<=n;i++)
    {
        new_node = (struct player *)malloc(sizeof(struct player));
        new_node -> plyrid = i;
        ptr -> next = new_node;
        new_node -> next = start;
        ptr = new_node;
    }
    for(i = n ; i>1 ; i--)
    {
        for(j= 1 ;j <k ; j++)
            ptr = ptr -> next;
        ptr -> next = ptr -> next -> next;
    }
    printf("\nwinner is : %d",ptr -> plyrid);
    return 0;
}
