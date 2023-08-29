//print how we are progressing at each step
//time - O(2 pow n) - write equations
#include<iostream>

/**
->Move n-1 discs from 1 to 2. This leaves disc n alone o pole 1.
->Move disc n from 1 to 3.
-> Move n-1 discs form 2 to 3, so they sit on disc n.
*/
using namespace std;

int count = 0;

void solve(int s , int d , int h , int n)
{
    count++;
    if(n == 1)
    {
        //so largest tile is at destination
        cout << "moving plate " << n << " from " << s << " to " << d;
        cout << endl;
        return ;
    }
    //first from source to helper with help of destination leaving largest tile(making solution small)
    solve(s , h , d , n-1);
    cout << "moving plate " << n << " from " << s << " to " << d;
    cout << endl;
    //once largest tile is at its destination , we will move all tile from helper to destination with help
    // of source
    solve(h , d , s , n-1);
}
int main()
{
    //n = number of plates
    int n;
    cin>>n;
    //s - starting pole , d = destination pole , h = helping pole
    int s = 1 , d = 3 , h = 2;
    solve(s , d , h , n);
    cout << count;
    return 0;
}
