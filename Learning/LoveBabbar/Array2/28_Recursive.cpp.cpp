/*
we simply modify iterative method to recursive method - replaced while loop with recrusion
*/

#include<iostream>
#include<vector>

using namespace std;

void solve(vector<vector<int>> vec , vector<int> &v , int top , int bottom , int left , int right)
{
    if(left> right || top > bottom)
        return ;

    for(int j=left ; j<=right ; j++)
        v.push_back( vec[top][j]);

    for(int i=top+1;i<=bottom ;i++)
        v.push_back(vec[i][right]);

    if(bottom!=top)
    for(int j=right-1 ; j>=left;j--)
        v.push_back(vec[bottom][j]);

    if(left != right)
    for(int i=bottom-1;i>top;i--)
        v.push_back(vec[i][left]);

    solve(vec , v , top+1 , bottom-1,left+1,right-1);
}

vector<int> spirallyTraverse(vector<vector<int>> vec, int N , int M)
{
    vector<int> v;
    int top =0 , bottom = N-1;
    int left = 0 , right = M-1;
    solve(vec , v ,top , bottom , left , right);
    return v;
}

int main()
{
    int N =5, M =5;
    vector<vector<int>> vec =
    {
        { 1, 2, 3, 4, 5},
        {16, 17, 18, 19, 6},
        {15, 24, 25, 20, 7},
        {14, 23, 22, 21, 8},
        {13, 12, 11, 10, 9}
    };

    vector<int> arr = spirallyTraverse(vec , N , M);
    for(auto i:arr)
        cout << i << " ";
    return 0;
}
