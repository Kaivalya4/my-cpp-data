/*
A simple solution can be to use three nested loop . Find all possible triplet and check wether it is holding
condition of AP. O(n^3) time
We can optimise the above code a bit -
So after putting two elements(say 1st and 2nd) we can find the symmetric differnce
and we will start traversing the array in the third loop till the difference between second and
third element is smaller than the symmetric difference . Since the array is sorted we can conclude that
    if the 3rd element - 2nd element > symmetric difference then the triplet is not possible using 1st and 2nd element
    Search for different 2nd element
    if the 3rd element  - 2nd element == symmetric difference then bingo!!! we got a AP triplet. Now no more AP
        triplet can be made using 1st and 2nd element as the array is already sorted . Search for different
        2nd element
    and so on......

*/


#include<iostream>
#include<unordered_map>

using namespace std;

//method2 -  using map in O(n^2) time and O(n) space
void solve(int arr[] , int n)
{
    unordered_map<int ,int> umap;

    for(int i=0 ; i<n ; i++)
        umap[arr[i]] = 1;

    for(int i=0 ;i<n ; i++)
    {
        for(int j=i+1 ; j<n-1 ; j++)
        {
            int diff = arr[j] - arr[i];
            if(umap[diff+arr[j] ]== 1)
            {
                cout << arr[i] << " " << arr[j] << " " << arr[j]+diff << endl;
                //since the array is sorted and distinct more than one triplet for fixed first and second
                //element is not possible
            }
        }
    }
}

//method3 - using concept of arithmetic mean , O(n^2) time and O(1) space
void solve2(int arr[] , int n)
{
    //we start with second element(i.e.middle element) and search for the other two element.
    //The element we selected will act as arithmetic mean of other two element of both side
    for(int i=1 ; i<n-1 ; i++)
    {
        for(int j=i-1 , k=i+1  ; j>=0 && k<n ;)
        {
            if(arr[j] + arr[k] == arr[i]*2)
            {
                cout << arr[j] << " " << arr[i] << " " << arr[k] << endl;

                // Since elements are distinct,
                // arr[k] and arr[j] cannot form
                // any more triplets with arr[i]
                j--;
                k++;
            }

            //if sum of the two element is less than the twice the middle then we should move to heavier side i.e.
            //increment k other wise decrement j
            else if(arr[j] + arr[k] < arr[i]*2)
                k++;
            else
                j--;
        }


    }
}

int main()
{
    int arr[] = { 2, 6, 9, 12, 17, 22, 31, 32, 35, 42 };
    solve(arr ,10);
    cout << endl << "another method " << endl;
    solve2(arr , 10);
    return 0;
}
