//We are given an array arr[] of size n. Numbers are from 1 to (n-1) in random order.
//The array has only one repetitive element.
//We need to find the repetitive element.

/*
Method1 - iterate over array , check wether the currents elements duplicate is present in the rest of array
Time Complexity : O(n*n)

Method2 - we can use natural number sum method formula to get sum of 1 to n-1 numbers , we subtract the sum
of array from this to get the answer. So updated formula n*(n-1)/2
O(n)

Method3 - Using hashing
O(n) time , Auxiliary Space : O(n)

Method 4(Use XOR): The idea is based on the fact that x ^ x = 0 and x ^ y = y ^ x.
1) Compute XOR of elements from 1 to n-1.
2) Compute XOR of array elements.
3) XOR of above two would be our result.
*/

//method4
#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
    int arr[] = { 9, 8, 2, 6, 1, 8, 5, 3, 4, 7 };
    unordered_map<int , int> umap;
    for(int i=0 ; i<10 ; i++)
    {
        umap[arr[i]]++;
    }
    for(auto i:umap)
    {
        if(i.second > 1){
            cout << i.first ;
            break;
        }
    }
    return 0;
}
