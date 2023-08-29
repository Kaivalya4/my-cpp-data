// Minimum Spanning tree - Hackerearth
#include <bits/stdc++.h>
#define  Boost ios_base :: sync_with_stdio (0) ; cin.tie(0) ; cout.tie(0) ;
#define  int  long long
using namespace std ;

struct ed {
    int u = 0 , v = 0 , w = 0 ;
} ;

ed el[100001] ;
int parent[10001] ;

bool cmp ( ed a , ed b ) {
    return a.w < b.w ;
}

int find ( int a ) {
    if ( parent[a] == -1 )
        return a ;
    return parent[a] = find(parent[a]) ;
}

void Union ( int a , int b ) {
    parent[b] = a ;
}

int32_t main () {
    int n = 0 , m = 0 ;
    cin >> n >> m ;

    for ( int i = 1 ; i <= n ; i++ ) {
        parent[i] = -1 ;
    }

    for ( int i = 0 ; i < m ; i++ ) {
        cin >> el[i].u >> el[i].v >> el[i].w ;
    }

    sort ( el , el+m , cmp ) ;

    int mip = 0 ;
    for ( int i = 0 ; i < m ; i++ ) {
        int a = find(el[i].u) ;
        int b = find(el[i].v) ;
        if ( a != b ) {
            Union(a,b) ;
            mip += el[i].w ;
        }
    }

    cout << mip << endl ;

    return 0 ;
}
