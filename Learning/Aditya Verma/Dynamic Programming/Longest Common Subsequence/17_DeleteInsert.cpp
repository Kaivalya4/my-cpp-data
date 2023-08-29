///Also try gfg.practice - minimum number of deletions and insertion
#include<iostream>
#include<string>

using namespace std;

void printMinDelAndInsert(string str1 , string str2)
{
    int n = str1.length();
    int m = str2.length();
    int t[n+1][m+1];
    for(int i=0 ;i<n+1 ;i++)
    {
        for(int j=0 ;j<m+1 ;j++)
        {
            if(i==0 || j==0)
                t[i][j] =0;
        }
    }
    for(int i=1 ; i<n+1 ;i++)
    {
        for(int j=1 ; j<m+1 ;j++)
        {
            if(str1[i-1] == str2[j-1])
                t[i][j] = 1+t[i-1][j-1];
            else
                t[i][j] = max(t[i][j-1] , t[i-1][j]);
        }
    }
    int val = t[n][m];
    cout << "number of insertions required : " << m  - val << endl;
    cout << "number of deletions required : " << n-val << endl;
}

int main()
{
    string str1 = "heap";
    string str2 = "pea";

      // Function Call
    printMinDelAndInsert(str1, str2);
    return 0;
}
