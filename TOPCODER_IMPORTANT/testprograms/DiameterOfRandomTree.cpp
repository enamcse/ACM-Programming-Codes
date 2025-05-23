#include <bits/stdc++.h>

#define all(a)           a.begin(),a.end()
#define chng(a,b)       a^=b^=a^=b;
#define clr(y,z)        memset(y,z,sizeof(y))
#define cntbit(mask)     __builtin_popcount(mask)
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define fr(i,a,b)       for(i=a;i<=b;i++)
#define inf             (1e9)
#define mod             1000000007
#define ll              long long
#define oo              (1<<30)
#define pb              push_back
#define PI              3.141592653589793
#define pi              (2*acos(0))
#define pp              pop_back
#define rev(a)          reverse(all(a));
#define SIZE(s)         ((int)s.size())
#define saja(a)         sort(all(a))
#define sqr(a)          ((a)*(a))
#define SZ              50005
#define V(a)            vector<(a)>

using namespace std;


class DiameterOfRandomTree
{
public:
    vector<int>adj[55];
    int n;
    bool col[55][3];
    double dp[55][3];
    double rec(int pos, int w, int par)
    {
        if(col[pos][w]) return dp[pos][w];
        col[pos][w] =  true;
        double &ret = dp[pos][w];
        ret = 0;
        for (int i = 0; i<adj[]; )
            ;
    }

    double getExpectation(vector <int> a, vector <int> b)
    {
        n = a.size();
        for (int i = 0; i<n; i++)
        {
            adj[ a[i] ].pb(b[i]);
            adj[ b[i] ].pb(a[i]);
        }
        double ret = 0.0;
        for (int i = 0; i<=n; i++)
            if(adj[i].size()==1)
            {
                clr(col,0);
                ret+=rec(i,1,-1);
                ret+=rec(i,2,-1);
            }
    };


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit-pf 2.3.0
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
    using namespace std;
    bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, double p2)
    {
        cout << "Test " << testNum << ": [" << "{";
        for (int i = 0; int(p0.size()) > i; ++i)
        {
            if (i > 0)
            {
                cout << ",";
            }
            cout << p0[i];
        }
        cout << "}" << "," << "{";
        for (int i = 0; int(p1.size()) > i; ++i)
        {
            if (i > 0)
            {
                cout << ",";
            }
            cout << p1[i];
        }
        cout << "}";
        cout << "]" << endl;
        DiameterOfRandomTree *obj;
        double answer;
        obj = new DiameterOfRandomTree();
        clock_t startTime = clock();
        answer = obj->getExpectation(p0, p1);
        clock_t endTime = clock();
        delete obj;
        bool res;
        res = true;
        cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
        if (hasAnswer)
        {
            cout << "Desired answer:" << endl;
            cout << "\t" << p2 << endl;
        }
        cout << "Your answer:" << endl;
        cout << "\t" << answer << endl;
        if (hasAnswer)
        {
            res = answer == answer && fabs(p2 - answer) <= 1e-9 * max(1.0, fabs(p2));
        }
        if (!res)
        {
            cout << "DOESN'T MATCH!!!!" << endl;
        }
        else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2)
        {
            cout << "FAIL the timeout" << endl;
            res = false;
        }
        else if (hasAnswer)
        {
            cout << "Match :-)" << endl;
        }
        else
        {
            cout << "OK, but is it right?" << endl;
        }
        cout << "" << endl;
        return res;
    }
    int main()
    {
        bool all_right;
        bool disabled;
        bool tests_disabled;
        all_right = true;
        tests_disabled = false;

        vector <int> p0;
        vector <int> p1;
        double p2;

        // ----- test 0 -----
        disabled = false;
        p0 = {0,1,2,3};
        p1 = {1,2,3,4};
        p2 = 6.0;
        all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
        tests_disabled = tests_disabled || disabled;
        // ------------------

        // ----- test 1 -----
        disabled = false;
        p0 = {0,0,0};
        p1 = {1,2,3};
        p2 = 3.375;
        all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
        tests_disabled = tests_disabled || disabled;
        // ------------------

        // ----- test 2 -----
        disabled = false;
        p0 = {0,0,0,1,4};
        p1 = {1,2,3,4,5};
        p2 = 6.25;
        all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
        tests_disabled = tests_disabled || disabled;
        // ------------------

        // ----- test 3 -----
        disabled = false;
        p0 = {0,0,0,0,0,0,0,0};
        p1 = {1,2,3,4,5,6,7,8};
        p2 = 3.9609375;
        all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
        tests_disabled = tests_disabled || disabled;
        // ------------------

        // ----- test 4 -----
        disabled = false;
        p0 = {0,0,0,1,2,3,5,6,8};
        p1 = {1,2,3,4,5,6,7,8,9};
        p2 = 10.53125;
        all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
        tests_disabled = tests_disabled || disabled;
        // ------------------

        if (all_right)
        {
            if (tests_disabled)
            {
                cout << "You're a stud (but some test cases were disabled)!" << endl;
            }
            else
            {
                cout << "You're a stud (at least on given cases)!" << endl;
            }
        }
        else
        {
            cout << "Some of the test cases had errors." << endl;
        }
        return 0;
    }
// PROBLEM STATEMENT
// Given a tree, let d(u,v) be the distance between nodes u and v in the tree.
// In other words, d(u,v) is the length of the only simple path that connects u and v.
// The diameter of the tree is the maximum of all d(u,v).
//
// You are given vector <int>s a and b, each containing n-1 elements.
// These describe a tree with n nodes, labeled 0 through n-1.
// For each valid i, the nodes a[i] and b[i] are connected by an edge.
//
// The length of each edge is generated randomly.
// More precisely, the length of each edge is either 1 or 2 with equal probability.
// The lengths of edges are mutually independent.
//
// Return the expected value of the diameter of the given tree.
//
// DEFINITION
// Class:DiameterOfRandomTree
// Method:getExpectation
// Parameters:vector <int>, vector <int>
// Returns:double
// Method signature:double getExpectation(vector <int> a, vector <int> b)
//
//
// CONSTRAINTS
// -a will contain between 1 and 50 elements, inclusive.
// -a and b will contain the same number of elements.
// -Each element in a will be between 0 and |a|, inclusive.
// -Each element in b will be between 0 and |a|, inclusive.
// -The graph will be a tree.
//
//
// EXAMPLES
//
// 0)
// {0,1,2,3}
// {1,2,3,4}
//
// Returns: 6.0
//
// This graph is a single path: 0-1-2-3-4.
// In this case, the diameter will always be the distance between nodes 0 and 4.
// The expected length of each edge is 1.5, thus the expected distance between 0 and 4 equals 4 * 1.5 = 6.
//
// 1)
// {0,0,0}
// {1,2,3}
//
// Returns: 3.375
//
// This tree has three edges: 0-1, 0-2, and 0-3.
// There are four possible cases:
//
// With probability 1/8 all three edges have length 1. In this case, the diameter is 2.
// With probability 3/8 the edges have lengths (1,1,2). In this case, the diameter is 3.
// With probability 3/8 the edges have lengths (1,2,2). In this case, the diameter is 4.
// With probability 1/8 all three edges have length 2. In this case, the diameter is also 4.
//
// Thus, the expected diameter is (1/8)*2 + (3/8)*3 + (3/8)*4 + (1/8)*4 = 27/8 = 3.375.
//
// 2)
// {0,0,0,1,4}
// {1,2,3,4,5}
//
// Returns: 6.25
//
//
//
// 3)
// {0,0,0,0,0,0,0,0}
// {1,2,3,4,5,6,7,8}
//
// Returns: 3.9609375
//
//
//
// 4)
// {0,0,0,1,2,3,5,6,8}
// {1,2,3,4,5,6,7,8,9}
//
// Returns: 10.53125
//
//
//
// END KAWIGIEDIT TESTING
