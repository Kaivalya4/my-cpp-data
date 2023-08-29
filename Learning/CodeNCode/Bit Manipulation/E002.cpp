/**
IMPORTANT POINT -
->An even number ends with 0 in binary
->An odd number ends with 1 in binary
*/

/**
Method1 - Using Bit Manipulation(in O(nlog(n)))
    vector<int> countBits(int n) {
        vector<int> vec;
        for(int i=0;i<=n; i++)
        {
            int x = i;
            int cnt =0;
            while(x>0)
            {
                cnt++;
                x = x&(x-1);
            }
            vec.push_back(cnt);
        }
        return vec;
    }

Method2 - Using DP( in O(n) time  )
    Let's denote the number as num:
        If it is even, the ending bit is 0, then that bit can be ignored,
        countBits(num) is the same as countBits(num >> 1), so countBits(num) = countBits(num >> 1);

            For example:
            num:      101010101010
            num >> 1: 10101010101

        If it is odd, the ending bit is 1, then the number of set bits is that of num - 1 + 1,
        i.e. countBits(num) = countBits(num - 1) + 1

            For example:
            num:     101010101011
            num - 1: 101010101010


    vector<int> countBits(int n) {
        vector<int> vec;
        vec.push_back(0);
        for(int i=1;i<=n ;i++)
        {
            vec.push_back(0);
            if(i%2 == 0)
                vec[i] = vec[i>>1];
            else
                vec[i] = vec[i-1] + 1;
        }
        return vec;
    }
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thnak you";
    return 0;
}
