#include<iostream>
using namespace std;
class human{
public :
    void func()
    {
        cout << " hello I am human !" ;
    }
};

int main()
{
    //  a class can be declared inside main or any other function and it will be available inside that only
    human info;
    info.func();
    return 0;
}

