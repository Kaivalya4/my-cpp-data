///Bear and Segment01

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int ctrone =0 , ctrtwo = 0;
        bool flag = false;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '1')
            {
                ctrone++;
                if(ctrtwo)
                {
                    flag = true;
                    cout << "NO" << endl;
                    break;
                }
            }
            else
            {
                if(ctrone)
                    ctrtwo++;
            }
        }
        if(flag == false)
        {
            if(ctrone == 0)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
    return 0;
}
