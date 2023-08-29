#include<iostream>
#include<vector>

using namespace std;

//This is recursive insertion sort method. But recursive insertion sort has no performance advantage

//all recursion method -
void insert(vector<int> &v , int val)
{
    if(v.size() == 0 || v[v.size() - 1] < val)
    {
       v.push_back(val);
       return;
    }
    int temp = v[v.size() - 1];
    v.pop_back();
    insert(v , val);
    v.push_back(temp);
}

void allrecursion(vector<int> &v)
{
    if(v.size() == 1)
        return;
    int val = v[v.size() - 1];
    v.pop_back();
    allrecursion(v);
    insert(v , val);
}

//recursion with loop - not working properly
/*
void recursionLoop(vector<int> &v)
{
  if(v.size() == 1)
  {
      return ;
  }
  int val = v[v.size() - 1];
  v.pop_back();
  recursionLoop(v);
  int n = (int)v.size();
  for(int i=0 ; i<n ; i++)
  {
      if(val < v[i])
      {
          v.insert(v.begin() + i , val);
      }
  }
}
*/

int main()
{
    vector<int> v = {7, 1, 5, 2, 3, 6};
    allrecursion(v);
    cout << "result of allrecursion funcion : " ;
    for(auto i:v)
        cout << i << " ";
    vector<int> v1 = {4 ,  7 , 1 , 5 , 2 , 3 , 6 };
    recursionLoop(v1);
    cout << endl << "result of recursionLoop funcion : " ;
    for(auto i:v1)
        cout << i << " ";
    return 0;
}
