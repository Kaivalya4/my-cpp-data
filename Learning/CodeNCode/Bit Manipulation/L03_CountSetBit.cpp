///Counting set bits in an integer.

#include<iostream>

using namespace std;

//using right shift operator. O(log2(n)) time
int method1(int n)
{
    int cnt =0;
    while(n>0)
    {
        if(n&1)
        {
            cnt++;
        }
        n = n>>1;
    }
    return cnt;
}

//Brian Kernighan’s algorithm-
int method2(int n)
{
    int cnt =0;
    while(n>0)
    {
        cnt++;
        n = n&(n-1);
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    cout << "number of set bit in n : " << method1(n) << endl;
    cout << "number of set bit in n : " << method2(n) << endl;
    return 0;
}
