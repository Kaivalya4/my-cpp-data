#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

///Some uses -
/**
->find kth smallest
->find kth largest
->find median
*/

bool comp(int a , int b)
{
    return a> b;
}
int main()
{
    ///finding kth smallest -
    int arr[] = { 3, 2, 10, 45, 33, 56, 23, 47 };
    int k = 5; //i.e. 6th smallest
    nth_element(arr , arr+k , arr+8); ///by default comparator is '<' i.e. elements are placed in ascending order
    ///i.e. elements before k is smaller or equal to kth element and elements right to kth element is greater
    cout << "The kth smallest element in the arr is : " << arr[5] << endl;

    ///finding the kth largest -
    int arr2[] = { 30, 20, 50, 60, 70, 10, 80, 40 };
    k = 1; //i.e. largest
    nth_element(arr2 , arr2 + k , arr2+8 , greater<int>());
    cout << "The kth largest element in the arr2 is : " << arr2[1] << endl;

    vector<int> vec =  { 30, 20, 50, 60, 70, 10, 80, 40} ;
    k = 1;
    nth_element(vec.begin() , vec.begin()+ k ,vec.end() , comp);  ///using custom comparator
    cout << "The kth largest element in the vec is : " << vec[1] << endl;

    ///finding the median-
    vector<int> vec2 = { 3, 2, 10, 45, 33, 56, 23, 47, 60 };
    nth_element(vec2.begin() , vec2.begin() + (vec2.size()/2) , vec2.end());
    cout << "The median of the vec2 is : " << vec2[vec2.size()/2];

    return 0;
}
