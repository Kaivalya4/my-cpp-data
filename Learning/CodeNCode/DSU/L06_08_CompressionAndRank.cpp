///We will optimize our first code using Path compression and Union by Rank
/**
L07- Owl Fight of Hackereath is no more available

Given an array . Perform two operations -
1. find(x) - find parent of x
2. union(a,b) - do union of a,b.
*/

#include<iostream>

using namespace std;

int par[100];
int R[100];
void makePar(int n)
{
    for(int i=1;i<=n;i++)
        R[i] = 1, par[i] = i;    ///depending on problem we create par accordingly . like - par[i] = i , par[i] = -1, par[i] = something etc.

}

///find()

/**
Iterative code-
int finds(int a)
{
    vector<int> vec;
    while(par[a]>0)
    {
        vec.push_back(a);
        a = par[a];
    }
    for(int i=0;i<vec.size();i++)
        par[vec[i]] = a;
    return a;
}
*/
//recursive
int finds(int a)
{
    if(par[a] == a)
        return a;
    return par[a] = finds(par[a]);                  ///Path Compression
}

///Union()
void unions(int a , int b)
{
    a = finds(a);   //find parent of a
    b = finds(b);   //find parent of b

    if(a == b){
        cout << "They are in same set" << endl;
        return ;
    }
    else
    {
        cout << "Both set are merged" << endl;
                                                    ///Union by rank
        if(R[a] > R[b])
        {
            par[b] = a;
            R[a] += R[b];
        }
        else{
            par[a] = b;
            R[b] += R[a];
        }
        return;
    }
}
int main()
{
    int n;
    cin >> n;
    makePar(n);  ///lets first create a parent array
    cout << "Enter number of queries : " << endl;
    int q;
    cin >> q;
    while(q--)
    {
        int inp;
        cin >> inp;
        if(inp == 1)
        {
            int a;
            cin >> a;
            cout << "From finds() parent is : " << finds(a) << endl;
        }
        if(inp == 2)
        {
            int a,b;
            cin >> a >> b;
            unions(a,b);
        }
    }
    return 0;
}
