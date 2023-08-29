/*
->Store elements of both array . Sort it . we get n largest unique
elements from back . Now we put n largest element from aux array in map(removing duplicate ,which is
easy with help of map). Now we store element of 2nd array which occur in map and then we remove element from
map in order to avoid duplicacy . Same with 1st array

->mine - Store unique elements of both array in aux array(2nd then 1st).
We use recursion to find the maximum subset of size n which gives max sum.
*/
//sorting one

#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

void maximizeArray(int arr1[], int arr2[] , int n)
{
    int arr[2*n];
    unordered_map<int ,int> umap;
    int k=0;
    for(int i=0; i<n ;i++)
    {
        arr[k++] = arr1[i];
    }
    for(int i=0 ;i<n ;i++)
    {
        arr[k++] = arr2[i];
    }
    sort(arr , arr+(2*n));
    int j=n+n-1 , ctr = 0;
    while(ctr != n)
    {
        if(umap[arr[j]] != 1)
        {
            umap[arr[j]] = 1;
            ctr ++;
        }
        j--;
    }
    k=0;
    for(int i=0 ;i<n; i++)
    {
        if(umap[arr2[i]] == 1){
            arr[k++] = arr2[i];
            umap[arr2[i]] = 0;  //we are unmarking the element of arr2 in umap
            //because if arr1 contain any duplicate of arr2 then it should not be copied twice .
            // Also if arr2 contain repetition of any same element then it should not be copied twice.
        }
    }
    for(int i=0 ;i<n ;i++)
    {
        if(umap[arr1[i]] == 1){
            arr[k++] = arr1[i];
            umap[arr1[i]] = 0; //so that duplicate element of arr1 not get copied twice ....
        }
    }
    for(int i=0 ;i<n ;i++)
        arr1[i] = arr[i];
}

int main()
{
    int array1[] = { 7, 4, 8, 0, 1 };
    int array2[] = { 9, 7, 2, 3, 6 };
    int sizes = sizeof(array1) / sizeof(array1[0]);
    maximizeArray(array1, array2, sizes);
    for(int i=0 ;i<sizes ; i++)
    {
        cout << array1[i] << " ";
    }
}
