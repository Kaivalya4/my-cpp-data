#include<iostream>
#include<vector>

using namespace std;


vector<int> spirallyTraverse(vector<vector<int>> arr , int N , int M)
{
    vector<int> a;
    int top = 0 , bottom = N-1; //first row ,last row
    int left = 0 , right = M-1; //first column  , last column
    while(1)
    {
        if(left > right)
            break;
        // print top row
        for(int i=left ;i<=right ;i++)
        {
            a.push_back(arr[top][i]);
        }
        top++; //one row from top completed , now we move down by one
        if(top > bottom)
            break;
        // print right column
        for(int i=top;i<=bottom ;i++)
        {
            a.push_back(arr[i][right]);
        }
        right--; //one column form last completed , move to left by one
        if(left > right)
            break;
        // print bottom row
        for(int i=right ;i>=left ; i--)
        {
            a.push_back(arr[bottom][i]);
        }
        bottom-- ; //one row from bottom compledted , move to up by one

        if(top > bottom)
            break;

        // print left column
        for(int i=bottom ; i>=top;i--)
        {
            a.push_back(arr[i][left]);
        }
        left++;
    }
    return a;
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
