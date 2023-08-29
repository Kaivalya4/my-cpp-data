/* Emplace in STL
-> Every container in stl has a insert and emplace function
-> Emplace is used to construct object in - place and avoids unnecessary copy at objects;
-> Insert and Emplace works equal for primitive data types(int , float etc.) but when we deal heavy objects we should use emplace if we can for more efficiency
*/

#include<iostream>
#include<set>

using namespace std;

class A{
    public :
        int x;
        A(int x=0) : x{x} {cout << "Construct" << endl;};
        A(const A& rhs) {x = rhs.x; cout<< "Copy" << endl;}
};
int main()
{
    set<A> set1;
    /* A a(10);
       set1.insert(a);
    */
    // Above one can be shortly written as -
    set1.insert(A(10)); // first we are constructing an object of Type A with value 10 then copying it to set
    set1.emplace(10); // emplace says I am constructing object you just pass me value
    return 0;
}
