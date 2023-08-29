#include<iostream>

using namespace std;

void one_to_n(int n)
{
    if(n == 1)
    {
        cout<< 1 << " ";
        return;
    }
    one_to_n(n-1);
    cout<<n << " "

}

void n_to_1(int n)
{
    if(n == 1)
    {
        cout<< 1 << " ";
        return;
    }
    cout<< n << " ";
    n_to_1(n-1);

}

int main()
{
    int n;
    cin>>n;
    one_to_n(n);
    cout<<endl;
    n_to_1(n);
    return 0;
}
