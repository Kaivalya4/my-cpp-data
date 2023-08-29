#include<iostream>
#include<vector>
#include<unordered_map>

/**
0 3
1 2
1 3
1 4
2 4
3 4
*/
using namespace std;

//int arr[100][100] ;


bool solve(int arr[][5] , int n , vector<int>&path , unordered_map<int,bool> umap)
{
    if(path.size() == n)
    {
        if(arr[path[n-1]][0] == 1)
            return true;
        return false;
    }
    int src = path.back();
    for(int i=1;i<n;i++)
    {
        if(umap[i] == false && arr[src][i] == 1){
            path.push_back(i);
            umap[i] = true;
            if(solve(arr , n ,path,umap ))
                return true;
            path.pop_back();
            umap[i] = false;
        }
    }
    return false;
}

///here assuming graph to be undirected
int main()
{
    /**
    int n;
    cout << "Enter number of nodes : " ;
    cin >> n;
    cout << "Enter number of edges : ";
    int m;
    cin >> m;
    cout << "Enter the edges : " ;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    **/
    int n =5;
    int arr[5][5] = {{0, 1, 0, 1, 0},
                         {1, 0, 1, 1, 1},
                         {0, 1, 0, 0, 1},
                         {1, 1, 0, 0, 0},
                         {0, 1, 1, 0, 0}};
    vector<int> path;
    path.push_back(0);
    unordered_map<int,bool> umap;
    umap[0] = true;
    if(solve(arr , n , path , umap))
    {
        for(int i=0;i<n;i++)
            cout << path[i] << " -> " ;
        cout << "\b\b\b" ;
    }
    else{
        cout << -1 << endl;
    }
    return 0;
}

