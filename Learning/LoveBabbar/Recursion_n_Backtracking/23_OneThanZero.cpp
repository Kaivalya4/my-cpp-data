//Given a positive integer n, print all n-bit binary numbers having more 1’s than 0’s for any prefix of the number.

#include<iostream>
#include<vector>
#include<string>

using namespace std;

void func(int zero , int one , int n , string str)
{
    if(zero + one == n)
    {
        cout << str << endl;
        return;
    }
    if(zero < one){
    string str1 = str;
    string str2 = str;
    str1.push_back('1');
    str2.push_back('0');
    func(zero + 1 , one , n , str2);
    func(zero , one + 1 , n , str1);
    }
    else if(zero == one)
    {
        string str1 = str;
        str1.push_back('1');
        func(zero , one + 1 , n , str1);
    }
}

void solve(int n)
{
    int zero =0 , one = 1;
    string str;
    str.push_back('1');
    func(zero , one , n , str);
}

int main()
{
    int n;
    cin >> n;
    solve(n);
}
