/*
-> we find prefix sum and store that sum into map, if any sum appears once more then there is zero sum subarray
Logic :
Suppose upto ith position we get sum x . Again after that we encounter sum x
  [.....x,.......x,...]
  That means that between these two x , something like this happened -
    x+y-y = x => some y things were added and then those y were removed from it
*/

#include<iostream>
#include<unordered_map>

using namespace std;

bool subArrayExists(int arr[] , int n)
{
    unordered_map<int ,int> umap;
    int sum =0 ;
    for(int i=0 ;i<n ;i++)
    {
        sum += arr[i];
        if(umap[sum])
            return true;
        umap[sum]=1;
    }
    return false;
}

int main()
{
    int arr[] = { -3, 2, 3, 1, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    if (subArrayExists(arr, n))
        cout << "Found a subarray with 0 sum";
    else
        cout << "No Such Sub Array Exists!";
    return 0;
}
