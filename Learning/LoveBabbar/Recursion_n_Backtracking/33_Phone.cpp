#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>


/*
Time Complexity: O(4^n), where n is a number of digits in the input number.
Each digit of a number has 3 or 4 alphabets, so it can be said that each digit has 4 alphabets as options.
If there are n digits then there are 4 options for the first digit and
for each alphabet of the first digit there are 4 options in the second digit, i.e
for every recursion 4 more recursions are called (if it does not match the base case).
So the time complexity is O(4^n).
*/
using namespace std;

void createmap(unordered_map<int , string>& umap)
{
    char ch = 'a';
    for(int i=2 ; i<=9 ; i++)
    {
        umap[i].push_back(ch);
        ch++;
        umap[i].push_back(ch);
        ch++;
        umap[i].push_back(ch);
        ch++;
    }
}

void solve(unordered_map<int ,string> umap , vector<int> digit , int n , string ans)
{
    if(n == 0)
    {
        cout << ans << endl;
        return ;
    }
    string str = umap[digit[n-1]];
    for(int i=0 ; i<str.length() ;i++)
    {
        ans.push_back(str[i]);
        solve(umap , digit , n-1 , ans);
        ans.pop_back();
    }
}
int main()
{
    unordered_map<int ,string> umap;
    createmap(umap);

    int num;
    cin >> num;
    vector<int> digit;
    while(num!=0)
    {
        digit.push_back(num %10);
        num = num /10;
    }
    string ans;
    solve(umap , digit , digit.size() , ans);
    return 0;
}
