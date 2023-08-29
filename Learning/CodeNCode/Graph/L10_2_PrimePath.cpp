///spoj
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> adjlist[10000];
int dist[10000];
int vis[10000];
vector<int> primes;

bool isPrime(int a)
{
    for(int i=2 ; i*i<a ; i++)
    {
        if(a%i == 0)
        {
            return false;
        }
    }
    return true;
}

bool isValid(int a , int b)
{
    int count = 0;
    while(a>0)
    {
        if(a%10 != b%10)
            count++;
        a = a/10;
        b = b/10;
    }
    if(count == 1)
        return true;
    return false;
}

void createGraph()
{
    for(int i=1000 ; i<=9999 ; i++)
    {
        if(isPrime(i))
            primes.push_back(i);
    }
    for(int i=0 ; i<primes.size() ; i++)
    {
        for(int j=i+1 ; j<=primes.size() ;j++)
        {
            int a = primes[i];
            int b = primes[j];
            if(isValid(a , b))
            {
                adjlist[a].push_back(b);
                adjlist[b].push_back(a);
            }
        }
    }
}

void bfs(int src)
{
    vis[src] = 1;
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int parent = q.front();
        q.pop();
        for(int i=0 ; i<adjlist[parent].size() ; i++)
        {
            int child = adjlist[parent][i];
            if(vis[child] == 0)
            {
                q.push(child);
                dist[child] = dist[parent] + 1;
                vis[child] = 1;
            }
        }
    }
}
int solve(int Num1,int Num2)
{
    createGraph();
    for(int i=1000 ; i<=9999 ; i++)
    {
        dist[i] = -1;
    }
    bfs(Num1);
    return dist[Num2] != -1 ? dist[Num2] : -1;
}

int main()
{
    int num1 , num2;
    cin >> num1 >> num2;
    cout << solve(num1 , num2);
    return 0;
}
