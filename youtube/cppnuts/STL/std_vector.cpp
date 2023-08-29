/*
Syntax std::vector<T> vec;
1. std::vector is  a sequence container and also known as Dynamic Array or Array list => sequence means in sequence .
  => best part of array is its constant time access
  => best part of list is its dynamic implementation
  => vector provides best part of both list and vector
2. its size can grow or shrink dynamically , and no need to provide size at compile time.

#access element -
at() , [] , front() , back() , data()
*/

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    std::vector<int> vec;
    std::vector<int> vec1 (5 ,20); // make vector of 5 elements with each element = 20
    std::vector<int> vec2 = {1,2,3,4,5}; //initializer list
    std::vector<int> vec3 {1,2,3,4,5}; // uniform intialization
    //access -
    cout<< vec1[0];
    cout<< vec1.at(1);
}
