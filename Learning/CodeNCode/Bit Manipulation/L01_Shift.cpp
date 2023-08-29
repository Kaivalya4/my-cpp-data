/**
IMPORTANT POINT -
->The left shift and right shift operators should not be used for negative numbers.
  The result of is undefined behaviour if any of the operands is a negative number.
  For example results of both -1 << 1 and 1 << -1 is undefined.
->If the number is shifted more than the size of integer, the behaviour is undefined.
  For example, 1 << 33 is undefined if integers are stored using 32 bits.
  For bit shift of larger values 1ULL<<62  ULL is used for Unsigned Long Long which is
  defined using 64 bits which can store large values.
*/

#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << "value of n when multiplied with 8 is : " << (n<<3) << endl ;
    cout << "value of n when divided by 8 is : " << (n >>3) ;
    return 0;
}
