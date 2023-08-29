#include<bits/stdc++.h>

using namespace std;

vector<int> tocheck;
vector<int> dist;
//bool found = false;
//int ans = INT_MAX;

void bfs(unordered_map<char,vector<char>>umap ,char a, char b ){

    /*int adash = a;
    tocheck[adash-65] = 1;
    vector<char> vec = umap[adash-65];
    for(auto i:vec)
    {
        int idash = i;
        if(i == b)
        {
            found = true;
            ans = min(ctr+1 , ans);
        }
        else if(tocheck[idash-65] == 0)
            dfs(umap , i , b , ctr+1);
    }*/
    queue<char> q;
    q.push(a);
    tocheck[a-65] = 1;
    dist[a-65] = 0;
    while(!q.empty())
    {
        char curr = q.front();
        q.pop();
        for(auto i:umap[curr])
        {
            if(tocheck[i-65] == 0)
            {
                dist[i-65] = dist[curr-65] +1;
                tocheck[i-65] = 1;
                q.push(i);
            }
        }

    }
}

int main()
{
    freopen("consistency_chapter_2_input.txt","r",stdin);
    freopen("outputA_2_2.txt","w",stdout);
    int  t;
    cin >> t;
    int itr = 0;
    while(t--){
        string s;
        cin >> s;
        int k;
        cin >> k;
        vector<char> possible;
        //vector<char> umap[26];
        unordered_map<char,vector<char>> umap;
        for(int i=0;i<k;i++){
            char a,b;
            cin >> a >> b;
            possible.push_back(b);
            //umap[a-65].push_back(b);
            umap[a].push_back(b);
        }
        bool check = true;
        for(int i=0;i<s.length()-1;i++){
            if(s[i] != s[i+1])
            {
                check = false;
                break;
            }
        }
        if(check)
        {
            cout << "Case #" << ++itr << ": " << 0 << endl;
            continue;
        }
        int ansf = INT_MAX;
        for(auto x:possible){  //char x='A' ; x<='Z' ; x++
            int step = 0;
            bool notfound = false;
            for(int i=0;i<s.length();i++){
                //ans = INT_MAX;
                //found = false;
                if(s[i] ==x )
                    continue;
                tocheck.clear();
                for(int i=0;i<26;i++)
                    tocheck.push_back(0);
                dist.clear();
                for(int i=0;i<26;i++)
                    dist.push_back(0);
                bfs(umap,s[i],x);
                /*if(found)
                    step += ans;
                else{
                    notfound = true;
                    break;
                }*/
                if(dist[x-65])
                    step += dist[x-65];
                else{
                    notfound = true;
                    break;
                }
            }
            if(!notfound)
                ansf = min(ansf, step);
        }
        if(ansf == INT_MAX)
            cout << "Case #" << ++itr << ": " << -1 << endl;
        else
            cout << "Case #" << ++itr << ": " << ansf << endl;
    }
    return 0;
}
