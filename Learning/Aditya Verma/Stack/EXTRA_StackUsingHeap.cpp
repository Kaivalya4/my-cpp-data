///Stack using heap
#include<iostream>
#include<queue>

///T.C. O(logn) as both push and pop takes O(logn) time
using namespace std;

///Query - 1=> push x | 2=> pop
int main()
{
    ///number of query
    int t;
    cin >> t;
    priority_queue<pair<int , int>> stk;
    int ctr = 0;
    while(t--)
    {
        int a;
        cin >> a;
        if(a == 1)
        {
            int b;
            cin >> b;
            stk.push({++ctr , b});
        }
        else{
            pair<int,int> p = stk.top();
            cout << p.second << endl ;
            stk.pop();
        }
    }
}
