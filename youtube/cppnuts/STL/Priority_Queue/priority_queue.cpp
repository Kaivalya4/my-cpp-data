/* Priority Queue
-> std::priority_queue is container adapter and by default it adapts std::vector and priority_queue provides constant time access of smallest or largest element
-> We may replace pirority of queue by max heap or min heap concept
-> cost of enserion and deletion is (log)
-> it is implemented using std::make_heap , std::push_heap , std::pop_heap functions internally
*/
#include <iostream>
#include<queue>
#include<vector>
#include<functional>

using namespace std;

template<typename T> void print(T& q) ///we can provide suitable return type container if we want to return(any).
{
    while(!q.empty()){
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    {
        std::priority_queue<int> q; ///By default it is max heap
        for(int i: {1,2,3,4,5,6,7,8,9})   //traversing through an array and storing value in i variable
        {
            q.push(i);
        }
        print(q);
    }
    {
        priority_queue<int , std::vector<int> , std::greater<int>> q2; // we tell it to adapt vector container . std::greater is comparater
        for(int i: {1,8,5,6,3,4,0,9,7,2,10})
            q2.push(i);
        print(q2);
    }
}

