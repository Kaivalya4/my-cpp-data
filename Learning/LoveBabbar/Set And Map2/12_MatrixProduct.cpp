#include<iostream>
#include<unordered_map>

//Time Complexity: O(N*M)
//Auxiliary Space: O(N*M)
using namespace std;

#define n 4
#define m 4

bool isPairWithProductK(int mat[n][m] , int k)
{
    unordered_map<int,int> umap;
    for(int i=0 ;i<n ;i++)
    {
        for(int j=0 ;j<m ;j++)
        {
            int val = mat[i][j];
            if(umap[k/val] && k%val == 0)
                return true;
            umap[mat[i][j]] = 1;
        }
    }
    return false;
}
int main()
{
     int mat[n][m] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };

    // given product
    int k = 42;

    if (isPairWithProductK(mat, k)) {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;

    return 0;
}
