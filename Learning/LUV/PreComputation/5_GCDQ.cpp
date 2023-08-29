#include<iostream>
#include<algorithm>

using namespace std;
int arr[1000002];
int forwd[1000002];
int backwd[1000002];

//I wrote this function using sirs notebook
/*int gcd(int a , int b)
{
    if(b ==0)
        return a;
    if(a%b == 0)
        return b;
    else
    {
        return gcd(b , a%b);
    }
}*/

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n , q;
        cin >> n >> q;
        for(int i=1;i<=n ;i++)
            cin >> arr[i];
        forwd[0] =0;
        backwd[n+1] = 0;
        for(int i=1;i<=n;i++){
            //if(forwd[i-1] > arr[i])
              //  forwd[i] = gcd(forwd[i-1] , arr[i]);
            //else
                //forwd[i] = gcd(arr[i],forwd[i-1]);
                forwd[i] = __gcd(forwd[i-1] , arr[i]);
        }
        for(int i=n ;i>=1 ; i--)
        {
            backwd[i] = __gcd(backwd[i+1] , arr[i]);
        }
        while(q--)
        {
            int a,b;
            cin >> a >> b;
            int val =  __gcd(forwd[a-1],backwd[b+1]);
            cout << val<< endl;
        }
    }

    return 0;
}
