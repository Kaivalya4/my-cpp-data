#include<iostream>
#include<vector>

using namespace std;

void func(vector<int> v)
{
    v[0] = 10;
    cout<< "changed value of vector in function : \n";
    for(auto  i: v)
        cout<< i<< endl;
    return;
}

void func1(vector<int> &v)
{
    v[0] = 10;
    return;
}
int main()
{
    vector<int> v = {1,2,3,4};
    vector<int> v1 ;
    //below will give error - 
    //v1[0] = v[0];  //if the newly created vector has no element yet then how we can change any positions value
    //cout<< v1[0];  //lly if it has no value then it cant print . program will stop here or at upper line and will not move further
    cout<< "address of vector is not passed like array in function ." << endl;
    func(v);
    cout<<"but value will not changed in original : " << endl;
    for(auto i:v)
        cout<< i << endl;
    cout<< "when we use reference then it will change : " << endl;
    func1(v);
    for(auto i:v)
        cout<< i << endl;
    return 0;
}