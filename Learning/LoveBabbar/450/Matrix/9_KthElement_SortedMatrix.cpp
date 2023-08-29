///-> Copy all elements in an array and sort it : O(n^2 * log(n^2) ) time and O(n^2) space
///-> Pick two rows and apply merge routine : O(n^2) time and O(k) space (worst : O(n^2))
///->traverse entire matrix and use heap : O(n^2) time and O(k) space (worst : O(n^2))
///->optimized version of heap solution using symmetric operation method : O(n(n-1)/2) time and O(k) space(worst : O(n^2) )
///->More optimized version of heap solution : assymtotically same complexity
///->Binary Search : O(32*N*LogN) time and O(1) space : Try it -> logic is simple : just like median in row wise
    ///sorted matrix : Find a number in range 1-1e9 and find all elements in each row which is less than equal
    ///to that number . If count == k => we have our answer . If count <k => we increase our low otherwise we decrease our high
    ///not coding it because I know BS solution are very error prone and I dont want to waste my mind

///More optimized version of maxheap
/**
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
    priority_queue<int> maxheap;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if((j+1)*(i+1) > k)
                break;
            maxheap.push(mat[i][j]);
            if(maxheap.size() >k)
                maxheap.pop();
            if(i == j)
                continue;
            maxheap.push(mat[j][i]);
            if(maxheap.size()>k)
                maxheap.pop();
        }
    }
    return maxheap.top();
}
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank you" << endl;
    return 0;
}
