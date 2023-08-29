///N meetings in one room - practise.gfg
/**
struct tuple{
        int start ;
        int ends ;
        int num;
    };

    static bool compare(tuple a , tuple b)
    {
        if(a.ends < b.ends) return true;
        else if(a.ends > b.ends) return false;
        else if(a.num < b.num) return true;   //if two have same end time then first one should come first
        return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        struct tuple ar[n];
        for(int i=0;i<n;i++)
        {
            ar[i].start = start[i];
            ar[i].ends = end[i];
            ar[i].num = i+1;
        }
        sort(ar,ar+n,compare);
        vector<int> ans;
        ans.push_back(ar[0].num);
        int last = ar[0].ends;
        for(int i=1;i<n;i++)
        {
            if(ar[i].start>last)
            {
                ans.push_back(ar[i].num);
                last = ar[i].ends;
            }

        }
        return ans.size();
    }
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "thank you";
    return 0;
}
