#include<iostream>

using namespace std;
long arr[10000002];

int main()
{
    int n,m;
    cin >>n;
    cin >> m;
    while(m--)
    {
        int a,b,k;
        cin >> a >> b >> k;
        arr[a] = arr[a] + k;
        arr[b+1] = arr[b+1] -k;
    }
    long sum = 0 , maxi = arr[1];
    for(int i=1;i<=n;i++)
    {
        sum += arr[i];
        maxi = max(maxi ,sum);
    }
    cout << maxi;
    return 0;
}
