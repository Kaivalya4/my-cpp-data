/*
->First generate all ugly numbers and insert them in a unordered_set s1.
->Take another empty set s2.
->Run two nested loops to generate all possible pairs from the two arrays taking
    one element from first array(call it a) and one from second array(call it b).
->Check if a is present in s1. If yes then check for each element of arr2[]
    if it is also present in s1.
->If both a and b are ugly numbers, then insert pair (a, b) in s2
    if a is less than b, or (b, a) otherwise. This is done to avoid duplicacy.
->Total pairs is the size of the set s2.

*/

#include<iostream>
#include<unordered_set>
#include<set>
using namespace std;

void genUgly(int arr[] , int i , int limit , unordered_set<int>&sets)
{
    if(i>limit)
        return;
    sets.insert(i);
    for(int j=0; j<3 ;j++)
    {
        i =i*arr[j];
        genUgly(arr , i , limit , sets);
        i = i/arr[j];
    }
}

int totalPairs(int arr1[], int arr2[] , int n , int m)
{
    unordered_set<int>sets;
    set<pair<int , int>> ans;
    int arr[] = {2,3,5};
    genUgly(arr , 1 , 1000 , sets);
    for(int i=0 ;i<n ;i++)
    {
        if(sets.find(arr1[i]) != sets.end())
        {
            int val = arr1[i];
            for(int j=0;j<m;j++)
            {
                if(sets.find(arr2[j]) != sets.end())
                {
                    int val2 = arr2[j];
                    ans.insert(make_pair(val,val2));
                }
            }
        }
    }
    return ans.size();
}

int main()
{
    int arr1[] = { 3, 7, 1 };
    int arr2[] = { 5, 1, 10, 4 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    cout << totalPairs(arr1, arr2, n, m);
    return 0;
}
