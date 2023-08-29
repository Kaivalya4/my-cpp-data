#include<stdio.h>
#define max 5
void dfs(int adj[][max] , int visited[] ,int start )
{
    int top = -1 , stk[max],i,j;
    visited[++top] = 1;
    stk[0] = start;
    while(top != -1)
    {
        start = stk[top];
        printf("%c ",start + 65);
        top --;
        for(i=0;i<max;i++)
        {
            if(adj[start][i] == 1 && visited[i] == 0)
            {
                stk[++top] = i;
                visited[i] = 1;
            }
        }
    }
}
int main()
{
    int visited[max] = {0};
    int adj[max][max] ,i,j;
    printf("Enter the adjency matrix :----\n");
    for(i=0;i<max;i++)
        for(j=0;j<max;j++)
        {
            printf("is %c neighbour of %c ?(1 for Yes and 0 for No) : ",j+65,i+65);
            scanf("%d",&adj[i][j]);
        }
    dfs(adj , visited , 0);
    return 0;
}
