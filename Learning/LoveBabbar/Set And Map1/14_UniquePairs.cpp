/*
Method1 - Brute Force : Find every pair and map it to get unique pairs and count of  set will give the answer
O(n^2Logn) time

Method2 - Use map or set to find unique elements in array
Starting loop from left to right in unique vector of element with fixing first element and then asscociating
next upcoming elements to get pair . Then number of such pair will be - n(n-1)/2
Similarly from right to left association will give pairs - n(n-1)/2
ex - {1,2,3} , LtoR :(1,2),(1,3),(2,3) , RtoL : (3,2),(3,1),(2,1)
now every element can pair with itself so more n pairs
total pairs = n(n-1)/2 + n(n-1)/2 + n = n(n-1) + n = n^2 .This formula can be directly used on a set

Method3 - I thought of a recursive solution but elements of array should be unique . So it is of no use!!!!!
int counts = 0;
void solve(int arr[] , int n , vector<int> sol)
{
    if(sol.size() == 2)
    {
        counts++;
        return;
    }
    for(int i=0 ; i<n ;i++)
    {
        sol.push_back(arr[i]);
        solve(arr , n , sol);
        sol.pop_back();
    }
}
*/

#include<iostream>
#include<set>
#include<unordered_map>
#include<vector>

using namespace std;

//method1
int solvemethod1(int arr[] , int n)
{
    set<pair<int ,int>> sets;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            sets.insert(make_pair(arr[i] , arr[j]));
        }
    }
    return sets.size();
}
//method2
int solvemethod2(int arr[] , int n)
{
    unordered_map<int ,int> umap;
    for(int i=0 ;i<n ; i++)
    {
        umap[arr[i]] = 1;
    }
    int val = umap.size();
    return val*val;
}

int main()
{
    int arr[] = { 1, 2, 2, 4, 2, 5, 3, 5 };
    cout << solvemethod2(arr , 8);
    cout << endl << solvemethod1(arr ,8);
    return 0;
}









