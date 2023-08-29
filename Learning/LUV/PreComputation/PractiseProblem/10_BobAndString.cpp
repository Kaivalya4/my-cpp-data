#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string a , b;
        cin >> a ;
        cin >> b;
        int counts =0;
        unordered_map<char , int> umapa , umapb;
        for(int i=0 ;i<a.length() ;i++)
        {
            umapa[a[i]] ++;
        }
        for(int i=0 ;i<b.length() ;i++)
        {
            umapb[b[i]] ++;
        }
        for(int i=0 ;i<b.length() ;i++)
        {
            if(abs(umapa[b[i]] - umapb[b[i]]) > 0 )
            {
                counts += abs(umapa[b[i]] - umapb[b[i]]);
            }
            umapa[b[i]] = umapb[b[i]] = -1;
        }
        for(auto i:umapa)
        {
            if(i.second != -1)
            {
                counts += i.second;
            }
        }
        cout << counts << endl;
    }
    return 0;
}
