#include<iostream>
#include<unordered_map>

using namespace std;

void solve(int arr[] , int n)
{
    unordered_map<int , int> umap;
    int maxs = -99999;
    for(int i=0 ; i<n ; i++)
    {
        if(maxs < arr[i])
            maxs = arr[i];
    }
    for(int i=0 ; i<n ; i++)
    {
        if(umap[arr[i]] == 1)
        {
            arr[i] = ++maxs;
        }
        umap[arr[i]] = 1;
    }
}
int main()
{
    int arr[] = { 1, 3, 4, 5, 3 };
    solve(arr , 5);
    for(int i=0 ; i<5 ; i++)
        cout << arr[i] << " ";
    return 0;
}
