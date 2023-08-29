/*set<T>
 -> it is an associative container that contains a sorted set of unique elements
 -> we can provide order of sorting but by default it is ascending
 -> it is usually implemented using red black tree
 -> insertion , removal , search have logarithmic complexity (as it is tree)
 -> if we want to store user defined data type in set then we will have to provide compare function so that set can store them in sorted order.
*/

#include<iostream>
#include<set>
#include<string>
#include<functional>  //for std::greater

using namespace std;

class person
{
public:
    int age;
    string name;
    bool operator < (const person & rt) const {return age < rt.age;} // this comparater will help compiler to sort element of class person on basis of age
                    //if comparater is not provided then we ger error
    bool operator > (const person & rt) const {return age > rt.age;} // by default above function will be called
};
int main()
{
    set<int> s1 ={1,2,4,3,5,5,4,3,2,1}; //duplicate elements will be removed and elements will be stored in sorted order
    for(auto i:s1)
        cout<< i << endl;
    set<person> s2 = {{30 , "mahesh"},{ 25 , "nitesh"},{22 , "prateek"}};
    for(auto i:s2)
        cout << i.age << " -> " << i.name << endl;
    set<person , greater<>> s3 = {{30 , "rahesh"},{ 25 , "kitesh"},{22 , "drateek"}}; // this will use second comparater
    for(auto i:s3)
        cout << i.age << " -> " << i.name << endl;
    return 0;
}
