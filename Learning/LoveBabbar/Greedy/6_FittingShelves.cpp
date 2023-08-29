#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


///Recursive solution
vector<vector<int>> soln;

bool comp(vector<int> a , vector<int> b)
{
   //cout << 1 << endl;
    if(a[0] < b[0])
        return true;
    else if(a[0] == b[0])
        if(a[1] > b[1])
            return true;
    return false;
}
void utility(int w , int m , int n , int cntm , int cntn)
{
    if(w<m)
    {
        vector<int> temp;
        temp.push_back(w );
        temp.push_back(cntn);
        temp.push_back(cntm);
        soln.push_back(temp);
        return;
    }
    if(w - n >=0)
    {
        utility(w -  n , m , n , cntm , cntn+1);
        utility(w - m , m , n , cntm+1 , cntn);
    }
    else
    {
        utility(w - m , m , n , cntm+1 , cntn);
    }
}

void solve1(int w , int  m , int n )
{
    int cntm = 0 , cntn = 0;
    utility(w , m , n , cntm , cntn);
   // for(int i=0;i<soln.size() ; i++)
     //      cout << soln[i][2] << " " << soln[i][1] << " " << soln[i][0] << endl ;
    sort(soln.begin() , soln.end(),comp);;
    cout << soln[0][2] << " " << soln[0][1] << " " << soln[0][0] ;
}

///Reverse Greedy approach (my nomenclature) : O(n) time
///find maximum number of n that can be used . Now start decrementing n and check the answer for which
///we will get minimum area. If for larger number of n we get min area then it will be our answer.
void solve2(int w , int m , int n)
{
    int cntn =0 , cntm = 0 , tempw = w;
    cntn = w/n;
    int ansm = INT_MAX , ansn = 0 ;
    while(cntn>=0)
    {
        cntm = (w - n*cntn)/m;
        if(w -n*cntn - m*cntm < tempw)
        {
            tempw = w - n*cntn - m*cntm ;
            ansn = cntn;
            ansm = cntm;
        }
        cntn--;
    }
    cout << endl;
    cout << ansm << " " << ansn << " " << tempw << endl;
}

int main()
{
    int w , m , n ; /// n is larger shelves
    cin >> w >> m >> n;
    /// Recursive solution -
    solve1(w , m , n);
    solve2(w , m , n);
    return 0;
}

