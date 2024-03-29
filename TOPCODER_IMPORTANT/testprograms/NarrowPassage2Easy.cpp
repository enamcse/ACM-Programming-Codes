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


class NarrowPassage2Easy
{
public:
    set< vector<int> >ss;
    map<vector<int>, int>mp;
    int n, tew;
    void rec(vector<int> now,vector<int> pos,  int sw)
    {
        if(mp[pos]) return;
        mp[pos]=51;
        ss.insert(pos);

        int temp;
        for (int i = 1; i<n; i++)
        {
//            if(i==sw) continue;
            if(now[i]+now[i-1]<=tew)
            {
                vector<int> v  = now, k = pos;
                temp = v[i];
                v[i] = v[i-1];
                v[i-1] =temp;
                temp = k[i];
                k[i] = k[i-1];
                k[i-1] =temp;

                rec(v,k,i);
            }

        }
        return;
    }
    int count(vector <int> s, int m)
    {
        n = s.size();
        tew = m;
        ss.clear();

        vector<int>kk;
        for (int i = 1; i<=n; i++)
            kk.pb(i);
        ss.insert(kk);
        rec(s,kk,-1);
        return ss.size();

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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, bool hasAnswer, int p2)
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
    cout << "}" << "," << p1;
    cout << "]" << endl;
    NarrowPassage2Easy *obj;
    int answer;
    obj = new NarrowPassage2Easy();
    clock_t startTime = clock();
    answer = obj->count(p0, p1);
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
        res = answer == p2;
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
    int p1;
    int p2;

    // ----- test 0 -----
    disabled = false;
    p0 = {1,2,3};
    p1 = 3;
    p2 = 2;
    all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 1 -----
    disabled = false;
    p0 = {1,2,3};
    p1 = 1000;
    p2 = 6;
    all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 2 -----
    disabled = false;
    p0 = {1,2,3};
    p1 = 4;
    p2 = 3;
    all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 3 -----
    disabled = false;
    p0 = {1,1,1,1,1,1};
    p1 = 2;
    p2 = 720;
    all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 4 -----
    disabled = false;
    p0 = {2,4,6,1,3,5};
    p1 = 8;
    p2 = 60;
    all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 5 -----
    disabled = false;
    p0 = {1000};
    p1 = 1000;
    p2 = 1;
    all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, true, p2) ) && all_right;
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
// There is a narrow passage.
// Inside the passage there are some wolves.
// You are given a vector <int> size that contains the sizes of those wolves, from left to right.
//
//
//
// The passage is so narrow that some pairs of wolves cannot pass by each other.
// More precisely, two adjacent wolves may swap places if and only if the sum of their sizes is maxSizeSum or less.
// Assuming that no wolves leave the passage, what is the number of different permutations of wolves in the passage?
// Note that two wolves are considered different even if they have the same size.
//
//
//
// Compute and return the number of permutations of wolves that can be obtained from their initial order by swapping a pair of wolves zero or more times.
//
// DEFINITION
// Class:NarrowPassage2Easy
// Method:count
// Parameters:vector <int>, int
// Returns:int
// Method signature:int count(vector <int> size, int maxSizeSum)
//
//
// CONSTRAINTS
// -size will contain between 1 and 6 elements, inclusive.
// -Each element in size will be between 1 and 1,000, inclusive.
// -maxSizeSum will be between 1 and 1,000, inclusive.
//
//
// EXAMPLES
//
// 0)
// {1, 2, 3}
// 3
//
// Returns: 2
//
// From {1, 2, 3}, you can swap 1 and 2 to get {2, 1, 3}. But you can't get other permutations.
//
// 1)
// {1, 2, 3}
// 1000
//
// Returns: 6
//
// Here you can swap any two adjacent wolves. Thus, all 3! = 6 permutations are possible.
//
// 2)
// {1, 2, 3}
// 4
//
// Returns: 3
//
// You can get {1, 2, 3}, {2, 1, 3} and {2, 3, 1}.
//
// 3)
// {1,1,1,1,1,1}
// 2
//
// Returns: 720
//
// All of these wolves are different, even though their sizes are the same. Thus, there are 6! different permutations possible.
//
// 4)
// {2,4,6,1,3,5}
// 8
//
// Returns: 60
//
//
//
// 5)
// {1000}
// 1000
//
// Returns: 1
//
//
//
// END KAWIGIEDIT TESTING
