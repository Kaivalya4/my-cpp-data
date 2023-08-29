#include<iostream>

using namespace std;
int arr[100001];

int main()
{
    int n;
    cin >> n;
    for(int i=0 ;i<n ;i++)
        cin >> arr[i];
    int i=0;
    for(int j=0 ;j<n ;j++)
    {
        if((j-i+1)%2 ==0)
        {
            int index = (j-i+1)/2;
            float val = ((float)(arr[index]+arr[index-1]))/(2.0);
            cout << val << endl;
        }
        else{
            float val = ((float)(arr[(j-i)]))*(1.0);
            cout << val << endl;
        }
    }
    return 0;
}
