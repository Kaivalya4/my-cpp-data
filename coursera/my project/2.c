#include<stdio.h>
#include<stdlib.h>
int arr[100000] ;
struct node
{
    int data ;
    struct node *left;
    struct node *right;
};
struct node *newnode(int key)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = key;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return new_node;
}
struct node *createtree(int par[] ,int n )
{
    int i;
    struct node *corres[n];
    for(i=0;i<n;i++)
        corres[i] = newnode(i);
    struct node *root = NULL;
    for(i=0;i<n;i++)
    {
        if(par[i] == -1)
            root = corres[i];
        else
        {
            struct node *ptr = corres[par[i]];
            if(ptr -> left)
                ptr -> right = corres[i];
            else
                ptr -> left = corres[i];
        }
    }
    return root;
}
void filldepth(int par[] , int i ,int depth[])
{
    if(depth[i])
        return ;
    if(par[i] == -1)
    {
        depth[i] = 1;
        return;
    }
    if(depth[par[i]] == 0)
        filldepth(par , i ,depth);
    depth[i] = depth[par[i]] + 1;
}
int height(int par[] , int n)
{
    int depth[n];
    for(int i=0;i<n;i++)
        depth[i] = 0;
    for(int i=0; i<n ;i++)
        filldepth(par  ,i ,depth);
    int ht = depth[0];
    for(int i=1; i<=n;i++)
        if(ht<depth[i])
            ht = depth[i];
    return ht;
}
int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    struct node *root = createtree(arr,n);
    int hght = height(arr , n);
    printf("%d",hght);
    return 0;
}
