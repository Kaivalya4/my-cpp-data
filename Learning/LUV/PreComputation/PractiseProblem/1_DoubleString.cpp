//key concept - if any character is present twice then we can convert any string to double string by deleting
//rest characters.

#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
        unordered_map<char , int> umap;
        for(int i=0 ;i<str.length() ; i++)
            umap[str[i]]++;
        string ans = "No";
        for(auto i:umap){
            if(i.second >= 2)
                ans = "Yes";
        }
            cout <<ans<< endl;
    }
}
