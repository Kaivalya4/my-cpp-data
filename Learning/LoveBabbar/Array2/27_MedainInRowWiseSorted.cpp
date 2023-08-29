/**
median in row wise sorted matrix - gfg.practice.
->If I can use extra space
    ->O(nm.log(nm) ) time and O(nm) space  --- sorting
    ->O(nm.log(nm/2) ) time and O(nm/2) space ---- heap --- mine
->Without extra space
    ->O(32*r*logc) using Binary search . Why this complexity
        -> even if we take 1e9 as maxi then it can be bring down to 1 using Binary Search(logn) in 32 steps
        -> For each 32 steps : we go to each row and run BS => r*logc

    Concept is same as minimum allocation of page - we do BS b/w 1 to maximum element of array.
    We try to find that element which has r*c/2 elements smaller than it .
    Using BS(1 - maxi) we get a mid => for this mid we find number of elements smaller than mid
    To find this count => we run BS on each row . This count should be > r*c/2

    class Solution{
public:
    int BinarySearchonEachRow(vector<int> row , int l , int r , int x)
    {
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(row[mid] <= x)
            {
                l = mid+1;
            }
            else
                r = mid-1 ;
        }
        return l;
    }
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here
        int mins= 1 , maxi = 2000;
        / *  If we consider this min and max then we get error I dont know why?
        for(int i=0;i<r;i++)
        {
            mins = min(mins , matrix[i][0]);
        }
        for(int i=0;i<c;i++)
        {
            maxi = max(maxi , matrix[i][c-1]);
        }* /
        int mediandominate = (r*c )/2 ; /// if there are 9 elements then
                ///median will be greater than 4 elements and smaller than 4 elements
        while(mins<=maxi)
        {
            int mid = (mins+maxi)/2;

            int ctr=0;
            for(int i=0;i<r;i++)
            {
                ctr += BinarySearchonEachRow(matrix[i] , 0 , c-1 , mid);
            }
            if(ctr <= mediandominate)
                mins = mid+1;
            else
                maxi = mid-1;
        }
        return mins;
    }
};
*/

#include<iostream>
#include<vector>

using namespace std;
    int BinarySearchonEachRow(vector<int> row , int l , int r , int x)
    {
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(row[mid] <= x)
            {
                l = mid+1;
            }
            else
                r = mid-1 ;
        }
        return l;
    }
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here
        int mins= 1 , maxi = 2000;
        int mediandominate = (r*c )/2 ; /// if there are 9 elements then
                ///median will be greater than 4 elements and smaller than 4 elements
        while(mins<=maxi)
        {
            int mid = (mins+maxi)/2;

            int ctr=0;
            for(int i=0;i<r;i++)
            {
                ctr += BinarySearchonEachRow(matrix[i] , 0 , c-1 , mid);
            }
            cout << mins << " " << mid << " " << maxi << " " << ctr << endl ;
            if(ctr <= mediandominate)
                mins = mid+1;
            else
                maxi = mid-1;
        }
        return mins;
    }

int main()
{
    vector<vector<int>> matrix = { {1,3,5}, {2,6,9}, {3,6,9} };
    median(matrix , 3 ,3);
}
