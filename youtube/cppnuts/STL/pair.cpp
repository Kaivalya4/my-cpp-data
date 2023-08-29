/*std;;pair<T1 , T2> obj;
-> pair is a struct template that provides a way to store two heterogeneous objects as a single unit (any combination of data structure or type can be paired)
-> map , multimap , unoreder_map , unorder_multimap can use pair to insert data into their structure.
*/

#include<iostream>
#include<vector>

using namespace std;

void print(pair<int , int> p)
{
    cout<<p.first << " -> " << p.second << endl;
}
template<typename T>
void prints(T a)
{
    for(auto i:a) // since pairs is structure based data structure we used dot to access its element
        cout<< i.first << " -> " << i.second << endl;
}
int main()
{
    {
        std::pair<int , int> p1(10 , 10); //one way
        print(p1);
    }
    {
        pair<int , int> p2 = make_pair(10 , 20);
        print(p2);
    }
    /*{
        pair(1 , 2);
    }*/
    {
        vector<pair<string , uint16_t>> vec; // vector of pair . here unit means unsigned int
        vec.push_back(make_pair("Rupesh" , 30));
        vec.push_back(make_pair("Ritesh" , 20));
        vec.push_back(pair<string , uint16_t>("Binod" , 22));
        vec.push_back(pair<string , uint16_t>("Sugar" , 18));
        vec.push_back(pair<string , uint16_t>("tata" , 20));  //templates argument is not needed in c++17 , auto type deduction work there with pair
        prints(vec);
    }
    return 0;
}
