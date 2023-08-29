/**

The number of occurance of an element can be given as
Total_i=(N-i+1)*(i)
(N-i+1) ==> Because the elements starting at that postion.
(i) ==> Because the number of times to be repeated from previos elements.
*/

#include<iostream>

using namespace std;

long arr[100001];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        long res =0;
        for(int i=1;i<=n;i++)
        {
            long sub = i *(n-i+1);
            if(sub%2 != 0)
                res = res ^ arr[i-1];

        }
        cout << res << endl;
    }
    return 0;
}
