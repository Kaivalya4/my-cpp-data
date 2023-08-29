/* std::set<T> setname;
-> There are 4 associative containers in STL - set , multiset , map , multimap
-> set contains sorted set of unique objects of type key . similar to set of mathematics
-> usually implemented using red-black tree
-> insertion, removal , search has log time complexity
-> to store user defined data types we will have to provide compare function so that set can store them in sorted order
-> we can pass order of sorting while constructing set object . By default it is ascending order
*/

#include<iostream>
#include<set>
#include<functional> // for greater and less
#include<string>    // for string functions

using namespace std;
class Person{
    public :
        float age;
        string name;
        //by default less(ascending) one will be used
        bool operator < (const Person & p) const {return age<p.age;} // compiler will not be able to compare directly so we are telling it to compare with help of age
        bool operator > (const Person & p) const {return age>p.age;}
};
int main()
{
    set<int> s = {1,2,3,4,5,1,2,3,4,5}; // will contain first five elements as others are copy of previous
    for(int e : s)
        cout<< e <<" ";
    cout << endl;
    set<Person> per = {{22 , "Undertaker"},{34,"Batista"},{21,"cena"}};
    for(auto e : per)
        cout<< e.age << " " << e.name; // will get ascending because it is default
    cout<< endl;
    set<Person ,  std::greater<>> per1 = {{22 , "machine"},{34,"bomb"},{21,"AAA"}};  // greater is for descending i.e. start from big to less
    for(Person e : per1)
        cout<< e.age << " " << e.name;
    return 0;
}
