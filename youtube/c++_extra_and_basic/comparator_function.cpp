#include<iostream>
#include<set>
#include<vector>
#include<algorithm>  // for sort()
#include<string>

using namespace std;

class student{
public:
    string name;
    int roll;
    int marks;
    student(string s  , int r , int m)  // this is constructor
    {
        this -> name = s;
        this -> marks = m;
        this -> roll = r;
    }
};

bool compare(int a , int b){ // a is first element and b is second
    return a>b;    //2>4 is false so it will return 0 and hence it will change order
}
bool compare1(student a , student b)
{
    if (a.marks == b.marks)
        return a.name < b.name;
    return a.marks > b.marks;
}
int main()
{
    student s1("xyz" , 1 , 95) , s2 ("abc" , 2 , 99);
    vector<int> v1;
    v1.push_back(3);
    v1.push_back(2);
    v1.push_back(4);

    for(auto i:v1)
        cout<< i << endl;
    //by default sort sorts in increasing order
    sort(v1.begin() , v1.end() , compare);  //we pass third argument as any function
    for(auto i:v1)
        cout<< i << endl;   //now it will print in descending order

    vector<student> v2;
    v2.push_back(s1);
    v2.push_back(s2);
    sort(v2.begin() , v2.end() , compare1); //we will sort decreasing on basis of marks . if marks is same then we will sort alphabetically on basis of name
    for(auto i: v2)
        cout<< i.name << " " << i.roll << " " << i.marks<< endl;
    return 0;
}
