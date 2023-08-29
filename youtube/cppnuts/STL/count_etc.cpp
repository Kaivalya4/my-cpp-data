//count and count_if are inside algorithm

/*
count - 
returns number of elements in the range[first,last) with value equal to val 
time - O(n)
template<class Init , class T> //InIt - input iterator and T - type of our value
 typename iterator_traits<InIt> ::difference_type   //type name is return type of count function
    count(InIt first , InIt last , const T&val); 
*/

/*
std::count_if - returns number of elements in the range[first , last) for which pred is true
time - O(n)

template<class InIt , class Pred>
    typename iterator_traits<InIt>::difference_type
        count_if(InIt first , InIt last , Pred pred);  //unary predicate is function that takes one value and do some comparison and return bool

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> v = {1,2,3,1,2};
    cout << count(v.begin() , v.end() , 1) ; 
    return 0;
}