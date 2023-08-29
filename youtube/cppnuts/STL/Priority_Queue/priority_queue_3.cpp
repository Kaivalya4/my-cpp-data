/**
-> we will make priority queue of pairs
-> we will make priority queue of vectors
-> we will make priority queue of structures(same logic can be applied to class)
*/
#include<iostream>
#include<queue>

using namespace std;

/**
we know heap is implemented in array . Suppose we are implementing max heap
we pushed 4 7 2 . Then 7 is at the top . Now if we insert 8
 7 < 8 =>true
 Thats why we do a<b for max heap.
*/

struct student{
    int roll;
    int marks;
};

struct comparator{
    bool operator()(pair<int,int> a, pair<int,int>b){
        // return "true" if "a" is ordered
        // before "b",
        return a.second < b.second;   ///max heap
    }
};

struct compares{
    bool operator()(student a, student b){
        return a.marks < b.marks;   ///those who have higher marks will come first - max heap of marks
    }
};

void print(priority_queue<pair<int,int >>maxq)
{
    while(!maxq.empty())
    {
        cout << maxq.top().first << " " << maxq.top().second << endl;
        maxq.pop();
    }
    cout << endl;
}

void print2(priority_queue<pair<int,int>,vector<pair<int,int>>,comparator> maxq2){
    while(!maxq2.empty()){
        cout << maxq2.top().first << " " << maxq2.top().second << endl;
        maxq2.pop();
    }
    cout << endl;
}

void print3(priority_queue<vector<int>> pq)
{
    while(!pq.empty()){
        vector<int> vec = pq.top();
        for(int i=0;i<vec.size();i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
        pq.pop();
    }
}

void print4(priority_queue<student , vector<student> , compares> pq)
{
    while(!pq.empty())
    {
        student s = pq.top();
        cout << s.roll << " -> " << s.marks << endl;
        pq.pop();
    }
}

int main()
{
    ///priority queue of pairs
    {
        ///It follow max/min property on basis of first element of pairs (by default)
        priority_queue<pair<int,int>> maxq;
        maxq.push({2,3});
        maxq.push({5,6});
        maxq.push({1,4});
        maxq.push({9,11});
        maxq.push({8,6});

        cout << "Elements are : " ;
        print(maxq);

        ///We can use comparator to use second element for our max/min property
        ///created maxq on basis of second element -
        priority_queue<pair<int,int>,vector<pair<int,int>> , comparator> maxq2;
        maxq2.push({2,3});
        maxq2.push({5,6});
        maxq2.push({1,4});
        maxq2.push({9,11});
        maxq2.push({8,6});

        cout << "Elements are : " ;
        print2(maxq2);
    }

    ///priority queue of vectors
    {
        ///priority queue by default adapts vector. So it works well for vector.
        ///compares corresponding element and place that vector in priority(by default)
        ///in which large value comes first
        vector<int> vec1 = {1,2,3,5};
        vector<int> vec2 = {2,3,4,6};
        vector<int> vec3 = {1,2,3,4};

        priority_queue<vector<int>> pq;
        pq.push(vec1);
        pq.push(vec2);
        pq.push(vec3);

        print3(pq);
        cout << endl;
    }

    ///priority queue of structures or user defined data types
    {
        priority_queue<student , vector<student> , compares> pq; ///brackets is also used to determine scope
        student a = {10,20} , b = {30,40} , c = {25,35};
        pq.push(a);
        pq.push(b);
        pq.push(c);
        print4(pq);

    }
    return 0;
}

