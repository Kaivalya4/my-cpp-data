/**
Celebrity Problem - gfg.practice
->O(n^2) time and O(n) space solution (accepted) - find all those who are known by all .
 From those find all those who know no one.
 class Solution
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n)
    {
        // code here
        vector<int> vec;
        for(int j=0;j<n;j++)
        {
            int counts = 0;
            for(int i=0;i<n;i++)
            {
                counts+= M[i][j];
            }
            if(counts == n-1)
            vec.push_back(j);
        }
        for(int i:vec)
        {
            int counts = 0;
            for(int j=0;j<n;j++)
                counts += M[i][j];
            if(counts == 0)
                return i;
        }
        return -1;
    }
};

-> Stack : O(n) time and O(n) space .
    -> push every id on stack . now run while loop till number of element in stack is greater than 2
    -> Pop A and B from stack : if A knows B => A is not celebrity . pop A . push B
                              : if A dont know B => then B is not clebrity . pop B. push A.
    -> Finally we will be left with one point(which may be our celebrity if he is known by all).
    If we see this method then it seems like a recursive approach to eliminate all those who dont
    satisfy criteria for celebrity because only those all elements are poped out which are not celebrity
    . We are not saying that if we pop A and push B then B is celebrity . We are only saying that it is
    guarantee that A is not clebrity and so pop him.

    class Solution
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n)
    {
        // code here
        stack<int> s;
        for(int i=0;i<n;i++)
            s.push(i);
        while(s.size()>1)
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if(M[a][b])
            {
                s.push(b);  ///a cant be  celebrity . But we cant claim anything forb
            }
            else{
                s.push(a);  ///a dont know b => b is not celebrity
            }
        }
        int j=s.top();
        int counts1=0 , counts2 =0;
        for(int i=0;i<n;i++)
        {
            counts1 += M[i][j];
            counts2 += M[j][i];
        }
        if(counts1 == n-1 && counts2 == 0)  /// if the count of persons who knows the celebrity is
                                ///n-1 and the count of people whom the celebrity knows is
                                ///0 then return the id of celebrity else return -1.
            return j;
        return -1;
    }
};

->Two Pointer: O(n) time and O(1) space
 Core idea :Pop A and B from stack : if A knows B => A is not celebrity . pop A . push B
                              : if A dont know B => then B is not clebrity . pop B. push A.
    So two pointer : one at start and one at end.
    if i knows j => i cant be celebrity . i++.
    else fi i dont know j => j cant be celebrity . j++

    Concept is same . We remove all those who cant be clebrity . Finally we left with one point. We
    have to sure that this is celebirty. So last step of counts1 and counts2 will be same like stack.

    class Solution
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n)
    {
        // code here
        int i=0 , j=n-1;
        while(i !=j)
        {
            if(M[i][j])
                i++;
            else
                j--;
        }
        int celeb = i;
        int counts1=0 , counts2=0;
        for(int all = 0 ; all < n;all++)
        {
            counts1 += M[all][celeb];
            counts2 += M[celeb][all];
        }
        if(counts1 == n-1 && counts2 == 0)
            return celeb;
        return-1;
    }
};
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You";
    return 0;
}
