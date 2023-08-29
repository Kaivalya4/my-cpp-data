///Maximum Sum - Hackerearth

#include<bits/stdc++.h>

using namespace std;

long long arr[100001];

int main()
{
    int n;
    cin >>n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    long long sum =0;
    int ctr =0;
    int flag =0;
    long long small = LONG_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i] >= 0)
            flag = 1 , ctr++ , sum += arr[i];
        else
            small = max(small,arr[i]);
    }
    if(flag == 1)
        cout << sum  << " " << ctr << endl;
    else
        cout << small << " " << 1 << endl;
    return 0;
}
