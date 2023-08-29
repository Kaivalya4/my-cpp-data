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

int main()
{
    int q , n , x;
    cin >> n;
    for(int i=0 ; i<n ; i++)
        cin >> a[i];
    cin >> q;
    while(q--)
    {
        cin >> x;
        int ctr = 0;
        for(int i=0 ; i<n ; i++)
            if(a[i] == x)
                ctr++;
        cout << ctr << endl;
    }
    return 0;
}
