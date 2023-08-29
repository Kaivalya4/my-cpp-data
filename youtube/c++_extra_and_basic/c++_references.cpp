//references is just an alias(alternative name ) for existing variable . Any change in alias produce change in original variable and vice versa

#include<iostream>

using namespace std;

void increase(int &inc)
{
    cout << "increamented inc = " << ++inc << endl;
}

int main()
{
    int a=5 , b =20;
    /* int &ref;   // this is wrong
        ref = a    //....         */

    int &ref = a; // we have to intialize referece variable as soon we declare it.
    cout << "a = " << a << endl;
    cout << "ref = " << ref << endl;

    a=10;
    cout << "a = " << a << endl;
    cout << "ref = " << ref << endl;

    ref = 11;
    cout << "a = " << a << endl;
    cout << "ref = " << ref << endl;

    //ref can not reference to another variable once it is referenced to other.
    ref = b;   // ref will not become reference of b it will just copy value of b
    cout << "a = " << a << endl;
    cout << "ref = " << ref << endl;

    increase(b);
    cout<< "b = " << b;
    return 0;
}
