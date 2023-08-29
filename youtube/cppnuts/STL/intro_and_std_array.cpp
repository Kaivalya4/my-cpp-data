/*
STL -  Standard Template Library => Three components -> Container  - stores more than one data . arrays , lists are container
                                                     -> Iterator  - access and traverse elements of container
                                                     -> Algorithm  - the way an operation to be performed on container . ex - search , sort etc.
*/

/* std :: array --
   -> all operations are prebuilt hence making our work easier as compared to traditional array(c-style array)
   -> pass by value is actually pass value - i.e. if you pass tradi. array(c-style array) in function then a pointer to it is passed but here it is not the case with std array
   -> Syntax - std::array<T , N> arr;  //here T is data type and N is size of array.
   -> Acess : 1. at() - arr.at(3); // best thing it gives out of bound error where needed
              2. [] - arr[3]; // does not give out of bound error
              3. front() - arr.front(); // gives first element
              4. back() - arr.back(); //gives last element
              5. data() - returns pointter for that array
*/
#include<iostream>
#include<array>
#include<algorithm>  // for sorting

using namespace std;

int main()
{
    //not providing array length or array type is illegal
    std::array<int , 5> arr;  //declare
    arr = {1,2,3,4,5} ; // list initialization . This was not possible in traditional method i.e. declaration and initialization should be in same line in case of cstyle array
    std::array<int , 5> arr1 {7,9,3,4,1}; // uniform initialization
    std::array<int , 5> arr2 ;
    arr2 = {1,2,3} ;  // element 4,5 set to zero
    // arr2 = {1,2,3,4,5,6} ; //error , too many elements in the intializer list
    arr2.fill(1); // all elements become 1.
    cout<<"after fill value at index 1 : " <<arr2[1] << endl;
    cout<< arr[2] << endl;  // value at index 3
    std::cout<< arr[5] << endl; //no bound check with []
   // cout<< arr.at(5) << endl; //at() do bound check
    cout<< "size of array is : " << arr.size() << endl ; // return length
    // to print element -
    cout<<endl;
    cout<< "first element of arr1 is : " << arr1.front();
    cout<<endl;
    cout<< "last element of arr1 is : "<< arr1.back();
    cout<< "elements in the array are : " ;
    for(int i : arr)
        cout<< i << " ";
    cout<< endl;
    //begin return iterator(like pointer ) pointing to first element and end to last element
    std::sort(arr1.begin() , arr1.end()) ; // sort in forward direction
    cout<< "elements in the array after ascending sorting are : ";
    for(int i : arr1)
        cout<< i << " " ;
    cout<< endl;
    std::sort(arr1.rbegin() , arr1.rend()) ; // descending
    cout<< "elements in the array after descending sorting are : ";
    for(int i : arr1)
        cout<< i << " " ;
    cout<< endl;
    for(int i =0; i<arr1.size() ; i++) // below one might be
        cout<< arr1[i]<<" ";    // this array's [] operator uses size_type  which is unsigned in C++ standards whereas i is signed . So to avoid any error we may use -
    cout<<endl;
    for(std::array<int,5>::size_type i{0} ; i<arr1.size() ; i++)
        cout<< arr1[i] << " ";
    // std::array::size_type is just an alias for std::size_t
    for(std::size_t i {0} ; i < arr1.size() ; i++)
        cout<<arr[i] << " ";

}
