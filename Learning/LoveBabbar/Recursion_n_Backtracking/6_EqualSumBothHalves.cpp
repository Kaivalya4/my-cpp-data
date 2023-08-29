/*
Given a number n, we need to print all n-digit binary numbers with equal sum in left and right halves.
 If n is odd, then mid element can be either 0 or 1

The idea is to recursively build left and right halves and keep track of difference between counts of 
1s in them. We print a string when difference becomes 0 and there are no more characters to add.
*/

#include<iostream>
#include<string>

using namespace std;

void func(int n , string left , string right , int diff)
{
    //two base condn - if even
    //even - 2 will eventually lead to 0
    if(n == 0)
    {
        //to be sure if our string is required one or not
        if(diff == 0)
        {
            cout << left + right << endl; //we concat them
        }
    }
    //odd
    //odd - 2...will eventually lead to 1
    if(n == 1)
    {
        //to be sure
        if(diff == 0)
        {
            //as middle element can be 0 or 1 in case of odd
            cout << left + "1" + right << endl;
            cout << left + "0" + right << endl;
        }
    }

    //If difference is more than what can be
    //   be covered with remaining n digits
    if((2  * abs(diff)) <= n)
    {
        //we are adding one bit at a time to each left and right . hence n-2
        
        func(n - 2 , left + "0" , right + "0" , diff ); //diff will remain same
        
        func(n - 2 , left + "1" , right + "1" , diff); //diff will remain same

        func(n - 2 , left + "0" , right + "1" , diff - 1); //left - right < 0  as right has more 1 hence diff-1

        func(n - 2 , left + "1" , right + "0" , diff + 1); //left - right >1  hence diff + 1
    }
}

void solve(int n)
{
    func(n , "" , "" , 0);  //initially both string are empty hence diff = 0
}

int main()
{
    int n;
    cin>> n;
    solve(n);
    return 0;
}