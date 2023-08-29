///Rest in peace - Hackerearth

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n%21 == 0){
            cout << "The streak is broken!" << endl;
            continue;
        }
        int digit =0;
        int flag =0;
        while(n>0)
        {
            if(digit == 1)
            {
                digit = n %10;
                if(digit == 2)
                 {
                     flag =1;
                     cout << "The streak is broken!" << endl;
                    break;
                 }
            }
            else
                digit = n%10;
            n /=10;
        }
        if(flag == 0)
            cout << "The streak lives still in our heart!" << endl;
    }
    return 0;
}
