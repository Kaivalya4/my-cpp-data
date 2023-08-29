/*unordered multimap -
-> it is an unordered associative container in which we may have multiple copies of each key value . We can visualize it as multimap without any
   sorted order.
-> Search , insertion , and removal have average constant time complexity because internally it uses hashing to insert and organize element into buckets.
-> it allows fast access because once hash function is computed it gives exact bucket where element is placed into.
*/

#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
    unordered_multimap<int , char> umm = {{4 , 'd'} , {3 , 'c'}};  //different method to insert element
    umm.insert({1, 'a'});
    umm.insert(pair<int , char>(2, 'b'));
    umm.insert(make_pair(1,'e'));

    for(pair<int , char> i : umm)
        cout<< i.first << " -> " << i.second << endl;
    return 0;
}
