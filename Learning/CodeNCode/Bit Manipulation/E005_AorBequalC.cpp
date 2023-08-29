///Minimum flips to make a or b equal c - Leetcode

/**
    int minFlips(int a, int b, int c) {
        int ctr =0;
        for(int i=0 ;i<32; i++)
        {
            bool x = false , y = false , z = false;
            if(a &(1<<i))
                x = true;
            if(b &(1<<i))
                y = true;
            if(c &(1<< i))
                z = true;
            if(z == true)
            {
                if(x == false && y == false)
                    ctr++;
            }
            else
            {
                if(x == true )
                    ctr++;
                if(y == true)
                    ctr++;
            }
        }
        return ctr;
    }
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You" ;
    return 0;
}
