///Binary Search - Iterative and Recursive . Enter array then enter element whose index to be found

#include<bits/stdc++.h>

using namespace std;

///Iterative
int BS1(vector<int> vec , int elem)
{
    int start =0;
    int ends = vec.size() -1;
    while(start<=ends)
    {
        int mid = start + (ends-start)/2;
        if(vec[mid] == elem)
            return mid;
        if(elem < vec[mid])
            ends = mid-1;
        else
            start = mid+1;
    }
    return -1;
}

///REcursive
int BS(vector<int> arr , int elem , int start , int ends)
{
    if(start>ends)
        return -1;
    int mid = start + (ends - start)/2;
    if(elem == arr[mid])
        return mid;
    if(elem <arr[mid])
        return BS(arr , elem , start , mid-1);
    else
        return BS(arr , elem , mid+1 , ends);
}

int BS2(vector<int> arr , int elem )
{
    return BS(arr , elem , 0 ,arr.size()-1);
}

int main()
{
    vector<int> vec;
    int n , elem ,val;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> val;
        vec.push_back(val);
    }
    cin >> elem;
    cout << BS1(vec , elem) << endl;
    cout << BS2(vec , elem ) << endl;
    return 0;
}
