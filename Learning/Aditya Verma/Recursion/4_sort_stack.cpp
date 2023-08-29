#include<iostream>
#include<stack>

using namespace std;

//time - O(n^2)
//this method is similar to recursive insertion sort which we applied on array-
void insert(stack<int> &s , int val)
{
  if(s.size() == 0 || val >s.top())
  {
    s.push(val);
    return;
  }
  int temp = s.top();
  s.pop();
  insert(s , val);
  s.push(temp);
}
void solve(stack<int> &s)
{
  if(s.size() == 1)
  {
    return;
  }
  int val = s.top();
  s.pop();
  solve(s);
  insert(s , val);
}
int main() {
  stack<int> s;
  s.push(7);
  s.push(1);
  s.push(5);
  s.push(2);
  s.push(6);

  solve(s);
  std::cout << "stack after sorting  : " << '\n';
  //since stack has no iterator
  int n = (int)s.size();
  for(int  i =0 ; i<n; i++) {
    cout<< s.top();
    s.pop();
  }
  cout<<endl;
  return 0;
}
