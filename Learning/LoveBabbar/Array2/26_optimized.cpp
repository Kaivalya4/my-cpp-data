//one is brute force which takes O(n*m) time - find sum of each row => max sum row will be answer
//Since the array is sorted we can optimize our code of O(n+m) time

/*
//we find the first appearance of 1 in every row - row in which 1 comes earliest will be the answer row
bool find3Numbers(int arr[], int n, int X)
{
    int indexi =-1;
    int indexj = INT_MAX ;
    int minindexj = INT_MAX;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j] == 1) //we found the 1 at jth column
            {
                indexj = j;
                break; //after jth column all will be 1 only
            }
        }
        if(minindexj > indexj) //if this j index is less than our previous j index , that means at current j one comes earliest
        {
            minindexj = indexj;
            indexi= i;
        }
    }
    return indexi;
}
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank YOU" ;
    return 0;
}
