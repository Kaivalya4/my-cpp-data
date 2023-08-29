#include<stdio.h>
#define max 5
void bfs(int adj[][max] , int visited[] , int start )
{
    int rear = -1 , front = -1 , i ;
    int queue[max];
    visited[0] = 1;
    queue[++rear] = 0;
    while(front != rear)
    {
        start = queue[++front];
        printf("%c ",start + 65);
        for(i=0;i<max;i++)
        {
            if(adj[start][i] == 1 && visited[i] == 0)
            {
                rear++;
                queue[rear] = i;
                visited[i] = 1;
            }
        }
    }
}
int main()
{
    int adj[max][max] ;
    int visited[max] = {0} , i ,j ;
    printf("\nEnter the adjency matrix :--- \n ");
    for(i=0; i<max;i++)
    {
        for(j=0 ; j<max;j++)
        {
            printf("is %c neighbour of %c(1 for yes and 0 for no) : ",j+65,i+65);
            scanf("%d",&adj[i][j]);
        }
    }
    printf("\n");
    bfs(adj, visited ,0 );
    return 0;
}
