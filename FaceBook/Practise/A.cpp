#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("travel_restrictions_input.txt","r",stdin);
    freopen("final.txt","w",stdout);
    int t;
    cin >> t;
    int ctr = 0;
    while(t--)
    {
        ctr++;
        int n;
        cin >> n;
        string a;
        string b;
        cin >> a;
        cin >> b;
        string op;
        cout << "Case #" << ctr << ":\n";
        for(int i=0;i<n;i++)
        {
            for(int k=0;k<n;k++)
                op.push_back('N');
            for(int j=i;j<n;j++)
            {
                if(a[j] == 'N' && j!=i)
                    break;
                op[j] = 'Y';
                if(b[j] == 'N')
                    break;
            }
            for(int j=i;j>=0;j--)
            {
                if(a[j] == 'N' && j!=i)
                    break;
                op[j] = 'Y';
                if(b[j] == 'N')
                    break;
            }
            cout << op << endl;
            op.clear();
        }
    }
    return 0;
}
