///By brute force - O(n^2)
///By optimized way - O(n)

///optimized
#include<iostream>

using namespace std;

int main()
{
    int n ,arr[20];
    cin >> n;
    for(int i=0;i<n; i++)
        cin >> arr[i];
    int res =0;
    for(int i=0 ;i<n ;i++)
    {
        res = res^(arr[i] + arr[i]);
    }
    cout << res << endl;
    return 0;
}
