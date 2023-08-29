/*
Traditional iterative and recursive method cant be used for large numbers . So we use array, vectors, strings,LL
for this -
multiply(res[], x)
1) Initialize carry as 0.
2) Do following for i = 0 to res_size – 1
….a) Find value of res[i] * x + carry. Let this value be prod.
….b) Update res[i] by storing last digit of prod in it.
….c) Update carry by storing remaining digits in carry.
3) Put all digits of carry in res[] and increase res_size by number of digits in carry.

if 5! = 120 then vector contains 0,1,2 we reverse it and bingo we have the answer
199*9  => 9*9 = 81 we push 1 and carry 8
          9*9 = 81+8 = 89 . we push 9 and carry 8
          9*1 = 9+8 = 17 . we push 7 and carry 1
          since carry !=0 so we need to create extra space for remaining digits that carry is holding(carry
           might also contain more than 3 digit number ) . so we push a digit of carry one by one until carry
           not equal to zero
*/

#include<iostream>
#include<vector>

using namespace std;


int multiply(vector<int>&vec , int nextnum , int sizes)
{
    int carry =0;
    for(int i=0 ; i<sizes ; i++)  //we multiply nextnumber to every digit of number which was previously calculated
    { //and store carry in the process . Suppose we need to find 6! , suppose we have already calculated 5!
        //so vec contains 0,2,1. hence we need to multiply 6 with 0 = 0 , 6 with 2 = 12 so 2 and carry 1
        // 6 with 1 = 6 + 1(carry) = 7 => 0,2,7
        int prod = vec[i]*nextnum + carry;
        vec[i] = prod %10;
        carry = prod /10;
    }
    while(carry)
    {
        vec.push_back(carry%10);
        carry = carry /10;
        sizes++;
    }
    return sizes;
}
vector<int> factorial(int n)
{
    vector<int> vec;
    vec.push_back(1); //intially 1 will be there
    int sizes= 1; //number of digits i.e. size of vec
    for(int i=2; i<=n ;i++)
        sizes = multiply(vec, i , sizes);
    return vec;
}

int main()
{
    int n;
    cin >>n;
    vector<int> vec;
    vec = factorial(n);
    for(auto i:vec)
        cout << i ;
    return 0;
}
