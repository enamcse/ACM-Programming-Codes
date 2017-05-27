/***********Template Starts Here***********/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <functional>
#include <string>
#include <iostream>
#include <cctype>
#include <set>

#define pb push_back
#define nl puts ("")
#define sp printf ( " " )
#define phl printf ( "hello\n" )
#define ff first
#define ss second
#define popcount __builtin_popcount
#define rightmost __builtin_ctz

using namespace std;

typedef long long vlong;
typedef unsigned long long uvlong;
typedef vector < int > vi;
typedef pair < int, int > ii;
typedef pair < vlong, vlong > lili;
typedef vector < ii > vii;

template < class T > T sq( T x ) { return x * x; }

const vlong inf = 2147383647;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;
const vlong maxint = 2147483647;
const vlong minint = -2147483648;

/***********Template Ends Here***********/

vlong bigmul ( vlong a, vlong b, vlong c ) {
    if ( b == 0 ) return 0;
    if ( b & 1 ) {
        return ( a + bigmul ( a, b - 1, c ) ) % c;
    }
    else {
        return ( 2 * bigmul ( a, b / 2, c ) ) % c;
    }
}

vlong bigmod ( vlong a, vlong p, vlong m ) {
    vlong res = 1, x = a % m;

    while ( p ) {
        if ( p & 1 ) res = bigmul ( res, x, m );
        x = bigmul ( x, x, m );
        p >>= 1;
    }

    return res;
}

int main () {
    
    vlong kase, cnt = 0;
    scanf ( "%lld", &kase );

    while ( kase-- ) {

        vlong a, b, c;
        scanf ( "%lld %lld %lld", &a, &b, &c );

        vlong res = bigmod( a, b, c );

        printf ( "Case %lld: %lld\n", ++cnt, res );
    }

    return 0;
}
