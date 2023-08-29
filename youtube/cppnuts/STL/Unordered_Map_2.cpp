#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
    unordered_map<int , int> um;
    um[3] = 3;                 // we can use [] to access and enter element
    for(int  i =0 ; i<5 ; i++)
    {
        um[i] = i*3;              // value of older 3 will be changed from 3 to 9
    }
    um.insert(make_pair(10 , 100));
    um.insert(make_pair(3 , 99)); // this will not have any effect as duplicate key value are not possible in map


    //begin() returns iterator to beginning and end() returns iterator to end
    cout<< "Elements of um are : " << endl;
    for(auto it = um.begin() ; it != um.end() ; it++)
        cout<< it-> first << " -> " << it -> second << endl;

    //we can remove using key with help of erase(key) . we can also use iterator.
    um.erase(3);
    unordered_map<int , int> ::iterator it;
    it = um.begin();
    um.erase(it);
    cout<< "Elements of um after erase() : " << endl;
    for(auto it = um.cbegin() ; it != um.cend() ; it++) //  cbegin() returns constant iterator to the beginning while cend() to end.
        cout<< it-> first << " -> " << it -> second << endl;

    //size() - size returns size of the unordered map.
    cout<< "Size of um is : " << um.size() << endl;


    //max_size() returns maximum size a map can have
    cout<< "Max size of um is : " << um.max_size() << endl;


    //empty() - returns boolean value , returns 1 or True if map is empty
    um.empty() ? cout<< "um is empty" << endl : cout << "um is not empty" << endl;


    //swap() - swap contents of two unordered map even if their size is different.
    unordered_map<int  ,int> um2;
    for(int  i =0 ; i<7 ; i++)
    {
        um2[i] = i*5;
    }
    cout<< "um before swap : " << endl;
    for(auto i: um)
        cout<< i.first << " -> " << i.second << endl;
     cout<< "um2 before swap : " << endl;
    for(auto i: um2)
        cout<< i.first << " -> " << i.second << endl;
    um.swap(um2);
    cout<< "um after swap : " << endl;
    for(auto i: um)
        cout<< i.first << " -> " << i.second << endl;
     cout<< "um2 after swap : " << endl;
    for(auto i: um2)
        cout<< i.first << " -> " << i.second << endl;

    //clear() - empty the entire unordered map
    um.clear();
    cout<< "After clear() : " << um.empty() ? cout<< "\bum is empty" << endl : cout << "\bum is not empty" << endl;
    return 0;

}
