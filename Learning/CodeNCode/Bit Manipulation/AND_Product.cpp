#include<iostream>

using namespace std;

long a[201];
long b[201];

int main()
{
    int n;
    cin >>n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        cin >> b[i];
    }
    for(int i=0;i<n;i++)
    {
        long res =0;
        long diff = b[i] - a[i] + 1;
        long one = 1;
        if(a[i] == b[i]){
            cout << a[i] << endl;
            continue;
        }
        for(int j=0;j<32;j++)
        {
            if(diff <= (one<<j))
            {
                if((a[i] &(one<<j)) && (b[i] &(one<<j))) ///if we directly use 1 here then we might get wrong answer as 1 is int not long
                    res += (one<<j);
            }
        }
        cout << res << endl;
    }
    return 0;
}
