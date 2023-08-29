///O(1) method
///IN similar way i can do
///  2-> RANGE MAX QUERY  3->RANGE AND QUERY 4->RANGE OR QUERY 5 -> Range GCD Query 6-> Range sum query
#include<iostream>

using namespace std;

int st[32][100001];
int logs[100001];

void LogArray(int arr[] , int n )
{
    logs[1] = 0;
    for(int i=2;i<=n;i++)    ///log[i] = largest power of 2 which is less than i.
        logs[i] = logs[i/2] +1;
}

void SparseTable(int arr[] , int n)
{
    ///first row i.e. length of pow(2,0) = 1 starting form index j.
    for(int j=0;j<n;j++)
        st[0][j] = arr[j];

    for(int i=1;i<=logs[n];i++)
    {
        for(int j=0;(j+(1<<i))<=n;j++)
        {
            st[i][j] = min(st[i-1][j] , st[i-1][j+(1<< (i -1) ) ]);
        }
    }
}

int main()
{
    int arr[100];
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int q;
    cin >> q;
    LogArray(arr , n);
    SparseTable(arr , n);
    cout << logs[n] << endl;
    for(int i =0;i<=logs[n];i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << st[i][j] <<  " ";
        }
        cout << endl;
    }
    while(q--){
        int l,r;
        cin >> l >> r;   ///0-based indexing
        int i = logs[r-l+1];
        int ans = min(st[i][l] , st[i][r - (1<<i) +1]);
        cout << ans << endl;
    }
    return 0;
}


