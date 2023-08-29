#include<stdio.h>
#define max 10
int adj[max][max] ,max_edge ;
int queue[max] , front = -1 , rear = -1 , n;
void create();
void display();
void insq(int );
int indegree(int );
int main()
{
    int i, k=0 ,node,topsort[max] ,indeg[max];
    create();
    printf("\nCoresponding Adjency matrix is : ");
    display();
    for(i=1;i<=n;i++)
    {
        indeg[i]=indegree(i);
        printf("%d ",indeg[i]);
        if(indeg[i] == 0)
            insq(i);
    }
    while(front <= rear)
    {
        node = queue[front];
        topsort[k] = node;
        front++;
        k++;
        for(i=1;i<=n;i++)
        {
            if(adj[node][i] == 1)
            {
                adj[node][i] = 0;
                indeg[i] = indeg[i] -1;
                if(indeg[i] == 0)
                    insq(i);
            }
        }
    }
    printf("\nSo toplogical sorting is ---- ");
    for(i=0 ;i<k;i++)
    {
        printf("%d ",topsort[i]);
    }
    return 0;
}
void create()
{
    int i ,start,end;
    printf("\nEnter number of nodes : ");
    scanf("%d",&n);
    max_edge = n*(n-1);
    printf("\nEnter nodes and edges(Enter both start = 0 and end =0 to stop) ---- ");
    for(i=1;i<=max_edge;i++)
    {
        printf("\nEnter Source : ");
        scanf("%d",&start);
        printf("\nEnter Sink : ");
        scanf("%d",&end);
        if(start == 0 && end == 0)
            break;
        if(start >n || end >n || start <= 0 || end <= 0)
        {
            printf("\nInvalid Edge.");
            i--;
        }
        else
            adj[start][end] = 1;
    }
}
void display()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        printf("\n");
        for(j=1;j<=n;j++)
            printf("%d ",adj[i][j]);
    }
}
void insq(int index)
{
    if(rear == max -1)
        printf("\nOverflow");
    else
    {
        if(front == -1)
        {
            front = 0;
            rear =0;
            queue[rear] = index;
        }
        else
        {
            rear++;
            queue[rear] = index;
        }
    }
}
int indegree(int node)
{
    int i,count =0 ;
    for(i=1;i<=n;i++)
    {
        if(adj[i][node] == 1)
            count ++;
    }
    return count;
}
