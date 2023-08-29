/**
->We will see some improved way to use lower and upper bound with set and map.
*/
#include<iostream>
#include<set>

using namespace std;

int main()
{
    set<int> s;
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int val;
        cin >> val;
        s.insert(val);
    }

    auto it = lower_bound(s.begin(),s.end(),5); ///this will take O(n)
    if(it ==s.end())
        cout << "not found" << endl;
    else
        cout << *it << endl;

    ///lower bound will return iterator i.e. s.iterator . lly like s.begin();
    it = s.upper_bound(5);  ///this will take O(logn) time
    if(it ==s.end())
        cout << "not found" << endl;
    else
        cout << *it << endl;

    cout << "lly with map and pairs" << endl;
    cout << "Keep learning and keep growing" << endl;
}
