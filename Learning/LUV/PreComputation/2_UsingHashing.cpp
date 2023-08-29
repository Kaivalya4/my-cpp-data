/*
Ginen array a of N integers. Given Q queries,
and in each query given a number x , print count of that number in array.

Constraints :
1<=N<=10^5
1<=a[i]<=10^7
1<=Q<=10^5

Testcase:ip 6             op : 1
            3 5 5 7 7 8        2
            5                  2
            3                  1
            7                  0
            5
            8
            9
*/
#include<iostream>

using namespace std;
const int N = 100001;
int a[N];
const int C = 10000001;
int hsh[C];

int main()
{
    int q , n , x;
    cin >> n;
    for(int i=0 ;i<n ; i++){
        cin >> a[i];
        hsh[a[i]] ++;
    }
    cin >> q;
    while(q--)
    {
        cin >> x ;
        cout << hsh[x] << endl;
    }
    return 0;
}
