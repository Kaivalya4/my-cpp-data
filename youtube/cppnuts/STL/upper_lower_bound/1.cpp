/**
->For array and vector : they must be sorted for logn time complexity otherwise t.c. will be n.
-> we can use it with array , vector , pair , map , set

-> in case of array it returns pointer and incase of stl's it return iterator

lower_bound(x) : if it founds x then it returns it address otherwise it returns address of element just
    greater . If none of the above happens then it returns container.end() i.e. garbage value
upper_bound(x) : returns address of element just greater than x . If none of the above happens then
    it returns container.end() i.e. garbage value
*/
///Here we will see for array and vector
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int arr[] = {1,6,3,9,5,5,8};
    int n = 6;
    //(start element address from where we want to sort , address after last element upto we want sort)
    sort(arr , arr+n); ///we sort it for logn time

    ///(same ,same , key)
    int *ptr = lower_bound(arr , arr+n ,4);
    if(ptr == arr+n)
        cout << "not found" << endl;
    else
        cout << *ptr << endl;

    vector<int> vec = {1,6,3,9,5,5,8};
    sort(vec.begin(),vec.end());

    vector<int>::iterator it = lower_bound( vec.begin() +2 , vec.end() , 2);
    if(it == vec.end())
        cout << "not found" << endl;
    else
        cout << *it << endl;
}
