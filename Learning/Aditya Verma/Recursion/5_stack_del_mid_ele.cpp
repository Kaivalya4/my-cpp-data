#include<iostream>
#include<stack>

using namespace std;

void del(stack<int> &s , int k)
{
  if(k == 1)
  {
    s.pop();
    return;
  }
  int val = s.top();
  s.pop();
  del(s , k-1);
  s.push(val);
  return;
}

int main()
{
  stack<int> s;
  s.push(7);
  s.push(1);
  s.push(5);
  s.push(2);
  s.push(6);
  //we have middle position(not index ) from formula : k= size/2 +1 i.e. kth element from the top
  int k = (int)((s.size())/2) +1;
  del(s,k);
  int n = (int)s.size();
  for(int i=0 ; i<n; i++)
  {
    cout<< s.top() << " ";
    s.pop();
  }
  return 0;
}
