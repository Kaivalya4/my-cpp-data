#include<bits/stdc++.h>

using namespace std;

int main()
{

    freopen("consistency_chapter_1_input.txt","r",stdin);
    freopen("output3.txt","w",stdout);
    int t;
    cin >> t;
    unordered_map<char,bool>umapc;
    unordered_map<char,bool>umapv;
    for(char c='A' ;c<='Z' ;c++)
    {
        if(c == 'A' ||c =='E' || c == 'I' || c == 'O' || c == 'U')
            umapv[c] = true;
        else
            umapc[c] = true;
    }
    int itr = 0;
    while(t--){
        string s;
        cin >> s;
        int ans = INT_MAX;
        for(char a='A';a<='Z';a++){
                int step = 0;
            for(int i=0;i<s.length();i++){
                if(s[i] == a)
                    continue;
                else if(umapc[s[i]]){
                    if(umapc[a])
                        step +=2;
                    else
                        step +=1;
                }
                else{
                    if(umapv[a])
                        step+=2;
                    else
                        step +=1;
                }
            }
            ans = min(step,ans);
        }
        cout << "Case #" << ++itr << ": " << ans;
        cout << endl;
    }
    return 0;
}

