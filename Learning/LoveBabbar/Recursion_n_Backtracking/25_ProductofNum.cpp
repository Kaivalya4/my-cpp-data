//find product of two number using recursion

#include<iostream>

using namespace std;

//method1 -
int func(int a , int b , int d , int prod)
{
    if(a == 0)
        return prod;
    int val = (a % 10) * d * b;
    prod = prod + val;
    return func(a/10 , b , d*10 , prod);
}
void solve(int a , int b)
{
    int prod = 0;
    cout << "product is  : " << func(a , b , 1 , prod);
}

//method2 -
int product(int a, int b)
{
    if(b > a)
        return product(b , a );
    if(b != 0 )
    {
        return a + product(a , b-1);
    }
    else
        return 0;
}

int main()
{
    int a , b;
    cin >> a >> b;
    solve(a , b);
    cout <<endl<< "product is "<< product(a , b);
    return 0;
}
