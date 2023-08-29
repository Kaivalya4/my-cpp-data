///we will directly write code for modular exponentiation .

/**
Modular Exponentiation for large numbers - gfg.practice
*/

#include<iostream>

using namespace std;

//O(n)
int naive(int x  , int y , int mod)
{
    int res =1;
    for(int i=1 ; i<=y ; i++)
        res = res*x;
    return res %mod;
}

//O(log n)
int expo(int x ,int y , int mod)
{
    int res = 1;
    while(y !=0)
    {
        if(y%2)
        {
            y--;
            res = (res * x) %mod;
        }
        y /= 2;
        x = (x * x) %mod;
    }
    return res;
}

int main()
{
    int x , y ,  mod;
    cin >> x ;
    cin >> y;
    cin >> mod;
    cout << naive(x,y,mod) << endl;
    cout << expo(x,y,mod) << endl; //x^y %mod;
    return 0;
}

