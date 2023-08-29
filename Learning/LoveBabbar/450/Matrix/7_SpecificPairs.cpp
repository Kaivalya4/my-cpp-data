/**
Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b)
over all choices of indexes such that both c > a and d > b. here a,b,c,d are indeces.

Brute force solution can easily find in O(n^4) time complexity . How to find solution in O(n^2) time.

                [ * * * * * - ]n     for the matrix in bracket the max element outside the bracket is y .
                [ * * * * * - ]n    we can find difference of y with every element in bracket and take the maximum
                [ * * * * * - ]n
                [ * * * * * - ]n
                [ - - - - - t ]n1
                 n  n  n  n  n2 y
  Note some patterns -
            1)  [ - - - - - ]n n        2)[ - - - - -]n n     3)    [ - - - -]n n n        4)   [ - - - - - -]n
                [ - - - - - ]n n          [ - - - - -]n n           [ - - - -]n n n             [ - - - - - -]n
                [ - - - - - ]n n          [ - - - - -]n n           [ - - - -]n n n             [ - - - - - -]n
                [ - - - - - ]n n          [ - - - - -]n n           [ - - - -]n n n             [ - - - - - -]n
                 n  n  n  n  y4 y1        [ - - - - -]n n           [ - - - -]n n n               n n n n n n y1
                 n  n  n  n  y2 y3          n n n n n y1 y2         n n n n y1 y2 y3              n n n n n n y2

    from image2 - to find maximum differnce for submatrix[] , we need to find maximum of y1 & y2 . If max(y1,y2)=res
    is larger then only differnce : res - any element of submatrix is larger. lly for image3 . lly for image 4
    -> so precompute maximum for last row and last column
        -> for row max(n-1,j) = max{ (n-1,j+1) , (n-1,j+2) , ..... (n-1,n-1) }
        -> lly for row
    From image1 y = max(y1,y2,y3 , y4) , since y4 , y1 , y2, y3 are the elements are the elements whose row-index
    i> row-index of all elements of submatrix[] . and j> row-column of all elements of submatrix[]
        so max differnce = max(y4 , y1 , y2 , y3) - all elements of submatrix[]

    -> From very first image we find what is differnce when we do for position y and t i.e. matrix(y) - matrix(t)
        Now at t we will store what is maximum of (t,n1,n2,y) . why?
        Because if we can get larger value than y then I will use that to find maximum differnce for the submatrix
        marked with *.

*/
#include<iostream>

using namespace std;

int arr[30][30];

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin >> arr[i][j];
    }
    int maxY[n+1][n+1];

    ///Pre-Compute maximum y in for last row
    for(int j=n-2;j>=0;j--)
    {
        maxY[n-1][j] = max(maxY[n-1][j+1] , arr[n-1][j]);
    }

    ///Pre-Compute maximum y for last column
    for(int i=n-2;i>=0;i--)
    {
        maxY[i][n-1] = max(maxY[i+1][n-1] , arr[i][n-1]);
    }

    ///To store our answer
    int maxDiff = INT_MIN;
    for(int i=n-2; i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            ///first find maxDiff
            maxDiff = max(maxY[i+1][j+1] - arr[i][j] , maxDiff);
                            ///t , n1 , n2 , y  --- refer very first image.
            maxY[i][j] = max(arr[i][j] , max(maxY[i][j+1] , max(maxY[i+1][j+1] , maxY[i+1][j]) ) );
        }
    }
    cout << maxDiff << endl;
    return 0 ;
}
