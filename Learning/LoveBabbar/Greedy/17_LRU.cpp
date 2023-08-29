///Least Recently used Algorithm.
/**
gfg.practice - O(N*C) time and O(N) space

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        vector<int> memory;
        unordered_map<int,bool> umap;
        int ans = 0;
        for(int i=0;i<N;i++)
        {
            if(umap[pages[i]] == 1)
            {
                for(int itr=0;itr<C;itr++)
                {
                    if(memory[itr] == pages[i])
                    {
                        memory.erase(memory.begin()+itr);
                        memory.push_back(pages[i]);
                        break;
                    }
                }
            }
            else{
                if(memory.size() == C){
                    ans++;
                    umap[memory[0]] = false;
                    memory.erase(memory.begin()+0);
                    memory.push_back(pages[i]);
                    umap[pages[i]] = true;
                }
                else{
                    ans++;
                    memory.push_back(pages[i]);
                    umap[pages[i]] = true;
                }
            }
        }
        return ans;
    }
};
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You" << endl;
    return 0;
}
