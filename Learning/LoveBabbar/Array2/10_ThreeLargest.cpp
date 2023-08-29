/*
Given	an	array	with	all	distinct	elements,	find	the	largest	three	elements.
Expected	time	complexity	is	O(n)	and	extra	space	is	O(1).

->1 If it is not O(n) then we can have used sort(O(nlogn)) and found out last three elements
->2 Find first Largest , second largest , third largest element one by one.
->3 Algorithm - Suppose we find another second largest then previous 2nd largest will become third largest. This algo works that way-
1) Initialize the largest three elements as minus infinite.
    first = second = third = -∞

2) Iterate through all elements of array.
   a) Let current array element be x.
   b) If (x > first)
      {
          // This order of assignment is important
          third = second
          second = first
          first = x
       }
   c)  Else if (x > second)
      {
          third = second
          second = x
      }
   d)  Else if (x > third)
      {
          third = x
      }

3) Print first, second and third.
*/
#include<iostream>

using namespace std;

int main()
{
    int arr[] = {10, 4, 3, 50, 23, 90};
    int n = 6;
    int first , second , third;
    first = second = third = INT_MIN;

    for(int i=0 ; i<n ; i++)
    {
        //i.e. arr[i] is greater than all three , So first becomes arr[i] , second becomes first , third becomes second
        if(arr[i] > first)
        {
            third = second;
            second = first;
            first = arr[i];
        }
        //i.e. greater than second but less than first
        else if(arr[i] > second)
        {
            third = second;
            second = arr[i];
        }
        else if(arr[i] > third)
        {
            third = arr[i];
        }
    }
    cout << first << " " << second << " " << third;
    return 0;
}
