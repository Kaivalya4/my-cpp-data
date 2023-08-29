/*
-> Brute force - Check for each number wether there is a divisor . O(n^2)
-> Not for very large number - Find the maximum element in array and also map all elements of array.
    Now pick an element and check wether its multiple exsist in array . Check multiple until multiple becomes
    bigger than max element
    Suppose one element is very large and others are very small then this will be costly . hence should be used
    on smaller numbers
-> Mine - map all elements. For every element find the prime factors of that element and not including itself
    as factor . Then check wether that factor exsist in map.
*/
//2nd method -
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>

using namespace std;

void divisibilityCheck(int arr[]  , int n)
{
    int maxs = INT_MIN;
    unordered_map<int , int> umap;
    for(int i=0 ;i<n ;i++)
    {
        umap[arr[i]] ++;
        maxs = max(arr[i] , maxs);
    }

    //suppose we have 2,6,6 then 2 will divide both 6 but we will store only once.
    unordered_set<int> sets;
    for(int i=0 ; i<n ;i++)
    {
        int val = arr[i];
        if(umap[val] > 1) //if 2,2 is present then we insert one 2 here.While repetition will be handled in below for loop
            sets.insert(val);
        int j=2;
        //to store only one occurence of a number
        while(1)
        {
            val = val*j;
            if(val > maxs)
                break;
            if(umap[val]){
                sets.insert(val);
            }
            val = val/j;
            j++;
        }
    }
    vector<int> vec;
    for(auto i:sets)
        vec.push_back(i);

    //now its time to store repetitions
    //suppose two 2 are present then each 2 can divide the other 2;
    for(int i=0; i<n ;i++)
    {
        while(umap[arr[i]] >1)
        {
            vec.push_back(arr[i]);
            umap[arr[i]] --;
        }
    }
    for(auto i:vec)
        cout << i << " ";
}

int main()
{
    int arr[] = { 2, 3, 8, 6, 9, 10 };
    //int arr[] = {2,2,3,8,6,6,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);

    divisibilityCheck(arr, n);

    return 0;
}
