#include<iostream>
#include<unordered_map>

using namespace std;

void solve(int arr[] , int n)
{
    unordered_map<int , int> umap;
    for(int i = 0 ; i<n ; i++)
    {
        umap[arr[i]] = 1;
    }
    int maxs = -99999;
    for(int i=0 ; i<n ; i++)
    {
        if(umap[arr[i]] == 2)
        {
            while(umap[maxs] != 0)
            {
                maxs++;
            }
            arr[i] = maxs;
        }
        umap[arr[i]] ++;
        maxs = max(arr[i] , maxs);
    }
}

int main()
{
    int arr[] = { 1, 2, 5, 7, 8, 8, 7 };
    solve(arr , 7);
    for(int i=0 ; i<7 ; i++)
        cout << arr[i] << " ";
    return 0;
}
