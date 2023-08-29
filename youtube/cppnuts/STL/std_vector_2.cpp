// linked list + array =  vector
// concept of size , capacity , and some amortized analysis come in to play

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    std::vector<int> arr;
    for(int i=0 ; i<16 ; i++)
    {
        arr.push_back(1); // adds new element at the end
        cout<< "size is : "<< arr.size() <<" capacity is : " << arr.capacity() << endl; //size gives current size of array and capacity gives max element it contains
    }
    cout<<"For arr1 : -"<<endl;
    std::vector<int> arr1;
    arr1.reserve(16);      //reserve 16 blocks  for array
    for(int i=0 ; i<16 ; i++)
    {
        arr1.push_back(1);
        cout<< "size is : "<< arr1.size() <<" capacity is : " << arr1.capacity() << endl;
    }
    return 0;
}
