#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n , m;
    cout << "Enter number of nodes : " ;
    cin >> n;
    cout << "Enter number of edges : ";
    cin >> m;
    vector<int> adj[n+1] ;
    cout << "Enter one connection in pairs at a time : ";
    int a , b;
    while(m--)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << "So the adjecency list is : " << endl;
    for(int i=0 ; i < n ; i++)
    {
        
        cout << i+1 << " : " ;
        int k = adj[i+1].size(); 
        for(auto j: adj[i+1])  //as node is started from 1 not zero
        {
            k--;
            if( k!= 0)
            cout << j << " -> ";
            else
            cout << j ;
        }
        cout << endl;
    }
}