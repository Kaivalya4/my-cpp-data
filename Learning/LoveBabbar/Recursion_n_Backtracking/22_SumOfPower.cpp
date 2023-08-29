#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

void solve(int x , int n , int &counts , int i)
{
    if(x == 0)
    {
        counts++;
        return;
    }
    if(x <0 || i > x)
        return;
    int val = pow(i,n);
    solve(x - val , n , counts , i+1);
    solve(x , n , counts , i+1);
}

int main()
{
    int x , n;
    cin >> x  >> n;
    int counts = 0;
    solve(x , n , counts , 1);
    cout << counts;
    return 0;
}
