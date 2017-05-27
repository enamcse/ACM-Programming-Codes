/***********Template Starts Here***********/
#pragma comment (linker,"/STACK:16777216")
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

#define pb push_back
#define nl puts ("")
#define sp printf ( " " )
#define phl printf ( "hello\n" )
#define all(c) (c).begin(),(c).end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define sz(a) int((a).size())

using namespace std;

typedef long long vlong;
typedef unsigned long long uvlong;
typedef vector < int > vi;
typedef pair < int, int > ii;
typedef vector < ii > vii;


const vlong inf = 2147383647;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;
const vlong maxint = 2147483647;
const vlong minint = -2147483648;

/***********Template Ends Here***********/
vlong mod = 1000000;

vlong getRandNum ( vlong m ) {
    vlong res = 1;
    int i;
    for ( i = 0; i < 10; i++ ) {
        res = res * rand();
        res %= m;
    }
    if ( res < 0 ) res *= -1;
    return res;
}

int main () {
    mod = mod * mod * mod;
    //freopen ( "input.txt", "r", stdin );
    //freopen ( "input.txt", "w", stdout );

    int kase = 1000 - 10;
    printf ( "%d\n", kase );

    srand ( 6*14*2014 );

    while ( kase-- ) {

        vlong a, b, c;

        a = getRandNum ( mod ) + 1;
        b = getRandNum ( mod ) + 1;
        c = getRandNum ( mod ) + 1;

        printf ( "%lld %lld %lld\n", a, b, c )  ;

    }

    return 0;
}
