///priority queue is container adapter .
///to use priority queue we simply include queue header file. There is no special priority queue header file.We
///include queue header file but to gain property of priority to the elements we declare as priority_queue .

#include<iostream>
#include<queue>

using namespace std;

void print1(priority_queue<int> &maxq)  ///here we have called using reference.
{
    while(!maxq.empty())
    {
        cout << maxq.top() << " ";
        maxq.pop();
    }
}

void print2(priority_queue<int , vector<int> , greater<int>> &minq)
{
    while(!minq.empty())
    {
        cout << minq.top() << " ";
        minq.pop();
    }
}

int main()
{
    ///push(element) - inserts the element in priority queue
    ///pop() - to remove element from priority queue
    ///top() - extract top element(max in case of max heap and min in case of min heap
    ///size() - returns number of elements in priority queue
    ///empty() - returns true is pq is empty otherwise false
    ///swap() - If there are tow priority queues with swap operation; we can exchange all elements from
            /// proiority queue1 to priority queue2 and vice versa. Here constraints are both must contain same data
            ///type elements and nature of priority queue should also be same. Size may differ.
   ///value_type() - represents the type of object stored as an element in a pirority queue.

    ///another way of min heap (popular in CP) - multiply all elements with -1. create a max heap from it.
    ///when we access the data and want to print it we simply multiply those elements with -1 again.

    priority_queue<int> maxq;  /// max heap by default
    priority_queue<int  , vector<int> , greater<int>> minq;  ///type , adapter , greater for min

    maxq.push(5);
    maxq.push(1);
    maxq.push(10);
    maxq.push(20);
    maxq.push(30);

    minq.push(5);
    minq.push(1);
    minq.push(10);
    minq.push(20);
    minq.push(30);

    cout << "size of maxq before print : " << maxq.size() << endl;
    cout << "size of minq before print : " << minq.size() << endl;

    maxq.empty() ? cout << "So maxq is empty." << endl:  cout<< "So maxq is empty" << endl;
    minq.empty() ? cout << "So minq is empty." << endl:  cout<< "So maxq is empty" << endl;

    cout << "elements of maxq is : " ;
    print1(maxq);
    cout << endl << "size of maxq after print : " << maxq.size() << endl;
    maxq.empty() ? cout << "So maxq is empty." << endl:  cout<< "So maxq is empty" << endl;

    cout << "elements of minq is : ";
    print2(minq);
    cout << endl << "size of minq after print : " << minq.size() << endl;
    minq.empty() ? cout << "So minq is empty." << endl:  cout<< "So minq is empty" << endl;

    cout << "We push following elements in maxq before swap : 5 1 10 20 30" << endl;
    maxq.push(5);
    maxq.push(1);
    maxq.push(10);
    maxq.push(20);
    maxq.push(30);

    priority_queue<int> maxq2;
    cout << "We push following elements in maxq2 before swap : 5 1 20 30 40 60" << endl;
    maxq2.push(5);
    maxq2.push(1);
    maxq2.push(20);
    maxq2.push(30);
    maxq2.push(40);
    maxq2.push(60);


    maxq.swap(maxq2);

    cout << endl << "Elements of maxq after swap : " << endl;
    print1(maxq);

    cout << endl << "Elements of maxq2 after swap : " << endl;
    print1(maxq2);

    return 0;
}
