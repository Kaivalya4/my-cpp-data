/**
L01 - 3 are theory

Given an array . Perform two operations -
1. find(x) - find parent of x
2. union(a,b) - do union of a,b.
*/

#include<iostream>

using namespace std;

int par[100];
void makePar(int n)
{
    for(int i=1;i<=n;i++)
        par[i] = i;    ///depending on problem we create par accordingly . like - par[i] = i , par[i] = -1, par[i] = something etc.

}

///find()
//Recursive -
int finds1(int a)
{
    if(par[a] == a)
        return a;
    return finds1(par[a]);
}
//Iterative -
int finds2(int a)
{
    while(1)
    {
        if(par[a] == a)
            return a;

        a = par[a];
    }
}

///Union()
void unions(int a , int b)
{
    a = finds1(a);   //find parent of a
    b = finds2(b);   //find parent of b

    if(a == b){
        cout << "They are in same set" << endl;
        return ;
    }
    else
    {
        cout << "Both set are merged" << endl;
        par[a] = b;
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
            cout << "From finds1() parent is : " << finds1(a) << endl;
            cout << "From finds2() parent is : " << finds2(a) << endl;
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
