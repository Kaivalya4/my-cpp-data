//duplicates value are grouped under same bucket .For duplicate keys a count value is maintained with each key - value pair

#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
    /* Insertion can done in various ways and in any way we represent elements in pairs like - {key , value} :
    -> direct using '=' or even after declaration
    -> using insert function
    -> using std::pair
    -> or directly move the pair inside insert()
    -> if there is another container which have key - value pair , by specifying a range we can copy those pairs into to unordered multimap
    */
    unordered_multimap <int , char> m1 = {{1 , 'a'}};
    unordered_multimap <int , char> :: iterator it;

    m1 = {{2 , 'b'} , {3 , 'c'}};  //again using  = overrite previous
    m1.insert({{4,'d'},{5,'e'}});
    pair<int , char> var(6,'f');
    m1.insert(var);
    m1.insert(pair<int , char> (7,'g'));
    m1.insert(make_pair<int , char> (8 , 'h'));


    cout<< "value of m1 is  : " << endl;
    for(auto i:m1)
        cout<< i.first << " -> " << i.second << endl;


    //erase() - deletes element
    it = m1.begin();
    cout<< "Erasing first pair: " << it -> first << " -> " << it -> second;
    m1.erase(m1.begin());   //erase  element pointed by the operator
    cout<< "\nErasing element with key 3 . ";
    m1.erase(3); //erase specified key element

    cout<< "value of m1 after erase operation is  : " << endl;
    for(auto i:m1)
        cout<< i.first << " -> " << i.second << endl;


    cout<< "size of m1 is : " << m1.size() ; //number of key value pair in m1
    cout<< "\nmax size of m1 is : " << m1.max_size() ; // max size of container
    cout<<endl;


    //find() - find a given key and return iterator to position if present otherwise return iterator to end
    it = m1.find(4);
    if(it != m1.end())
        cout<< "key value found : " << it -> first << " -> " << it -> second << endl;  // "." doesnt work with iterator pointer
    else
        cout<< "element not found" << endl;


    cout<< "number of element with key 5 is : " << m1.count(5) << endl ; // count() - how many times a pair present with given key

    //swap function swaps contents of two multimap even if their size differs
    unordered_multimap<int , char> m2;
    m2 = {{4 , 'c'} , {3 , 'd'} , {11 , 'k'} };
    cout<< "m1 before swap  : " << endl;
    for(auto i:m1)
        cout<< i.first << " -> " << i.second << endl;
    cout<< "m2 before swap  : " << endl;
    for(auto i:m2)
        cout<< i.first << " -> " << i.second << endl;
    m1.swap(m2);
    cout<< "m1 after swap  : " << endl;
    for(auto i:m1)
        cout<< i.first << " -> " << i.second << endl;
    cout<<"m2 after swap : " << endl;
    for(auto i:m2)
        cout<< i.first << " -> " << i.second << endl;

    //clear() remove all elements :
    m1.clear();

    //empty() - returns 1 when empty otherwise 0
    cout<< "m1 after clear operation is : " ;
    m1.empty() ? cout << "empty" : cout<< "not empty" ;

    /*
    ->  begin() - returns iterator to beginning
    ->  end() - returns iterator to end
    ->  cbegin() - returns constant iterator to beginning
    ->  cend() - returns constant iterator to end
    */

    return 0;
}
