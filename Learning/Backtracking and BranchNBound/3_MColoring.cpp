/**
gfg.practice -
bool solve(bool graph[101][101] , int m , int v , int n, int color[] )
{
    if(v<0)
    {
        return true;
    }
    bool ans = false;
    for(int c = 1; c<=m;c++){
        bool flag = false;
        for(int i=0;i<=n;i++)
        {
            if(graph[v][i] && color[i] == c)
            {
                flag = true;
                break;
            }
        }
        if(!flag)
        {
           color[v] = c;
           ans = ans ||  solve(graph , m , v-1 ,n, color);
           color[v] = 0;
        }
    }
    return ans;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    int color[V] = {0};
    return  solve(graph , m , V-1 , V-1, color );
}
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You" ;
    return 0;
}
