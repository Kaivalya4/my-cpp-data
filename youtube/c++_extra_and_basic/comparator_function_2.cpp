#include<iostream>
#include<set>

using namespace std;

class compare{
public:
    bool operator()(const int &a , const int &b){    // we do operator overloading
        return a>b;
    }
};

int main()
{
    set<int , compare> s;   // in vector we were calling comparator function and while in container like set , map , priority queue we use class name
                            //or struct name
    s.insert(2);
    s.insert(1);
    s.insert(3);
    for(auto i:s)
        cout<< i << " ";
    return 0;
}
