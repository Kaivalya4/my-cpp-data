#include<iostream>
#include<string.h>

using namespace std;

int t[11+1][12+1][12+1];

//n , m , counts changed hence 3d dp
int lcss(string x, string y , int n , int m , int counts)
{
    if(n==0 || m==0)
        return counts;
    if(t[n][m][counts] != -1)
       return  t[n][m][counts] ;
    if(x[n-1] == y[m-1])
        t[n][m][counts] = lcss(x,y,n-1,m-1,counts+1);
    t[n][m][counts] = max(t[n][m][counts] , max(lcss(x,y,n-1,m,0) , lcss(x,y,n,m-1,0)));
    return t[n][m][counts];
}

int main()
{
    char X[] = "abcdexyzefg";
    char Y[] = "xyzabcdefghi";

    int n = strlen(X);
    int m = strlen(Y);

    int counts = 0;

    memset(t , -1 , sizeof(t[0][0][0]) * 12*13*13); //(obj , value to put , total space required to be filled)

    cout << "Length of Longest Common Substring is "
         << lcss(X, Y, n, m , counts);
    return 0;
}
