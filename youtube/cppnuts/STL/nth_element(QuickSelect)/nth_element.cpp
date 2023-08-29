/**
We can implement QuickSelect directly in c++ using std::nth_element(first,nth,last) which rearranges the
elements in range [first,last) so that after rearranging element of nth index will
be correct index of that element (just like QuickSelect) i.e. all elements preciding nth position
are smaller and all elements following nth position are greater than nth element.

It is typically implemented using a version of quickSelect called IntroSelect.
Introselect is a hybrid of quickselect and median of medians.

header file - algorithm
Time Complexity : O(n) , with n being the distance between first and the last.

template
void nth_element (RandomAccessIterator first, RandomAccessIterator nth,
                  RandomAccessIterator last);

first: Random-access iterator to the first element in the list.
last: Random-access iterator to the last element in the list.
nth: Random-access iterator pointing to the position in the list.
If it points to end, then this function will do nothing.

Return Value: Since, return type is void, so it doesnot return any value.
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int arr[] = { 3, 2, 10, 45, 33, 56, 23, 47 };
    ///let n be 5 i.e. 0,1,2,3,4
    nth_element(arr , arr + 4 , arr + 8);

    ///5th element will be at its sorted position
    for(int i=0;i<8;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<int> a = { 7, 4, 6, 3, 9, 1 };
    int k = 2; ///i.e 0,1,2 => 3rd element at its sorted position
    nth_element(a.begin() , a.begin()+k , a.end());
    for(auto i:a)
        cout << i << " ";

    return 0;
}
