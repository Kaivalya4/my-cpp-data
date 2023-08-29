#include<iostream>
#include<unordered_map>

using namespace std;

int solve(int a[] , int b[], int n , int m)
{
    unordered_map<int , int> umap;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            int sum = a[i] + b[j];
            umap[sum] = 1;
        }
    }
    int ctr = 0;
    for(auto i:umap)
    {
        ctr += i.second;
    }
    return ctr;
}
int main()
{
    int a[] = { 12, 2, 7 };
    int n = sizeof(a) / sizeof(a[0]);
    int b[] = { 4, 3, 8 };
    int m = sizeof(b) / sizeof(b[0]);

    cout << solve(a, b , n , m);
    return 0;
}
