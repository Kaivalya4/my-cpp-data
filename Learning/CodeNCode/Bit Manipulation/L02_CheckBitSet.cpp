///check wether k th bit of a number is set or not
#include<iostream>

using namespace std;

int main()
{
    int n,k;
    cin >> n;
    cin >> k;
    if(n &(1<<k))
        cout << "kth bit is set" ;
    else
        cout << "kth bit is not set";
    return 0;
}
