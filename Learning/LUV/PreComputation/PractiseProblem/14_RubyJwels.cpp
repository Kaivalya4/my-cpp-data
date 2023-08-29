#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string a;
        cin >> a;
        unordered_map<char ,int> umap;
        for(int i=0 ;i<a.length() ;i++)
        {
            umap[a[i]] ++;
        }
        int counts =0;
        while(1)
        {
            if(umap['r'] && umap['u'] && umap['b'] && umap['y'])
            {
               umap['r'] --;
               umap['u'] --;
               umap['b'] --;
               umap['y'] --;
               counts++;
            }
            else
                break;
        }
        cout << counts << endl;
    }
    return 0;
}
