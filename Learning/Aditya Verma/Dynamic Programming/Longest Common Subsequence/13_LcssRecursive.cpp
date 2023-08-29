//lcs - longest common subsequence
//lcss - longest common substring
#include<iostream>
#include<string.h>

using namespace std;

int lcss(string x ,string y , int n ,int m , int counts)
{
    if(n==0 || m==0)
        return counts;
    //if common character found then we increment counts
    if(x[n-1] == y[m-1])
        counts = lcss(x,y,n-1,m-1 , counts+1);

    //now counts is storing len of substring till now(if any) . So we need to find max from
    //two lcss function just like lcs and see that we are making counts = 0 in that call
    //this would not be possible with simple if else if we tried to change code of tabulation of aditya verma
    //to recursion
    counts = max (counts , max(lcss(x,y,n-1,m,0), lcss(x,y,n,m-1,0)));
    return counts;
}

int main()
{
    char X[] = "abcdxyzefg";
    char Y[] = "xyzabcdefg";

    int n = strlen(X);
    int m = strlen(Y);

    int counts = 0;

    cout << "Length of Longest Common Substring is "
         << lcss(X, Y, n, m , counts);
    return 0;
}
